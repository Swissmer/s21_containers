#ifndef CPP2_CONTAINERS_SRC_MAP_S21_MAP_H_
#define CPP2_CONTAINERS_SRC_MAP_S21_MAP_H_

// #include "s21_srchelp.h"
#include <algorithm>
#include <initializer_list>
#include <stdexcept>

namespace s21 {
template <typename Key, typename T>
class Map {
 public:
  using size_type = size_t;
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  //  using reference = value_type &;
  //  using const_reference = const value_type &;

 public:
  template <class value_type>
  class Node {  // Binary tree for map container, bcs map is always sorting data
                // while appending their
   public:
    value_type data;
    Node *left;
    Node *right;
    Node *parent;

   public:
    Node(value_type const &item, Node *left_, Node *right_, Node *parent_)
        : data(item), left(left_), right(right_), parent(parent_) {}
  };

 public:
  Map();
  Map(std::initializer_list<value_type> const &items);
  Map(const Map &m);
  Map(Map &&m);
  ~Map();

  Map &operator=(const Map &m);
  Map &operator=(Map &&m);

  bool empty();
  size_type size();
  size_type max_size();
  mapped_type const *find(key_type const &key) const;

  class MapIterator {  // Map simple iterator
   public:
    using iterator = MapIterator;

    MapIterator() : current_(nullptr){};
    MapIterator(Node<value_type> *node) : current_(node) {}

    value_type const &operator*() const { return current_->data; }
    value_type const operator->() const { return current_->data; }

    MapIterator &operator++() {
      if (current_->right) {
        current_ = current_->right;
        while (current_->left) {
          current_ = current_->left;
        }
      } else {
        auto parent = current_->parent;
        while (parent && current_ == parent->right) {
          current_ = parent;
          parent = parent->parent;
        }
        current_ = parent;
      }
      return (*this);
    }

    MapIterator operator++(int) {
      if (current_->right) {
        current_ = current_->right;
        while (current_->left) {
          current_ = current_->left;
        }
      } else {
        auto parent = current_->parent;
        while (parent && current_ == parent->right) {
          current_ = parent;
          parent = parent->parent;
        }
        current_ = parent;
      }
      return (*this);
    }

    MapIterator &operator--() {
      if (current_->left) {
        current_ = current_->left;
        while (current_->right) {
          current_ = current_->right;
        }
      } else {
        Node<value_type> *parent = current_->parent;
        while (parent && current_ == parent->left) {
          current_ = parent;
          parent = parent->parent;
        }
        current_ = parent;
      }
      return (*this);
    }

    bool operator==(MapIterator const &other) const {
      return current_ == other.current_;
    }

    bool operator!=(MapIterator const &other) const {
      return !(*this == other);
    }

   private:
    Node<value_type> *current_;
    friend class Map<key_type, mapped_type>;
  };

  class MapConstIterator {  // Map const iterator
   public:
    MapConstIterator() : current_(nullptr) {}
    MapConstIterator(Node<value_type> *node) : current_(node) {}

    value_type const &operator*() const { return current_->data; }
    value_type const operator->() const { return current_->data; }

    MapConstIterator &operator++() {
      if (current_->right) {
        current_ = current_->right;
        while (current_->left) {
          current_ = current_->left;
        }
      } else {
        auto parent = current_->parent;
        while (parent && current_ == parent->right) {
          current_ = parent;
          parent = parent->parent;
        }
        current_ = parent;
      }
      return *this;
    }

    MapConstIterator operator++(int) {
      if (current_->right) {
        current_ = current_->right;
        while (current_->left) {
          current_ = current_->left;
        }
      } else {
        auto parent = current_->parent;
        while (parent && current_ == parent->right) {
          current_ = parent;
          parent = parent->parent;
        }
        current_ = parent;
      }
      return *this;
    }

    MapConstIterator &operator--() {
      if (current_->left) {
        current_ = current_->left;
        while (current_->right) {
          current_ = current_->right;
        }
      } else {
        Node<value_type> *parent = current_->parent;
        while (parent && current_ == parent->left) {
          current_ = parent;
          parent = parent->parent;
        }
        current_ = parent;
      }
      return *this;
    }

    bool operator==(const MapConstIterator &other) const {
      return current_ == other.current_;
    }
    bool operator!=(const MapConstIterator &other) const {
      return !(*this == other);
    }

   private:
    Node<value_type> *current_;
    friend class Map<key_type, mapped_type>;
  };

