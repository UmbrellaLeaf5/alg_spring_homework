#pragma once

// std libs:
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

// std usings:
using std::is_sorted;

// (написал шаблонизированные функции, так как они крутые)
// (а так же потому, что не знаю, какой тип нужно использовать под целые числа)

// MEANS: функция, находящая в отсорт. векторе 2 числа, в сумме дающие число
// (если такие числа найти не удаётся, возбуждает ошибку)
// (также возбуждает ошибку, если на вход подан неотсорт. вектор)
// ARGS: [const vector<Type>&]: отсорт. вектор элементов произвольного типа
// ARGS: [const Type&]: число, которое нужно представить суммой
// RETURNS: [pair<Type, Type>]: пара чисел, дающих в сумме число
template <typename Type>
inline std::pair<Type, Type> TwoElemsGivingSum(const std::vector<Type>& vec,
                                               const Type& sum) {
  if (vec.empty()) throw std::invalid_argument("Empty array.");
  if (!is_sorted(vec.begin(), vec.end()))
    throw std::invalid_argument("Array is not sorted.");

  // MEANS: индекс, указывающий с начала вектора
  size_t first = 0;
  // MEANS: индекс, указывающий с конца вектора
  size_t last = vec.size() - 1;

  while (first != last) {
    if (vec[first] + vec[last] == sum)
      return {vec[first], vec[last]};
    else if (vec[first] + vec[last] < sum)
      first++;
    else if (vec[first] + vec[last] > sum)
      last--;
  }

  // если индексы сошлись (first == last), таких элементов в векторе нет
  throw std::logic_error("There are no two elements giving such sum.");
}

// (и да, я не хочу париться с проверкой на то,)
// (определено ли сравнение для этого типа :)
