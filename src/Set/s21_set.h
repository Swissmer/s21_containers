#ifndef CPP2_CONTAINERS_SRC_SET_S21_SET_H_
#define CPP2_CONTAINERS_SRC_SET_S21_SET_H_

#include <iostream>

#include "../RedBlackTree/s21_rbtree.h"

namespace s21 {
template <typename Key>
class Set {
 public:
  //  Set Member type
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename RedBlackTree<Key>::iterator;
  using const_iterator = typename RedBlackTree<Key>::const_iterator;
  using size_type = size_t;

  // Set Member functions
  Set() : tree_(){};
  Set(std::initializer_list<value_type> const &items) {
    for (auto element : items) {
      tree_.insert(element);
    }
  };
  Set(const Set &s) : tree_(s.tree_) {}
  Set(Set &&s) : tree_(std::move(s.tree_)){};
  ~Set(){};
  Set &operator=(Set &&s) {
    tree_ = std::move(s.tree_);
    return *this;
  }

  // Set Iterators
  iterator begin() { return tree_.begin(); }
  iterator end() { return tree_.end(); }

  // Set Capacity
  bool empty() { return tree_.empty(); }
  size_type size() { return tree_.size(); }
  size_type max_size() { return tree_.max_size(); }

  // Set Modifiers
  void clear() { return tree_.clear(); }
  std::pair<iterator, bool> insert(const value_type &value) {
    return tree_.insert(value);
  }
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> result;
    for (const auto &arg : {args...}) {
      result.push_back(insert(arg));
    }
    return result;
  }
  void erase(iterator pos) { return tree_.erase(pos); }
  void swap(Set &other) { tree_.swap(other.tree_); }
  void merge(Set &other) { tree_.merge(other.tree_); }

  // Set Lookup
  iterator find(const Key &key) { return tree_.find(key); }
  bool contains(const Key &key) { return tree_.contains(key); }

  // for dev
  void print() { tree_.print(); }

 private:
  RedBlackTree<Key> tree_;
};

}  // namespace s21

#endif  // CPP2_CONTAINERS_SRC_SET_S21_SET_H_
