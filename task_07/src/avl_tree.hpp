#pragma once

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <list>
#include <vector>

template <typename T>
struct AVLTreeNode {
  /**
   * @brief Инициализирует новый экземпляр AVLTreeNode
   * @param key: ключ, который будет храниться в узле
   */
  AVLTreeNode(T key = T()) : key{key} {}

  /**
   * @brief Инициализирует новый экземпляр AVLTreeNode
   * @param key: ключ, который будет храниться в узле
   * @param left: указатель на левого потомка
   * @param right: указатель на правого потомка
   */
  AVLTreeNode(T key, AVLTreeNode* left, AVLTreeNode* right)
      : key{key}, left{left}, right{right} {}

  /// @brief Ключ, хранящийся в узле
  T key;

  /// @brief Высота поддерева, корнем которого является этот узел
  size_t height = 1;

  /// @brief Указатель на левого потомка
  AVLTreeNode* left = nullptr;

  /// @brief Указатель на правого потомка
  AVLTreeNode* right = nullptr;

  ~AVLTreeNode() {
    delete left;
    delete right;
  }
};

template <typename T>
class AVLTree {
 public:
  /// @brief Инициализирует новый экземпляр AVLTree
  AVLTree() : root{nullptr} {}

  /**
   * @brief Инициализирует новый экземпляр AVLTree
   * @param vec: вектор
   */
  AVLTree(const std::vector<T>& vec) : root{nullptr} {
    for (const T& elem : vec) Push(elem);
  }

  /**
   * @brief Инициализирует новый экземпляр AVLTree
   * @param list: список инициализации
   */
  AVLTree(const std::initializer_list<T>& list) : root{nullptr} {
    for (const T& elem : list) Push(elem);
  }

  /**
   * @brief Инициализирует новый экземпляр AVLTree
   * @param list: двусвязный список
   */
  AVLTree(const std::list<T>& list) : root{nullptr} {
    for (const T& elem : list) Push(elem);
  }

  /**
   * @brief Проверяет, содержится ли ключ k в AVL-дереве
   * @param k: ключ, который нужно найти
   * @return true, если ключ найден, иначе false
   */
  bool Contains(T k) const { return FindNodeByKey(root, k) != nullptr; }

  /**
   * @brief Вставляет ключ k в AVL-дерево
   * @param k: ключ, который нужно вставить
   */
  void Push(T k) { root = InsertedTree(root, k); }

  /**
   * @brief Удаляет ключ k из AVL-дерева
   * @param k: ключ, который нужно удалить
   */
  void Pop(T k) { root = RemovedTree(root, k); }

  ~AVLTree() { delete root; }

 private:
  /// @brief Указатель на корень дерева
  AVLTreeNode<T>* root;

  /**
   * @brief Выполняет правый поворот поддерева
   * @param n: узел поддерева, вокруг которого выполняется поворот
   * @return AVLTreeNode<T>*: новый корень поддерева после поворота
   */
  AVLTreeNode<T>* RotateRight(AVLTreeNode<T>* n) {
    AVLTreeNode<T>* l = n->left;
    n->left = l->right;
    l->right = n;

    UpdateHeight(n);
    UpdateHeight(l);

    return l;
  }

  /**
   * @brief Выполняет левый поворот поддерева
   * @param n: узел поддерева, вокруг которого выполняется поворот
   * @return AVLTreeNode<T>*: новый корень поддерева после поворота
   */
  AVLTreeNode<T>* RotateLeft(AVLTreeNode<T>* n) {
    AVLTreeNode<T>* r = n->right;
    n->right = r->left;
    r->left = n;

    UpdateHeight(r);
    UpdateHeight(n);

    return r;
  }

