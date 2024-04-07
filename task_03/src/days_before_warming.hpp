#pragma once

#include "temperatures.hpp"

// std libs:
#include <iostream>

// std usings:
using std::cout, std::cin, std::endl;

/**
 * @brief функция, которая считает дни до потепления глупым способом
 * (вложенным перебором)
 * @param temperatures: вектор температур в исследуемом кол-ве дней
 * @return std::vector<size_t>: вектор дней до потепления для каждого дня
 */
inline std::vector<size_t> DaysUntilWarmingSillyLooping(
    const std::vector<Temperature>& temperatures) {
  // @brief кол-во исследуемых дней
  auto amount = temperatures.size();

  // @brief вектор дней до потепления для каждого дня
  auto res = std::vector<size_t>(amount);

  for (size_t i = 0; i < temperatures.size(); i++) {
    res[i] = 0;
    for (size_t j = i; j < temperatures.size(); j++) {
      // если следующий день теплее предыдущего, мы нашли нужно кол-во
      if (temperatures[i] < temperatures[j]) break;

      // иначе прибавляем и идём смотреть дальше
      res[i]++;
    }

    // если кол-во найденных дней совпадает с кол-вом дней до последнего, то мы
    // вышли из цикла с j, значит, более тёплых дней уже не будет
    if (res[i] == amount - i) res[i] = 0;
  }
  return res;
}

/**
 * @brief функция, которая считает дни до потепления более умным способом
 * (вложенным перебором, но только для опред. элементов)
 * @param temperatures: вектор температур в исследуемом кол-ве дней
 * @return std::vector<size_t>: вектор дней до потепления для каждого дня
 */
inline std::vector<size_t> DaysUntilWarmingSmarterLooping(
    const std::vector<Temperature>& temperatures) {
  // @brief кол-во исследуемых дней
  auto amount = temperatures.size();

  // @brief вектор дней до потепления для каждого дня
  auto res = std::vector<size_t>(amount);

  for (size_t i = 0; i < temperatures.size(); i++) {
    res[i] = 0;

    // если в предыдущем дне результат больше 1, не имеет смысла заново искать
    // день, после которого будет потепление, просто используем на один меньше
    // (+ (i == 0) позволяет не писать доп. if)
    if (res[i + (i == 0) - 1] > 1) {
      res[i] = res[i - 1] - 1;

    } else {  // иначе по-честному ищем день, после которого будет потепление
      for (size_t j = i; j < temperatures.size(); j++) {
        // если следующий день теплее предыдущего, мы нашли нужно кол-во
        if (temperatures[i] < temperatures[j]) break;

        // иначе прибавляем и идём смотреть дальше
        res[i]++;
      }
    }

    // если кол-во найденных дней совпадает с кол-вом дней до последнего, то мы
    // вышли из цикла с j, значит, более тёплых дней уже не будет
    if (res[i] == amount - i) res[i] = 0;
  }
  return res;
}
