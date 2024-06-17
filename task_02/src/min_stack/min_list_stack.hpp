#pragma once

#include <initializer_list>
#include <list>
#include <memory>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

/**
 * @brief реализация стека на двусвязном списке (std::list)
 * @tparam T: тип значений элементов стека
 */
template <typename T>
class MinListStack {
 public:
  MinListStack() = default;

  MinListStack(const T& value) { Push(value); }

  MinListStack(const MinListStack<T>&) = default;

  MinListStack(const std::stack<T>& stack) { PushRange(stack); }

  MinListStack(const std::vector<T>& vector) { PushRange(vector); }

  MinListStack(const std::initializer_list<T>& init_list) {
    PushRange(init_list);
  }

  MinListStack& operator=(const MinListStack<T>&) = default;
  MinListStack& operator=(MinListStack<T>&&) = default;

  bool operator==(const MinListStack<T>& other) const {
    return list_ == other.list_;
  }

  /**
   * @return T: верхний элемент стека
   * @throw std::logic_error: если стек пуст
   */
  T Top() {
    if (Empty()) throw std::logic_error("Stack is empty");

    return list_.back().first;
  }

  /**
   * @brief проверяет, пуст ли стек
   * @return true: если пуст
   * @return false: если не пуст
   */
  bool Empty() { return list_.empty(); }

  /**
   * @return size_t: размер стека
   */
  size_t Size() { return list_.size(); }

  /**
   * @brief добавляет новый элемент в стек
   * @param value: значение нового элемента
   */
  void Push(const T& value = T()) {
    T newMin = list_.empty() ? value : std::min(value, list_.back().second);
    list_.emplace_back(value, newMin);
  }

  /**
   * @brief расширяет стек значениями элементов другого стека
   * @param stack
   */
  void PushRange(MinListStack<T> stack) {
    MinListStack<T> temp_stack;
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

    list_.pop_back();
  }

  /**
   * @brief меняет все элементы двух стеков местами
   * @param another_stack
   * @throw std::invalid_argument: если размеры стеков не совпадает
   */
  void Swap(MinListStack<T>& another_stack) {
    if (Size() != another_stack.Size()) {
      throw std::invalid_argument("Sizes of stacks do not match");
    }

    std::swap(list_, another_stack.list_);
  }

  /**
   * @return T: значение минимума стека
   * @throw std::logic_error: если минимум не проинициализирован
   */
  T GetMin() {
    if (Empty()) throw std::logic_error("Stack is empty");

    return list_.back().second;
  }

 private:
  std::list<std::pair<T, T>> list_;
};
