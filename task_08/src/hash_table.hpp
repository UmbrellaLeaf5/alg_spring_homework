#include <vector>

/**
 * @file hash_table.h
 * @brief Реализация простой хэш-таблицы с открытой адресацией
 *
 * @details Данная реализация хэш-таблицы использует хэш-функцию FNV-1a для
 * равномерного распределения элементов. Коллизии разрешаются с помощью
 * связанных списков.
 */

/**
 * @brief Элемент хэш-таблицы
 * @tparam V: тип значения, хранимого в хэш-таблице
 *
 * @details Каждый элемент хэш-таблицы содержит ключ, значение и указатель на
 * следующий элемент в случае коллизии.
 */
template <typename V>
struct HashNode {
  /**
   * @brief Инициализирует новый экземпляр элемента хэш-таблицы
   * @param key: ключ элемента
   * @param value: значение элемента
   */
  HashNode(const size_t& key, const V& value)
      : key(key), value(value), next(nullptr) {}

  /// @brief Ключ элемента
  size_t key;

  /// @brief Значение элемента
  V value;

  /// @brief Указатель на следующий
  HashNode* next;
};

/**
 * @brief Реализация хэш-таблицы
 * @tparam V: тип значения, хранимого в хэш-таблице
 *
 * @details Класс реализует основные операции с хэш-таблицей: вставка, получение
 * значения по ключу и удаление элемента по ключу.
 */
template <typename V>
class HashTable {
 public:
  /**
   * @brief Инициализирует новый экземпляр Hash Table
   *
   * @param size: начальный размер хэш-таблицы
   */
  HashTable(size_t size) { table.resize(size, nullptr); }

  ~HashTable() {
    for (const auto& elem : table) delete elem;
  }

  /**
   * @brief Вычисляет хэш-значение по ключу
   * @details
   * https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function?useskin=vector
   * @param key: ключ для вычисления хеша
   * @param table_size: размер хэш-таблицы
   * @return size_t: индекс элемента в хэш-таблице
   */
  size_t HashFunction(const size_t& key, size_t table_size) {
    size_t hash = 2166136261;  // начальное значение FNV-1a хеша
    const size_t fnv_prime = 16777619;

    for (char c : std::to_string(key)) {
      hash ^= static_cast<size_t>(c);
      hash *= fnv_prime;
    }

    return hash % table_size;
  }

  /**
   * @brief Вставляет элемент в хэш-таблицу
   * @param key: ключ для вычисления хеша
   * @param value: значение вставляемого элемента
   */
  void Insert(const size_t& key, const V& value) {
    size_t index = HashFunction(key, table.size());
    HashNode<V>* newNode = new HashNode<V>(key, value);

    if (table[index] == nullptr)
      table[index] = newNode;

    else {
      HashNode<V>* current = table[index];

      while (current->next != nullptr) current = current->next;

      current->next = newNode;
    }
  }

  /**
   * @brief Получает значение по ключу
   * @param key: ключ для поиска
   * @return V: значение, соответствующее ключу
   * @throw std::out_of_range: если ключ не найден в хэш-таблице
   */
  V GetValue(const size_t& key) {
    size_t index = HashFunction(key, table.size());
    HashNode<V>* current = table[index];

    while (current != nullptr) {
      if (current->key == key) return current->value;

      current = current->next;
    }

    throw std::out_of_range("Key not found.");
  }

  /**
   * @brief Удаляет элемент по ключу
   * @param key: ключ удаляемого элемента
   * @throw std::out_of_range: если ключ не найден в хэш-таблице
   */
  void RemoveByKey(const size_t& key) {
    size_t index = HashFunction(key, table.size());
    HashNode<V>* current = table[index];
    HashNode<V>* prev = nullptr;

    while (current != nullptr) {
      if (current->key == key) {
        if (prev == nullptr)
          table[index] = current->next;

        else
          prev->next = current->next;

        delete current;
        return;
      }

      prev = current;
      current = current->next;
    }

    throw std::out_of_range("Key not found.");
  }

  auto Size() { return table.size(); }

 private:
  /// @brief Массив указателей на элементы хэш-таблицы
  std::vector<HashNode<V>*> table;
};