  MapConstIterator begin() const;
  MapIterator begin();
  MapConstIterator end() const;
  MapIterator end();

 public:
  void clear(Node<value_type> *node);
  void clear();
  void insert(Node<value_type> *&node, value_type const &item,
              Node<value_type> *parent = nullptr);

  std::pair<MapIterator, bool> insert(const value_type &value);
  std::pair<MapIterator, bool> insert(key_type const &key,
                                      mapped_type const &obj);
  std::pair<MapIterator, bool> insert_or_assign(key_type const &key,
                                                mapped_type const &obj);

  mapped_type &at(const key_type &key);
  mapped_type &operator[](const key_type &key);

  void swap(Map &other);
  void merge(Map &other);
  void erase(MapIterator pos);

  bool contains(const key_type &key) const;

  template <typename... Args>
  std::vector<std::pair<MapIterator, bool>> insert_many(Args &&...args);

 private:
  Node<value_type> *root_;
  size_type size_ = 0;
  Node<value_type> *find_node(Node<value_type> *node,
                              const key_type &key) const;
  mapped_type const *find(Node<value_type> *node, key_type const &key) const;
  void transplant(Node<value_type> *u, Node<value_type> *v);
  Node<value_type> *minimum(Node<value_type> *x) const;
  Node<value_type> *successor(Node<value_type> *x) const;
};

template <typename key_type, typename mapped_type>
Map<key_type, mapped_type>::Map() : root_(nullptr), size_(0U) {}

template <typename key_type, typename mapped_type>
Map<key_type, mapped_type>::Map(std::initializer_list<value_type> const &items)
    : Map() {
  for (auto const &item : items) {
    insert(item);
  }
}

template <typename key_type, typename mapped_type>
Map<key_type, mapped_type>::Map(const Map &m) : Map() {
  for (auto const &item : m) {
    insert(item);
  }
}

template <typename key_type, typename mapped_type>
Map<key_type, mapped_type>::Map(Map &&m) : root_(m.root_), size_(m.size_) {
  m.size_ = 0;
  m.root_ = nullptr;
}

template <typename key_type, typename mapped_type>
Map<key_type, mapped_type>::~Map() {
  clear(root_);
}

template <typename key_type, typename mapped_type>
Map<key_type, mapped_type> &Map<key_type, mapped_type>::operator=(
    const Map &m) {
  if (this != &m) {
    Map tmp(m);
    swap(tmp);
  }
  return *this;
}

template <typename key_type, typename mapped_type>
Map<key_type, mapped_type> &Map<key_type, mapped_type>::operator=(Map &&m) {
  if (this != &m) {
    clear(root_);
    root_ = m.root_;
    m.root_ = nullptr;
  }
  return *this;
}

template <typename key_type, typename mapped_type>
inline typename Map<key_type, mapped_type>::size_type
Map<key_type, mapped_type>::max_size() {
  std::allocator<std::pair<key_type, mapped_type>> Alloc;
  return std::allocator_traits<decltype(Alloc)>::max_size(Alloc) / 5;
}

template <typename key_type, typename mapped_type>
const mapped_type *s21::Map<key_type, mapped_type>::find(
    key_type const &key) const {
  return find(root_, key);
}

template <typename key_type, typename mapped_type>
bool s21::Map<key_type, mapped_type>::empty() {
  return size_ == 0;
}

template <typename key_type, typename mapped_type>
size_t s21::Map<key_type, mapped_type>::size() {
  return size_;
}

template <typename key_type, typename mapped_type>
inline typename s21::Map<key_type, mapped_type>::MapConstIterator
s21::Map<key_type, mapped_type>::begin() const {
  if (!root_) {
    return MapConstIterator(nullptr);
  }

  Node<value_type> *cur = root_;
  while (cur->left) {
    cur = cur->left;
  }

  return MapConstIterator(cur);
}

template <typename key_type, typename mapped_type>
inline typename s21::Map<key_type, mapped_type>::MapIterator
s21::Map<key_type, mapped_type>::begin() {
  if (!root_) {
    return MapIterator(nullptr);
  }

  Node<value_type> *cur = root_;
  while (cur->left) {
    cur = cur->left;
  }

  return MapIterator(cur);
}

template <typename key_type, typename mapped_type>
inline typename s21::Map<key_type, mapped_type>::MapConstIterator
s21::Map<key_type, mapped_type>::end() const {
  return MapConstIterator(nullptr);
}

template <typename key_type, typename mapped_type>
inline typename s21::Map<key_type, mapped_type>::MapIterator
s21::Map<key_type, mapped_type>::end() {
  return MapIterator(nullptr);
}

template <typename key_type, typename mapped_type>
inline void s21::Map<key_type, mapped_type>::clear(Node<value_type> *node) {
  if (node) {
    clear(node->left);
    clear(node->right);
    delete node;
  }
}
template <typename key_type, typename mapped_type>
inline void s21::Map<key_type, mapped_type>::clear() {
  clear(root_);
  root_ = nullptr;
  size_ = 0;
}

template <typename key_type, typename mapped_type>
inline void s21::Map<key_type, mapped_type>::insert(Node<value_type> *&node,
                                                    value_type const &item,
                                                    Node<value_type> *parent) {
  if (!node) {
    node = new Node<value_type>(item, nullptr, nullptr, parent);
  } else if (item.first < node->data.first) {
    insert(node->left, item, node);
  } else if (node->data.first < item.first) {
    insert(node->right, item, node);
  } else {
    node->data.second = item.second;
  }
  ++size_;
}

template <typename key_type, typename mapped_type>
typename std::pair<typename s21::Map<key_type, mapped_type>::MapIterator, bool>
s21::Map<key_type, mapped_type>::insert(const value_type &value) {
  Node<value_type> **cur = &root_;
  Node<value_type> *parent = nullptr;

  while (*cur) {
    if (value.first < (*cur)->data.first) {
      parent = *cur;
      cur = &(*cur)->left;
    } else if ((*cur)->data.first < value.first) {
      parent = *cur;
      cur = &(*cur)->right;
    } else {
      // false
      return std::make_pair(MapIterator(*cur), false);
    }
  }

  *cur = new Node<value_type>(value, nullptr, nullptr, parent);
  ++size_;
  return std::make_pair(MapIterator(*cur), true);
}

template <typename key_type, typename mapped_type>
typename std::pair<typename s21::Map<key_type, mapped_type>::MapIterator, bool>
s21::Map<key_type, mapped_type>::insert(key_type const &key,
                                        mapped_type const &obj) {
  Node<value_type> **cur = &root_;
  Node<value_type> *parent = nullptr;

  while (*cur) {
    if (key < (*cur)->data.first) {
      parent = *cur;
      cur = &(*cur)->left;
    } else if ((*cur)->data.first < key) {
      parent = *cur;
      cur = &(*cur)->right;
    } else {
      return std::make_pair(MapIterator(*cur), false);
    }
  }
  *cur = new Node<value_type>(value_type(key, obj), nullptr, nullptr, parent);
  ++size_;
  return std::make_pair(MapIterator(*cur), true);
}

template <typename key_type, typename mapped_type>
typename std::pair<typename s21::Map<key_type, mapped_type>::MapIterator, bool>
s21::Map<key_type, mapped_type>::insert_or_assign(key_type const &key,
                                                  mapped_type const &obj) {
  Node<value_type> **cur = &root_;
  Node<value_type> *parent = nullptr;
  while (*cur) {
    if (key < (*cur)->data.first) {
      parent = *cur;
      cur = &(*cur)->left;
    } else if ((*cur)->data.first < key) {
      parent = *cur;
      cur = &(*cur)->right;
    } else {
      (*cur)->data.second = obj;
      return std::make_pair(MapIterator(*cur), false);
    }
  }
  *cur = new Node<value_type>(value_type(key, obj), nullptr, nullptr, parent);
  ++size_;
  return std::make_pair(MapIterator(*cur), true);
}

template <typename key_type, typename mapped_type>
typename Map<key_type, mapped_type>::mapped_type &
Map<key_type, mapped_type>::at(const key_type &key) {
  Node<value_type> *node = find_node(root_, key);

  if (node) {
    return node->data.second;
  } else {
    throw std::out_of_range("Key not found");
  }
}

template <typename key_type, typename mapped_type>
typename Map<key_type, mapped_type>::mapped_type &
Map<key_type, mapped_type>::operator[](const key_type &key) {
  Node<value_type> *current_ = root_;
  Node<value_type> *parent = nullptr;

  while (current_ != nullptr) {
    if (key == current_->data.first) {
      return current_->data.second;
    } else if (key < current_->data.first) {
      parent = current_;
      current_ = current_->left;
    } else {
      parent = current_;
      current_ = current_->right;
    }
  }

  Node<value_type> *newNode = new Node<value_type>(
      std::make_pair(key, mapped_type()), nullptr, nullptr, parent);

  if (parent == nullptr) {
    root_ = newNode;
  } else if (key < parent->data.first) {
    parent->left = newNode;
  } else {
    parent->right = newNode;
  }
  ++size_;
  return newNode->data.second;
}

template <typename key_type, typename mapped_type>
typename s21::Map<key_type, mapped_type>::template Node<
    std::pair<const key_type, mapped_type>>
    *s21::Map<key_type, mapped_type>::find_node(Node<value_type> *node,
                                                const key_type &key) const {
  if (node == nullptr) {
    return nullptr;
  } else if (key < node->data.first) {
    return find_node(node->left, key);
  } else if (key > node->data.first) {
    return find_node(node->right, key);
  } else {
    return node;
  }
}

template <typename key_type, typename mapped_type>
typename Map<key_type, mapped_type>::mapped_type const *
Map<key_type, mapped_type>::find(Node<value_type> *node,
                                 key_type const &key) const {
  if (!node) {
    return nullptr;
  } else if (key < node->data.first) {
    return find(node->left, key);
  } else if (node->data.first < key) {
    return find(node->right, key);
  } else {
    return &(node->data.second);
  }
}
template <typename key_type, typename mapped_type>
inline void s21::Map<key_type, mapped_type>::swap(Map &other) {
  std::swap(root_, other.root_);
  std::swap(size_, other.size_);
}

template <typename key_type, typename mapped_type>
bool s21::Map<key_type, mapped_type>::contains(const key_type &key) const {
  Node<value_type> *current_ = root_;
  while (current_ != nullptr) {
    if (key == current_->data.first) {
      return true;
    } else if (key < current_->data.first) {
      current_ = current_->left;
    } else {
      current_ = current_->right;
    }
  }
  return false;
}

template <typename key_type, typename mapped_type>
inline void s21::Map<key_type, mapped_type>::merge(Map &other) {
  for (auto const &item : other) {
    insert(item);
    // other.clear();
  }
}

template <typename key_type, typename mapped_type>
inline void s21::Map<key_type, mapped_type>::erase(MapIterator pos) {
  Node<value_type> *node = pos.current_;
  if (!node) {
    return;
  }
  if (!node->left && !node->right) {
    if (node == root_) {
      root_ = nullptr;
    } else {
      if (node->parent->left == node) {
        node->parent->left = nullptr;
      } else {
        node->parent->right = nullptr;
      }
    }
  } else if (!node->left) {
    transplant(node, node->right);
  } else if (!node->right) {
    transplant(node, node->left);
  } else {
    Node<value_type> *min_right = minimum(node->right);
    if (min_right->parent != node) {
      transplant(min_right, min_right->right);
      min_right->right = node->right;
      min_right->right->parent = min_right;
    }
    transplant(node, min_right);
    min_right->left = node->left;
    min_right->left->parent = min_right;
  }
  delete node;
  --size_;
}

template <typename key_type, typename mapped_type>
inline void s21::Map<key_type, mapped_type>::transplant(Node<value_type> *u,
                                                        Node<value_type> *v) {
  if (!u->parent) {
    root_ = v;
  } else if (u == u->parent->left) {
    u->parent->left = v;
  } else {
    u->parent->right = v;
  }
  if (v) {
    v->parent = u->parent;
  }
}

template <typename key_type, typename mapped_type>
typename s21::Map<key_type, mapped_type>::template Node<
    std::pair<const key_type, mapped_type>>
    *s21::Map<key_type, mapped_type>::minimum(Node<value_type> *x) const {
  while (x->left) {
    x = x->left;
  }
  return x;
}

template <typename key_type, typename mapped_type>
typename s21::Map<key_type, mapped_type>::template Node<
    std::pair<const key_type, mapped_type>>
    *s21::Map<key_type, mapped_type>::successor(Node<value_type> *x) const {
  if (x->right) {
    return minimum(x->right);
  }
  Node<value_type> *y = x->parent;
  while (y && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

template <typename key_type, typename mapped_type>
template <typename... Args>
std::vector<std::pair<typename Map<key_type, mapped_type>::MapIterator, bool>>
s21::Map<key_type, mapped_type>::insert_many(Args &&...args) {
  std::vector<std::pair<MapIterator, bool>> result = {(insert(args))...};
  return result;
}
}  // namespace s21

#endif  // CPP2_CONTAINERS_SRC_MAP_S21_MAP_H_
