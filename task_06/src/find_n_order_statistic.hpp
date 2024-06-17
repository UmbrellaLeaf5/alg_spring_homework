#include <algorithm>
#include <stdexcept>
#include <vector>

/**
 * @brief Разбивает вектор вокруг опорного элемента.
 * @tparam T: тип элементов в векторе
 * @param data: вектор, который нужно разбить
 * @param left: левый индекс диапазона, который нужно разбить
 * @param right: правый индекс диапазона, который нужно разбить
 * @return индекс опорного элемента после разбиения
 */
template <typename T>
static size_t Partition(std::vector<T>& data, size_t left, size_t right) {
  size_t mid = (left + right) / 2;

  std::swap(data[mid], data[left + 1]);

  if (data[left] > data[right]) std::swap(data[left], data[right]);
  if (data[left + 1] > data[right]) std::swap(data[left + 1], data[right]);
  if (data[left] > data[left + 1]) std::swap(data[left], data[left + 1]);

  size_t i = left + 1, j = right;
  const T cur = data[left + 1];
  while (true) {
    while (data[++i] < cur)
      ;
    while (data[--j] > cur)
      ;

    if (i > j) break;
    std::swap(data[i], data[j]);
  }

  std::swap(data[left + 1], data[j]);
  return j;
}

/**
 * @brief Находит n-ю порядковую статистику (n-й наименьший элемент) в векторе.
 * @tparam T: тип элементов в векторе
 * @param data: вектор, в котором нужно найти n-ю порядковую статистику
 * @param n: порядок статистики, которую нужно найти (индекс начиная с 1)
 * @return n-я порядковая статистика в векторе
 */
template <typename T>
T FindNOrderStatistic(std::vector<T> data, size_t n) {
  if (data.empty()) throw std::runtime_error("Vector is empty.");

  if (n >= data.size()) throw std::runtime_error("Wrong N value.");

  for (size_t left = 0, right = data.size(); /* nothing */;) {
    if (right <= left + 1) {
      if (right == left + 1 && data[right] < data[left])
        std::swap(data[left], data[right]);

      return data[n];
    }

    size_t pivot = Partition(data, left, right);

    if (pivot == n)
      return data[n];

    else if (pivot > n)
      right = pivot - 1;

    else
      left = pivot + 1;
  }
}
