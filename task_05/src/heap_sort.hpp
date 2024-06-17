#include <vector>

/**
 * @brief Возвращает элемент, который находится выше
 * @param index: индекс элемента, выше которого нужное значение
 * @return T: элемент, который находится выше
 */
static std::size_t ParentOf(std::size_t index) { return (index - 1) / 2; }

/**
 * @brief Возвращает элемент, который находится левее
 * @param index: индекс элемента, левее которого нужное значение
 * @return T: элемент, который находится левее
 */
static std::size_t LeftChildOf(std::size_t index) { return (2 * index + 1); }

/**
 * @brief Возвращает элемент, который находится правее
 * @param index: индекс элемента, правее которого нужное значение
 * @return T: элемент, который находится правее
 */
static std::size_t RightChildOf(std::size_t index) { return (2 * index + 2); }

/**
 * @brief Приводит кучу в валидное состояние после добавления
 * @tparam T: тип элементов в куче
 * @param data: вектор, представляющий собой кучу
 */
template <typename T>
static void SiftUpHeap(std::vector<T>& data) {
  // идем с конца по родителям
  std::size_t index = data.size() - 1;

  // пока следующий родитель больше, меняем местами
  while (index > 0 && data[ParentOf(index)] < data[index]) {
    std::swap(data[index], data[ParentOf(index)]);
    index = ParentOf(index);
  }
}

/**
 * @brief Добавляет элемент в кучу
 * @tparam T: тип элементов в куче
 * @param data: вектор, представляющий собой кучу
 * @param elem: значение элемента
 */
template <typename T>
static void AddToHeap(std::vector<T>& data, T elem) {
  data.push_back(elem);
  SiftUpHeap(data);
}

/**
 * @brief Создаёт кучу по вектору
 * @tparam T: тип элементов в куче
 * @param data: изначальный вектор
 * @return std::vector<T>: созданная куча в виде вектора
 */
template <typename T>
static std::vector<T> GetHeap(const std::vector<T>& data) {
  std::vector<T> res;
  for (const auto& elem : data) AddToHeap(res, elem);
  return res;
}

/**
 * @brief Приводит кучу в валидное состояние после удаления
 * @tparam T: тип элементов в куче
 * @param data: вектор, представляющий собой кучу
 * @param start
 * @param end
 */
template <typename T>
static void SiftDownHeap(std::vector<T>& data, std::size_t start,
                         std::size_t end) {
  while (start < end) {
    std::size_t largest = start;  // largest = корень поддерева

    // если левый потомок существует и больше текущего лучшего элемента
    if (LeftChildOf(start) < end && data[LeftChildOf(start)] > data[largest]) {
      largest = LeftChildOf(start);
    }

    // если правый потомок существует и больше текущего лучшего элемента
    if (RightChildOf(start) < end &&
        data[RightChildOf(start)] > data[largest]) {
      largest = RightChildOf(start);
    }

    // если текущий элемент не больше своих потомков, завершаем итерацию
    if (largest == start) break;

    // меняем местами текущий элемент с наибольшим из потомков
    std::swap(data[start], data[largest]);

    // переходим вниз по дереву к потомку, с которым произвели обмен
    start = largest;
  }
}

// MARK: HeapSort

/**
 * @brief Сортировка кучей, пирамидальная сортировка — алгоритм сортировки,
 использующий структуру данных двоичная куча. Это неустойчивый алгоритм
 сортировки с временем работы O(nlogn), где n — количество элементов для
 сортировки, и использующий O(1) дополнительной памяти.
 * @tparam T: тип элементов вектора
 * @param data: сортируемый вектор
 */
template <typename T>
void HeapSort(std::vector<T>& data) {
  if (data.empty()) return;

  data = GetHeap(data);
  auto n = data.size();
  auto index = data.size();

  for (std::size_t i = 0; i < n - 1; i++) {
    std::swap(data[0], data[n - 1 - i]);
    index--;
    SiftDownHeap(data, 0, index);
  }
}