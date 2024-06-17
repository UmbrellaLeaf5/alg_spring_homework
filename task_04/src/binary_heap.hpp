#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

/**
 * @brief реализация двоичной min-heap на std::vector
 * @tparam T: тип значений двоичной кучи
 */
template <typename T>
class BinaryMinHeap {
 public:
  BinaryMinHeap() = default;
  BinaryMinHeap(const std::vector<T>& data) {
    for (const auto& elem : data) Add(elem);
  }

  BinaryMinHeap(const std::initializer_list<T>& data) {
    for (const auto& elem : data) Add(elem);
  }

  /**
   * @brief Доступ к копиям элементов кучи по индексу
   * @param index
   * @return T: элемент по индексу
   * @throw std::out_of_range: если индекс больше размера кучи
   */
  T operator[](size_t index) const {
    if (index > Size()) throw std::out_of_range("invalid index");

    return data_[index];
  }

  /**
   * @brief Доступ к данным кучи (const &)
   * @return const std::vector<T>&: вектор всех элементов
   */
  const std::vector<T>& Data() const { return data_; }

  /**
   * @brief Доступ к данным кучи (const &)
   * @return const std::vector<T>&: вектор всех элементов
   */
  explicit operator const std::vector<T>&() const { return Data(); }

  /**
   * @brief Добавляет элемент в кучу
   * @param elem: значение элемента
   */
  void Add(T elem) {
    data_.push_back(elem);
    SiftUp();
  }

  /**
   * @brief Вырезает минимум (корень) из кучи
   * @return T: значение этого минимума (корня)
   * @throw std::out_of_range: если куча пуста
   */
  T ExtractMin() {
    if (Empty()) throw std::out_of_range("empty heap");

    auto res = Data()[0];

    // меняем местами минимум с последним
    std::swap(data_[0], data_[Size() - 1]);
    data_.pop_back();
    SiftDown();

    return res;
  }

  /**
   * @brief Вырезает корень (минимум) из кучи
   * @return T: значение этого корня (минимума)
   */
  T ExtractRoot() { return ExtractMin(); }

  /**
   * @brief Возвращает значение минимума (корня)
   * @return T: значение минимума (корня)
   * @throw std::out_of_range: если куча пуста
   */
  T GetMin() const {
    if (Empty()) throw std::out_of_range("empty heap");

    return Data()[0];
  }

  /**
   * @brief Возвращает значение корня (минимума)
   * @return T: значение корня (минимума)
   */
  T GetRoot() const { return GetMin(); }

  size_t Size() const { return data_.size(); }

  bool Empty() const { return Size() == 0; }

 private:
  /**
   * @brief Возвращает элемент, который находится выше
   * @param index: индекс элемента, выше которого нужное значение
   * @return T: элемент, который находится выше
   */
  size_t ParentOf(size_t index) const { return (index - 1) / 2; }

  /**
   * @brief Возвращает элемент, который находится левее
   * @param index: индекс элемента, левее которого нужное значение
   * @return T: элемент, который находится левее
   */
  size_t LeftChildOf(size_t index) const { return (2 * index + 1); }

  /**
   * @brief Возвращает элемент, который находится правее
   * @param index: индекс элемента, правее которого нужное значение
   * @return T: элемент, который находится правее
   */
  size_t RightChildOf(size_t index) const { return (2 * index + 2); }

  /// @brief Приводит кучу в валидное состояние после добавления
  void SiftUp() {
    // идем с конца по родителям
    size_t index = Size() - 1;

    // пока следующий родитель больше, меняем местами
    while (index > 0 && data_[ParentOf(index)] > data_[index]) {
      std::swap(data_[index], data_[ParentOf(index)]);
      index = ParentOf(index);
    }
  }

  /// @brief Приводит кучу в валидное состояние после удаления
  void SiftDown(size_t index = 0) {
    while (index < Size()) {
      size_t smallest = index;  // smallest = корень поддерева

      // если левый потомок существует и меньше текущего наименьшего элемента
      if (LeftChildOf(index) < Size() &&
          data_[LeftChildOf(index)] < data_[smallest]) {
        smallest = LeftChildOf(index);
      }

      // если правый потомок существует и меньше текущего наименьшего элемента
      if (RightChildOf(index) < Size() &&
          data_[RightChildOf(index)] < data_[smallest]) {
        smallest = RightChildOf(index);
      }

      // если текущий элемент не меньше своих потомков, завершаем итерацию
      if (smallest == index) break;

      // меняем местами текущий элемент с наименьшим из потомков
      std::swap(data_[index], data_[smallest]);

      // переходим вниз по дереву к потомку, с которым произвели обмен
      index = smallest;
    }
  }

