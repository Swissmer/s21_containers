#ifndef CPP2_CONTAINERS_SRC_LIST_S21_LIST_H_
#define CPP2_CONTAINERS_SRC_LIST_S21_LIST_H_

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {

template <typename T>
class List {
 public:
  // List Member type
  class Node;
  class ListConstIterator;
  class ListIterator;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = List<T>::ListIterator;
  using const_iterator = List<T>::ListConstIterator;
  using size_type = size_t;

  // List Functions
  List();
  List(size_type n);
  List(std::initializer_list<value_type> const &items);
  List(const List &l);
  List(List &&l);
  ~List();
  List &operator=(const List &l);
  List &operator=(List &&l) noexcept;
  List &operator=(std::initializer_list<value_type> const &items);

  // List Element access
  const_reference front() const noexcept { return carbin_->next_->value_; }
  const_reference back() const noexcept { return carbin_->prev_->value_; }

  // List Iterators
  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  iterator end() noexcept { return iterator(carbin_); }
  const_iterator end() const noexcept { return const_iterator(carbin_); }

  // List Capacity
  bool empty() const noexcept { return !list_size_; }
  size_type size() const noexcept { return list_size_; }
  size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(Node) / 2;  // !!!!
  }

  // List Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <class... Args>
  void insert_many_back(Args &&...args);
  template <class... Args>
  void insert_many_front(Args &&...args);
  void erase(iterator pos);
  void push_back(const_reference value) { insert(end(), value); }
  void pop_back() { erase(--end()); }
  void push_front(const_reference value) { insert(begin(), value); }
  void pop_front() { erase(begin()); }
  void swap(List &other) noexcept;
  void merge(List &other);
  void splice(const_iterator pos, List &other);
  void reverse();
  void unique();
  void sort();

  class ListIterator {
   public:
    friend class List;

    // Constructors and destructors
    ListIterator() : current_(nullptr) {}
    ListIterator(Node *node) : current_(node) {}

    // Comparison operators
    bool operator==(ListIterator other) noexcept;
    bool operator!=(ListIterator other) noexcept;

    // Increment and decrement operators
    ListIterator &operator++() noexcept;
    ListIterator operator++(int);
    ListIterator &operator--() noexcept;
    ListIterator operator--(int);

    // Dereference operator
    const_reference operator*() { return current_->value_; }

   private:
    Node *current_;
  };

  class ListConstIterator : public ListIterator {
   public:
    // Constructors and destructors
    ListConstIterator(){};
    ListConstIterator(ListIterator other) : ListIterator(other) {}
  };

  class Node {
   public:
    value_type value_;
    Node *next_ = nullptr;
    Node *prev_ = nullptr;

    Node(const_reference value) : value_(value) {}
  };

  // For dev
  void print() const;

 private:
  // Main variables
  Node *head_ = nullptr;
  Node *tail_ = nullptr;
  Node *carbin_ = nullptr;
  size_type list_size_ = 0;

  // Methods not available
  void base_list() noexcept;
  bool unique_list();
};

}  // namespace s21

#include "s21_list.tpp"

#endif  // CPP2_CONTAINERS_SRC_LIST_S21_LIST_H_
