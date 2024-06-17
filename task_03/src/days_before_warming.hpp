#pragma once

#include "temperature.hpp"

// std libs:
#include <stack>

/**
 * @brief функция, которая считает дни до потепления глупым способом
 * (вложенным перебором)
 * @param temperatures: вектор температур в исследуемом кол-ве дней
 * @return std::vector<size_t>: вектор дней до потепления для каждого дня
 */
inline std::vector<size_t> DaysBeforeWarmingSillyLooping(
    const std::vector<Temperature>& temperatures) {
  // @brief кол-во исследуемых дней
  auto days_amount = temperatures.size();

  // @brief вектор дней до потепления для каждого дня
  auto res = std::vector<size_t>(days_amount);

  for (size_t i = 0; i < days_amount; i++) {
    res[i] = 0;
    for (size_t j = i; j < days_amount; j++) {
      // если следующий день теплее предыдущего, мы нашли нужно кол-во
      if (temperatures[i] < temperatures[j]) break;

      // иначе прибавляем и идём смотреть дальше
      res[i]++;
    }

    // если кол-во найденных дней совпадает с кол-вом дней до последнего, то мы
    // вышли из цикла с j, значит, более тёплых дней уже не будет
    if (res[i] == days_amount - i) res[i] = 0;
  }

  return res;
}

/**
 * @brief функция, которая считает дни до потепления более умным способом
 * (вложенным перебором, но только для опред. элементов)
 * @param temperatures: вектор температур в исследуемом кол-ве дней
 * @return std::vector<size_t>: вектор дней до потепления для каждого дня
 */
inline std::vector<size_t> DaysBeforeWarmingSmarterLooping(
    const std::vector<Temperature>& temperatures) {
  // @brief кол-во исследуемых дней
  auto days_amount = temperatures.size();

  // @brief вектор дней до потепления для каждого дня
  auto res = std::vector<size_t>(days_amount);

  for (size_t i = 0; i < days_amount; i++) {
    res[i] = 0;

    // если в предыдущем дне результат больше 1, не имеет смысла заново искать
    // день, после которого будет потепление, просто используем на один меньше
    // (+ (i == 0) позволяет не писать доп. if)
    if (res[i + (i == 0) - 1] > 1) {
      res[i] = res[i - 1] - 1;

    } else {  // иначе по-честному ищем день, после которого будет потепление
      for (size_t j = i; j < days_amount; j++) {
        // если следующий день теплее предыдущего, мы нашли нужно кол-во
        if (temperatures[i] < temperatures[j]) break;

        // иначе прибавляем и идём смотреть дальше
        res[i]++;
      }
    }

    // если кол-во найденных дней совпадает с кол-вом дней до последнего, то мы
    // вышли из цикла с j, значит, более тёплых дней уже не будет
    if (res[i] == days_amount - i) res[i] = 0;
  }

  return res;
}

/**
 * @brief функция, которая считает дни до потепления умным способом
 * (перебором с помощью стека мы можем быстрее найти день потепления)
 * (и за меньшее кол-во итераций считать промежуточный результат)
 * @param temperatures: вектор температур в исследуемом кол-ве дней
 * @return std::vector<size_t>: вектор дней до потепления для каждого дня
 */
std::vector<size_t> DaysBeforeWarmingStackLooping(
    const std::vector<Temperature>& temperatures) {
  // @brief кол-во исследуемых дней
  auto days_amount = temperatures.size();

  // @brief вектор дней до потепления для каждого дня
  auto res = std::vector<size_t>(days_amount);

  // @brief стек индексов непосчитанных дней
  std::stack<size_t> uncounted_days;
  for (size_t i = 0; i < days_amount; i++) {
    // (while по уже пройденным дням, так что мы не занулим их здесь)
    res[i] = 0;

    // @brief последний непосчитанный день
    auto j = 0;
    // запоминаем последний от предыдущего прохождения while
    if (!uncounted_days.empty()) j = uncounted_days.top();

    // пока стек непосчитанных дней пуст, заполняем их
    while (!uncounted_days.empty()) {
      // если следующий день не холоднее предыдущего, то не перезаписываем
      if (temperatures[i] <= temperatures[j]) break;

      // иначе заполняем непосчитанные дни с конца
      res[j] = i - j;
      uncounted_days.pop();

      // каждый раз обновляем j
      if (!uncounted_days.empty()) j = uncounted_days.top();
    }

    // по умолчанию всегда добавляем текущий элемент в непосчитанные
    uncounted_days.push(i);
  }

  return res;
}
