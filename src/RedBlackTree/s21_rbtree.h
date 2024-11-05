#ifndef CPP2_CONTAINERS_SRC_RBTREE_S21_RBTREE_H_
#define CPP2_CONTAINERS_SRC_RBTREE_S21_RBTREE_H_

#include <iostream>
#include <limits>
// using namespace std;

#define RED true
#define BLACK false

namespace s21 {
template <typename Key>
class RedBlackTree {
 public:
  class Node;
  class RedBlackTreeIterator;
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = RedBlackTree<Key>::RedBlackTreeIterator;
  using const_iterator = RedBlackTree<Key>::RedBlackTreeIterator;
  using size_type = size_t;
  using treeNode = Node *;

  class RedBlackTreeIterator {
   public:
    // Constructors and destructors
    RedBlackTreeIterator();
    RedBlackTreeIterator(treeNode other, treeNode node);

    // Comparison operators
    bool operator==(const RedBlackTreeIterator &other) const;
    bool operator!=(const RedBlackTreeIterator &other) const;

    // Increment and decrement operators
    RedBlackTreeIterator &operator++();
    RedBlackTreeIterator operator++(int);
    RedBlackTreeIterator &operator--();
    RedBlackTreeIterator operator--(int);

    // Dereference operator
    reference operator*() const;

    // For develop
    treeNode getNode() const;

   private:
    // Variables
    treeNode iter;
    treeNode nil;

    // Methods not available
    treeNode getMin(treeNode node) const;
    treeNode getMax(treeNode node) const;
    size_type getSize(treeNode node) const;
    size_type size(treeNode node) const;
  };

  // Constructors and destructors
  RedBlackTree();
  RedBlackTree(const RedBlackTree &tree);
  RedBlackTree(RedBlackTree &&tree);
  ~RedBlackTree();

  // Iterators
  iterator begin() const;
  iterator end() const;

  // Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Modifiers
  RedBlackTree &operator=(RedBlackTree &&tree);
  void clear();
  std::pair<iterator, bool> insert(const value_type &value, bool var = false);
  void erase(iterator value);
  void swap(RedBlackTree &tree);
  void merge(RedBlackTree &other, bool var = false);

  // Lookup
  size_type count(const Key &key);
  iterator find(const Key &key);
  iterator upper_bound(const Key &key);
  bool contains(const Key &key);
  std::pair<iterator, iterator> equal_range(const Key &key);
  void print();
  treeNode getMax(treeNode node);
  treeNode getMin(treeNode node);

 private:
  // Main variables
  treeNode root;
  treeNode nil;

  // Methods not available
  void insertValue(key_type value);

  // Balancing
  void insertBalance(treeNode newNode);
  void eraseBalance(treeNode node);

  // Rotate
  void leftRotate(treeNode node);
  void rightRotate(treeNode node);

  // For develop
  treeNode getRoot();
  treeNode getChild(treeNode node);
  treeNode createNil();
  int getChildrenCount(treeNode node);
  void clearTree(treeNode root);
  void printTree(treeNode root, int depth = 0);
  void moving(treeNode toNode, treeNode fromNode);
};
}  // namespace s21

#include "s21_rbtree.tpp"

#endif  // CPP2_CONTAINERS_SRC_RBTREE_S21_RBTREE_H_
