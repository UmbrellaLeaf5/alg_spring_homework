#include <vector>

/**
 * @brief Сливает две отсортированные части вектора в один
 * @tparam T: тип элементов вектора
 * @param data: вектор, содержащий данные для слияния
 * @param left: индекс начала первой отсортированной части
 * @param mid: индекс конца первой части и начала второй части
 * @param right: индекс конца второй отсортированной части
 */
template <typename T>
static void Merge(std::vector<T>& data, std::size_t left, std::size_t mid,
                  std::size_t right) {
  std::size_t index_1 = 0;  /// @brief индекс для первой части
  std::size_t index_2 = 0;  /// @brief индекс для второй части

  /// @brief временный вектор для слияния
  std::vector<T> res(right - left);

  // сливаем две части, пока не достигнем конца какой-либо части
  while (left + index_1 < mid && mid + index_2 < right) {
    if (data[left + index_1] < data[mid + index_2]) {
      // берем элемент из первой части
      res[index_1 + index_2] = data[left + index_1];
      index_1++;

    } else {
      // берем элемент из второй части
      res[index_1 + index_2] = data[mid + index_2];
      index_2++;
    }
  }

  // копируем оставшиеся элементы из первой части, если она не закончилась
  while (left + index_1 < mid) {
    res[index_1 + index_2] = data[left + index_1];
    index_1++;
  }

  // копируем оставшиеся элементы из второй части, если она не закончилась
  while (mid + index_2 < right) {
    res[index_1 + index_2] = data[mid + index_2];
    index_2++;
  }

  // копируем результат слияния обратно в исходный вектор
  for (std::size_t i = 0; i < index_1 + index_2; i++) data[left + i] = res[i];
}

// MARK: MergeSort

/**
 * @brief Сортировка слиянием — алгоритм сортировки, использующий O(n)
 * дополнительной памяти и работающий за O(nlog(n)) времени
 * @tparam T: тип элементов вектора
 * @param data: сортируемый вектор
 */
template <typename T>
void MergeSort(std::vector<T>& data) {
  if (data.empty()) return;

  auto n = data.size();

  for (std::size_t i = 1; i < n; i *= 2)
    for (std::size_t j = 0; j < n - i; j += 2 * i)
      Merge(data, j, j + i, std::min(j + 2 * i, n));
}