  /// @brief Данные кучи
  std::vector<T> data_;
};

/**
 * @brief реализация двоичной max-heap на std::vector
 * @tparam T: тип значений двоичной кучи
 */
template <typename T>
class BinaryMaxHeap {
 public:
  BinaryMaxHeap() = default;
  BinaryMaxHeap(const std::vector<T>& data) {
    for (const auto& elem : data) Add(elem);
  }

  BinaryMaxHeap(const std::initializer_list<T>& data) {
    for (const auto& elem : data) Add(elem);
  }

  /**
   * @brief Доступ к копиям элементов кучи по индексу
   * @param index
   * @return T: элемент по индексу
   * @throw std::out_of_range: если индекс больше размера кучи
   */
  T operator[](size_t index) const {
    if (index > Size) throw std::out_of_range("invalid index");

    return data_[index];
  }

  /**
   * @brief Доступ к данным кучи (const &)
   * @return const std::vector<T>&: вектор всех элементов
   */
  const std::vector<T>& Data() const { return data_; }

  /**
   * @brief Доступ к данным кучи (const &)
   * @return const std::vector<T>&: вектор всех элементов
   */
  explicit operator const std::vector<T>&() const { return Data(); }

  /**
   * @brief Добавляет элемент в кучу
   * @param elem: значение элемента
   */
  void Add(T elem) {
    data_.push_back(elem);
    SiftUp();
  }

  /**
   * @brief Вырезает максимум (корень) из кучи
   * @return T: значение этого максимума (корня)
   * @throw std::out_of_range: если куча пуста
   */
  T ExtractMax() {
    if (Empty()) throw std::out_of_range("empty heap");

    auto res = Data()[0];

    // меняем местами максимум с последним
    std::swap(data_[0], data_[Size() - 1]);
    data_.pop_back();
    SiftDown();

    return res;
  }

  /**
   * @brief Вырезает корень (максимум) из кучи
   * @return T: значение этого корня (максимума)
   */
  T ExtractRoot() { return ExtractMax(); }

  /**
   * @brief Возвращает значение максимума (корня)
   * @return T: значение максимума (корня)
   * @throw std::out_of_range: если куча пуста
   */
  T GetMax() const {
    if (Empty()) throw std::out_of_range("empty heap");

    return Data()[0];
  }

  /**
   * @brief Возвращает значение корня (максимума)
   * @return T: значение корня (максимума)
   */
  T GetRoot() const { return GetMax(); }

  size_t Size() const { return data_.size(); }

  bool Empty() const { return Size() == 0; }

 private:
  /**
   * @brief Возвращает элемент, который находится выше
   * @param index: индекс элемента, выше которого нужное значение
   * @return T: элемент, который находится выше
   */
  size_t ParentOf(size_t index) const { return (index - 1) / 2; }

  /**
   * @brief Возвращает элемент, который находится левее
   * @param index: индекс элемента, левее которого нужное значение
   * @return T: элемент, который находится левее
   */
  size_t LeftChildOf(size_t index) const { return (2 * index + 1); }

  /**
   * @brief Возвращает элемент, который находится правее
   * @param index: индекс элемента, правее которого нужное значение
   * @return T: элемент, который находится правее
   */
  size_t RightChildOf(size_t index) const { return (2 * index + 2); }

  /// @brief Приводит кучу в валидное состояние после добавления
  void SiftUp() {
    // идем с конца по родителям
    size_t index = Size() - 1;

    // пока следующий родитель больше, меняем местами
    while (index > 0 && data_[ParentOf(index)] < data_[index]) {
      std::swap(data_[index], data_[ParentOf(index)]);
      index = ParentOf(index);
    }
  }

  /// @brief Приводит кучу в валидное состояние после удаления
  void SiftDown(size_t index = 0) {
    while (index < Size()) {
      size_t largest = index;  // largest = корень поддерева

      // если левый потомок существует и больше текущего лучшего элемента
      if (LeftChildOf(index) < Size() &&
          data_[LeftChildOf(index)] > data_[largest]) {
        largest = LeftChildOf(index);
      }

      // если правый потомок существует и больше текущего лучшего элемента
      if (RightChildOf(index) < Size() &&
          data_[RightChildOf(index)] > data_[largest]) {
        largest = RightChildOf(index);
      }

      // если текущий элемент не больше своих потомков, завершаем итерацию
      if (largest == index) break;

      // меняем местами текущий элемент с наибольшим из потомков
      std::swap(data_[index], data_[largest]);

      // переходим вниз по дереву к потомку, с которым произвели обмен
      index = largest;
    }
  }

  /// @brief Данные кучи
  std::vector<T> data_;
};