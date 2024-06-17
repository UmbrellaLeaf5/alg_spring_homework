#pragma once

#include <initializer_list>
#include <limits>
#include <memory>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

/**
 * @brief элемент стека с минимумом (звено в односвязном списке)
 * @tparam T: тип значения в стеке
 */
template <typename T>
class MinSinglyListElem {
 public:
  MinSinglyListElem() : prev{nullptr}, min{std::numeric_limits<T>::max()} {}

  MinSinglyListElem(const MinSinglyListElem<T>& elem)
      : prev{elem.prev}, data{elem.data}, min{elem.min} {}

  MinSinglyListElem(MinSinglyListElem<T>* elem, const T& value)
      : prev(elem),
        data{value},
        min{std::min(elem ? elem->min : std::numeric_limits<T>::max(), value)} {
  }

  MinSinglyListElem(const std::shared_ptr<MinSinglyListElem<T>>& elem,
                    const T& value)
      : prev(elem),
        data{value},
        min{std::min(elem ? elem->min : std::numeric_limits<T>::max(), value)} {
  }

  MinSinglyListElem(const T& value) : prev{nullptr}, data{value}, min{value} {}

  MinSinglyListElem<T>& operator=(MinSinglyListElem<T>&&) = default;
  MinSinglyListElem<T>& operator=(const MinSinglyListElem<T>& elem) = default;

  bool operator==(const MinSinglyListElem<T>& elem) const {
    return data == elem.data;
  }

  // @brief указатель на предыдущий элемент
  std::shared_ptr<MinSinglyListElem<T>> prev;

  // @brief значение элемента
  T data;

  // @brief минимальный элемент на данном уровне стека
  T min;
};

/**
 * @brief реализация стека с минимумом на односвязном списке
 * @tparam T: тип значений элементов стека
 */
template <typename T>
class MinSinglyListStack {
 public:
  MinSinglyListStack() = default;

  MinSinglyListStack(const T& value) { Push(value); }

  MinSinglyListStack(const MinSinglyListStack<T>& stack) = default;

  MinSinglyListStack(const std::stack<T>& stack) { PushRange(stack); }

  MinSinglyListStack(const std::vector<T>& vector) { PushRange(vector); }

  MinSinglyListStack(const std::initializer_list<T>& init_list) {
    PushRange(init_list);
  }

  MinSinglyListStack& operator=(const MinSinglyListStack<T>& stack) {
    PushRange(stack);
    return *this;
  }

  MinSinglyListStack& operator=(MinSinglyListStack<T>&& stack) {
    PushRange(std::move(stack));
    return *this;
  }

  /**
   * @return T: верхний элемент стека
   * @throw std::logic_error: если стек пуст
   */
  T Top() {
    if (Empty()) throw std::logic_error("Stack is empty");

    return top_->data;
  }

  /**
   * @brief проверяет, пуст ли стек
   * @return true: если пуст
   * @return false: если не пуст
   */
  bool Empty() { return top_ == nullptr; }

  /**
   * @return size_t: размер стека
   */
  size_t Size() { return size_; }

  /**
   * @brief добавляет новый элемент в стек
   * @param value: значение нового элемента
   */
  void Push(const T& value = T()) {
    auto new_elem = std::make_shared<MinSinglyListElem<T>>(top_, value);
    top_ = new_elem;
    size_++;
  }

  /**
   * @brief расширяет стек значениями элементов другого стека
   * @param stack
   */
  void PushRange(MinSinglyListStack<T> stack) {
    MinSinglyListStack<T> temp_stack;
    while (!stack.Empty()) {
      temp_stack.Push(stack.Top());
      stack.Pop();
    }

    while (!temp_stack.Empty()) {
      Push(temp_stack.Top());
      temp_stack.Pop();
    }
  }

  /**
   * @brief расширяет стек значениями std::stack
   * @param stack
   */

  void PushRange(std::stack<T> stack) {
    std::stack<T> temp_stack;
    while (!stack.empty()) {
      temp_stack.push(stack.top());
      stack.pop();
    }

    while (!temp_stack.empty()) {
      Push(temp_stack.top());
      temp_stack.pop();
    }
  }

  /**
   * @brief расширяет стек значениями элементов вектора
   * @param vector
   */
  void PushRange(const std::vector<T>& vector) {
    for (const auto& elem : vector) Push(elem);
  }

  /**
   * @brief расширяет стек значениями элементов списка инициализации
   * @param init_list
   */
  void PushRange(const std::initializer_list<T>& init_list) {
    for (const auto& elem : init_list) Push(elem);
  }

  /**
   * @throw std::invalid_argument: если стек пуст
   */
  void Pop() {
    if (Empty()) throw std::logic_error("Stack is empty");

    top_ = top_->prev;
    size_--;
  }

  /**
   * @brief меняет все элементы двух стеков местами
   * @param another_stack
   * @throw std::invalid_argument: если размеры стеков не совпадает
   */
  void Swap(MinSinglyListStack<T>& another_stack) {
    if (Size() != another_stack.Size()) {
      throw std::invalid_argument("Sizes of stacks do not match");
    }

    std::swap(another_stack.TopPtr(), top_);
  }

  /**
   * @return T: минимальный элемент в стеке
   * @throw std::logic_error: если стек пуст
   */
  T GetMin() {
    if (Empty()) throw std::logic_error("Stack is empty");

    return top_->min;
  }

 private:
  /**
   * @return std::shared_ptr<MinSinglyListElem<T>>&: ptr на верхний элемент
   * стека
   * @throw std::logic_error: если ключ != "ptr"
   */
  std::shared_ptr<MinSinglyListElem<T>>& TopPtr() {
    if (Empty()) throw std::logic_error("Stack is empty");

    return top_;
  }

  std::shared_ptr<MinSinglyListElem<T>> top_ = nullptr;
  size_t size_ = 0;
};
