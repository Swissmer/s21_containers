#ifndef CPP2_CONTAINERS_SRC_MULTISET_S21_MULTISET_H_
#define CPP2_CONTAINERS_SRC_MULTISET_S21_MULTISET_H_

#include <iostream>
#include <limits>

#include "../RedBlackTree/s21_rbtree.h"

namespace s21 {
template <class Key>
class Multiset {
 public:
  //  Multiset Member type
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename RedBlackTree<Key>::iterator;
  using const_iterator = typename RedBlackTree<Key>::const_iterator;
  using size_type = size_t;

  // Multiset Member functions
  Multiset() : tree_(){};
  Multiset(std::initializer_list<value_type> const &items) {
    for (auto element : items) {
      tree_.insert(element, true);
    }
  };
  Multiset(const Multiset &ms) : tree_(ms.tree_) {}
  Multiset(Multiset &&ms) : tree_(std::move(ms.tree_)){};
  ~Multiset(){};
  Multiset &operator=(Multiset &&ms) {
    tree_ = std::move(ms.tree_);
    return *this;
  }

  // Multiset Iterators
  iterator begin() { return tree_.begin(); }
  iterator end() { return tree_.end(); }

  // Multiset Capacity
  bool empty() { return tree_.empty(); }
  size_type size() { return tree_.size(); }
  size_type max_size() { return tree_.max_size(); }

  // Multiset Modifiers
  void clear() { return tree_.clear(); }
  iterator insert(const value_type &value) {
    return tree_.insert(value, true).first;
  }
  template <typename... Args>
  Vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    Vector<std::pair<iterator, bool>> result;
    for (const auto &arg : {args...}) {
      result.push_back(tree_.insert(arg));
    }
    return result;
  }
  void erase(iterator pos) { return tree_.erase(pos); }
  void swap(Multiset &other) { tree_.swap(other.tree_); }
  void merge(Multiset &other) { tree_.merge(other.tree_); }

  // Multiset Lookup
  size_type count(const Key &key) { return tree_.count(key); }
  iterator find(const Key &key) { return tree_.find(key); }
  bool contains(const Key &key) { return tree_.contains(key); }
  std::pair<iterator, iterator> equal_range(const Key &key) {
    return tree_.equal_range(key);
  }
  iterator lower_bound(const Key &key) { return tree_.find(key); }
  iterator upper_bound(const Key &key) { return tree_.upper_bound(key); }

  // Multiset dev
  void print() { tree_.print(); }

 private:
  RedBlackTree<Key> tree_;
};

}  // namespace s21

#endif  // CPP2_CONTAINERS_SRC_MULTISET_S21_MULTISET_H_