  /**
   * @brief Выполняет балансировку поддерева
   * @param n: узел поддерева, которое нужно сбалансировать
   * @return AVLTreeNode<T>*: новый корень поддерева после балансировки
   */
  AVLTreeNode<T>* Balance(AVLTreeNode<T>* n) {
    /**
     * @brief Вычисляет фактор балансировки поддерева
     * @param n: корень поддерева, для которого нужно вычислить фактор
     * @return long long: фактор балансировки поддерева
     */
    std::function<long long(AVLTreeNode<T>*)> BalanceFactor =
        [this](AVLTreeNode<T>* n) {
          return SubtreeHeight(n->right) - SubtreeHeight(n->left);
        };

    UpdateHeight(n);

    switch (BalanceFactor(n)) {
      case 2:
        if (BalanceFactor(n->right) < 0) n->right = RotateRight(n->right);
        return RotateLeft(n);

      case -2:
        if (BalanceFactor(n->left) > 0) n->left = RotateLeft(n->left);
        return RotateRight(n);

      default:
        return n;
    }
  }

  /**
   * @brief Вставляет ключ в поддерево
   * @param n: корень поддерева, в который нужно вставить ключ
   * @param k: ключ, который нужно вставить
   * @return AVLTreeNode<T>*: новый корень поддерева после вставки
   */
  AVLTreeNode<T>* InsertedTree(AVLTreeNode<T>* n, T k) {
    if (!n) return new AVLTreeNode(k);

    if (k < n->key)
      n->left = InsertedTree(n->left, k);
    else
      n->right = InsertedTree(n->right, k);

    return Balance(n);
  }

  /**
   * @brief Удаляет узел с ключем k из поддерева
   * @param n: корень поддерева, из которого нужно удалить ключ
   * @param k: ключ, который нужно удалить
   * @return AVLTreeNode<T>*: новый корень поддерева после удаления ключа
   */
  AVLTreeNode<T>* RemovedTree(AVLTreeNode<T>* n, T k) {
    if (!n) return nullptr;

    if (k == n->key) {
      if (!n->right) return n->left;

      FindMinKeyNode(n->right)->right = RemovedMinKeyNode(n->right);
      FindMinKeyNode(n->right)->left = n->left;
      return Balance(FindMinKeyNode(n->right));
    }

    k < n->key ? n->left = RemovedTree(n->left, k)
               : n->right = RemovedTree(n->right, k);
    return Balance(n);
  }

  /**
   * @brief Удаляет узел с минимальным ключом из поддерева
   * @param n: корень поддерева, из которого нужно удалить минимальный узел
   * @return AVLTreeNode<T>*: новый корень поддерева после удаления
   */
  AVLTreeNode<T>* RemovedMinKeyNode(AVLTreeNode<T>* n) {
    if (!n->left) return n->right;

    n->left = RemovedMinKeyNode(n->left);
    return Balance(n);
  }

  /**
   * @brief Находит узел с ключом k в поддереве
   * @param n: корень поддерева, в котором нужно найти ключ
   * @param k: ключ, который нужно найти
   * @return AVLTreeNode<T>*: указатель на узел с ключом k (если нету - nullptr)
   */
  AVLTreeNode<T>* FindNodeByKey(AVLTreeNode<T>* n, T k) const {
    if (n == nullptr || n->key == k) return n;

    return k < n->key ? FindNodeByKey(n->left, k) : FindNodeByKey(n->right, k);
  }

  /**
   * @brief Находит узел с минимальным ключом в поддереве
   * @param n: корень поддерева, в котором нужно найти минимальный узел
   * @return AVLTreeNode<T>*: указатель на узел с минимальным ключом
   */
  AVLTreeNode<T>* FindMinKeyNode(AVLTreeNode<T>* n) {
    return n->left ? FindMinKeyNode(n->left) : n;
  }

  /**
   * @brief Вычисляет высоту поддерева, корнем которого является этот узел
   * @return size_t: высота поддерева
   */
  size_t SubtreeHeight(AVLTreeNode<T>* n) { return n ? n->height : 0; }

  /**
   * @brief Обновляет высоту поддерева
   * @param n: корень поддерева, высоту которого нужно обновить
   */
  void UpdateHeight(AVLTreeNode<T>* n) {
    n->height = std::max(SubtreeHeight(n->left), SubtreeHeight(n->right)) + 1;
  }
};
