namespace s21 {

///////////////////////////
// class description node//
///////////////////////////

template <typename Key>
class RedBlackTree<Key>::Node {
 public:
  Key data;
  bool color;
  Node *parent;
  Node *left;
  Node *right;
};

///////////////////////////////
// class description iterator//
///////////////////////////////

// Constructors and destructors

template <typename Key>
RedBlackTree<Key>::RedBlackTreeIterator::RedBlackTreeIterator()
    : iter(nullptr), nil(nullptr) {}

template <typename Key>
RedBlackTree<Key>::RedBlackTreeIterator::RedBlackTreeIterator(treeNode other,
                                                              treeNode node)
    : iter(other), nil(node) {}

// Comparison operators

template <typename Key>
bool RedBlackTree<Key>::RedBlackTreeIterator::operator==(
    const RedBlackTreeIterator &other) const {
  return iter == other.iter;
}

template <typename Key>
bool RedBlackTree<Key>::RedBlackTreeIterator::operator!=(
    const RedBlackTreeIterator &other) const {
  return iter != other.iter;
}

// Increment and decrement operators

template <typename Key>
typename RedBlackTree<Key>::RedBlackTreeIterator &
RedBlackTree<Key>::RedBlackTreeIterator::operator++() {
  if (iter != nil) {
    if (iter->right != nil) {
      iter = iter->right;
      while (iter->left != nil) {
        iter = iter->left;
      }
    } else {
      if (iter == getMax(iter)) {
        // "maximum reached"
        iter = nil;
      } else {
        while (iter->parent != nullptr && iter == iter->parent->right) {
          iter = iter->parent;
        }
        iter = iter->parent;
      }
    }
  }
  return *this;
}

template <typename Key>
typename RedBlackTree<Key>::RedBlackTreeIterator
RedBlackTree<Key>::RedBlackTreeIterator::operator++(int) {
  iterator it(*this);
  ++(*this);
  return it;
}

template <typename Key>
typename RedBlackTree<Key>::RedBlackTreeIterator &
RedBlackTree<Key>::RedBlackTreeIterator::operator--() {
  if (size(iter) > 0 && iter == nil) {
    iter = getMax(iter);
  } else if (iter != nil) {
    if (iter->left != nil) {
      iter = iter->left;
      while (iter->right != nil) {
        iter = iter->right;
      }
    } else {
      if (iter == getMin(iter)) {
        // "minimum reached"
      } else {
        while (iter->parent != nullptr && iter == iter->parent->left) {
          iter = iter->parent;
        }
        iter = iter->parent;
      }
    }
  }
  return *this;
}

template <typename Key>
typename RedBlackTree<Key>::RedBlackTreeIterator
RedBlackTree<Key>::RedBlackTreeIterator::operator--(int) {
  iterator it(*this);
  --(*this);
  return it;
}

// Dereference operator

template <typename Key>
Key &RedBlackTree<Key>::RedBlackTreeIterator::operator*() const {
  if (iter == nil)
    throw std::runtime_error("error value");
  
  return iter->data;
}

// For develop

template <typename Key>
typename RedBlackTree<Key>::Node *
RedBlackTree<Key>::RedBlackTreeIterator::getNode() const {
  return iter;
}

// Methods not available

template <typename Key>
typename RedBlackTree<Key>::Node *
RedBlackTree<Key>::RedBlackTreeIterator::getMin(
    RedBlackTree<Key>::Node *node) const {
  treeNode min = node;
  if (min->parent != nullptr) {
    while (min->parent != nullptr) min = min->parent;
    while (min->left != nil) min = min->left;
  }
  return min;
}

template <typename Key>
typename RedBlackTree<Key>::Node *
RedBlackTree<Key>::RedBlackTreeIterator::getMax(
    RedBlackTree<Key>::Node *node) const {
  treeNode max = node;
  if (max->parent != nullptr) {
    while (max->parent != nullptr) max = max->parent;
    while (max->right != nil) max = max->right;
  }
  return max;
}

template <typename Key>
size_t RedBlackTree<Key>::RedBlackTreeIterator::getSize(
    RedBlackTree<Key>::Node *node) const {
  if (node == nil) {
    return 0;
  } else {
    return 1 + getSize(node->left) + getSize(node->right);
  }
}

template <typename Key>
size_t RedBlackTree<Key>::RedBlackTreeIterator::size(
    RedBlackTree<Key>::Node *node) const {
  treeNode root = node;
  if (root->parent != nullptr) {
    while (root->parent != nullptr) root = root->parent;
  }
  size_type count = getSize(root);
  return count;
}

/////////////////////////////////
//// class description iterator//
/////////////////////////////////

// Constructors and destructors

template <typename Key>
s21::RedBlackTree<Key>::RedBlackTree() {
  root = createNil();
}

template <typename Key>
RedBlackTree<Key>::RedBlackTree(const RedBlackTree<Key> &tree) {
  root = createNil();
  for (const_iterator it = tree.begin(); it != tree.end(); ++it) {
    insert(*it, true);
  }
}

template <typename Key>
RedBlackTree<Key>::RedBlackTree(RedBlackTree<Key> &&tree) {
  root = createNil();
  swap(tree);
}

template <typename Key>
RedBlackTree<Key>::~RedBlackTree() {
  if (root != nil) {
    clear();
  }
  delete nil;
}

// Iterators

template <typename Key>
inline typename RedBlackTree<Key>::iterator RedBlackTree<Key>::begin() const {
  treeNode result = root;
  if (result != nil) {
    while (result->left != nil) {
      result = result->left;
    }
  }
  return iterator(result, this->nil);
}

template <typename Key>
inline typename RedBlackTree<Key>::iterator RedBlackTree<Key>::end() const {
  treeNode result = root;
  if (result != nil) {
    while (result->right != nil) {
      result = result->right;
    }
    result->right->parent = result;
    result = result->right;
  }
  return iterator(result, this->nil);
}

// Capacity

template <typename Key>
inline bool RedBlackTree<Key>::empty() {
  return this->root == nil ? true : false;
}

template <typename Key>
inline size_t RedBlackTree<Key>::size() {
  size_type count = 0;
  if (root != nil) {
    for (auto it = begin(); it != end(); ++it) {
      ++count;
    }
  }
  return count;
}

template <typename Key>
inline size_t RedBlackTree<Key>::max_size() {
  return std::numeric_limits<size_type>::max() / (sizeof(Node) / 2) / 5;
}

// Modifiers

template <typename Key>
RedBlackTree<Key> &RedBlackTree<Key>::operator=(RedBlackTree<Key> &&tree) {
  clear();
  swap(tree);
  return *this;
}

template <typename Key>
void RedBlackTree<Key>::clear() {
  clearTree(this->root);
  this->root = nil;
}

template <typename Key>
inline std::pair<typename RedBlackTree<Key>::iterator, bool>
RedBlackTree<Key>::insert(const Key &value, bool var) {
  std::pair<iterator, bool> result;
  result.first = find(value);
  result.second = false;
  iterator nodeInsert = find(value);
  size_type sizeBegin = size();
  if (nodeInsert == iterator(nil, nil)) {
    insertValue(value);
    result.first = find(value);
    if (size() > sizeBegin) result.second = true;
  } else {
    if (var == true) {
      insertValue(value);
      result.first = --upper_bound(value);
      if (size() > sizeBegin) result.second = true;
    }
  }
  return result;
}

template <typename Key>
void RedBlackTree<Key>::erase(iterator value) {
  if (value.getNode() == nil) 
    throw std::runtime_error("value error");
  
  treeNode nodeErase = value.getNode();
  bool eraseColor = nodeErase->color;
  treeNode child;
  if (getChildrenCount(nodeErase) < 2) {
    child = getChild(nodeErase);
    moving(nodeErase, child);
    delete nodeErase;
  } else {
    treeNode minNode = getMin(nodeErase->right);
    nodeErase->data = minNode->data;
    eraseColor = minNode->color;
    child = getChild(minNode);
    moving(minNode, child);
    delete minNode;
  }
  if (eraseColor == false) eraseBalance(child);
}

template <typename Key>
inline void RedBlackTree<Key>::swap(RedBlackTree<Key> &tree) {
  std::swap(root, tree.root);
  std::swap(nil, tree.nil);
}

template <typename Key>
inline void RedBlackTree<Key>::merge(RedBlackTree<Key> &other, bool var) {
  for (iterator it = other.begin(); it != other.end(); ++it) {
    insert(*it, var);
  }
}

// Lookup

template <typename Key>
size_t RedBlackTree<Key>::count(const Key &key) {
  size_t count = 0;
  for (auto it = begin(); it != end(); ++it) {
    if (*it == key) count += 1;
  }
  return count;
}

template <typename Key>
inline typename RedBlackTree<Key>::iterator RedBlackTree<Key>::find(
    const Key &key) {
  treeNode root = this->root;
  treeNode result = nil;
  while (root != nil) {
    if (root->data == key) {
      result = root;
    }
    if (root->data < key) {
      root = root->right;
    } else {
      root = root->left;
    }
  }
  return iterator(result, nil);
}

template <typename Key>
typename RedBlackTree<Key>::iterator RedBlackTree<Key>::upper_bound(
    const Key &key) {
  iterator result = find(key);
  if (result != end()) {
    for (iterator it = result; it != end(); ++it) {
      if (*it != key) {
        result = it;
        break;
      }
    }
  }
  return result;
}

template <typename Key>
inline bool RedBlackTree<Key>::contains(const Key &key) {
  return find(key) == iterator(nil, nil) ? false : true;
}

template <typename Key>
std::pair<typename RedBlackTree<Key>::iterator,
          typename RedBlackTree<Key>::iterator>
RedBlackTree<Key>::equal_range(const Key &key) {
  std::pair<iterator, iterator> result;
  result.first = find(key);
  result.second = result.first;
  if (result.first != end()) {
    for (iterator it = result.first; it != end(); ++it) {
      if (*it != key) {
        result.second = it;
        break;
      }
    }
  }
  return result;
}

template <typename Key>
void s21::RedBlackTree<Key>::print() {
  printTree(getRoot());
}

template <typename Key>
typename RedBlackTree<Key>::treeNode RedBlackTree<Key>::getMax(treeNode node) {
  while (node->right != nil) {
    node = node->right;
  }
  return node;
}

template <typename Key>
typename RedBlackTree<Key>::treeNode RedBlackTree<Key>::getMin(treeNode node) {
  while (node->left != nil) {
    node = node->left;
  }
  return node;
}

// Methods not available

template <typename Key>
void RedBlackTree<Key>::insertValue(key_type value) {
  treeNode node = new Node;
  node->parent = nullptr;
  node->data = value;
  node->left = nil;
  node->right = nil;
  node->color = true;

  treeNode parrent = nullptr;
  treeNode currentNode = this->root;

  while (currentNode != nil) {
    parrent = currentNode;
    if (node->data < currentNode->data)
      currentNode = currentNode->left;
    else
      currentNode = currentNode->right;
  }

  node->parent = parrent;
  if (parrent == nullptr) {
    root = node;
  } else if (node->data < parrent->data) {
    parrent->left = node;
  } else {
    parrent->right = node;
  }

  if (node->parent == nullptr) {
    node->color = false;
    return;
  }

  if (node->parent->parent == nullptr) {
    return;
  }

  insertBalance(node);
}

// Balancing

template <typename Key>
void RedBlackTree<Key>::insertBalance(treeNode newNode) {
  treeNode uncle;
  while (newNode->parent->color == true) {
    if (newNode->parent == newNode->parent->parent->left) {
      uncle = newNode->parent->parent->right;
      if (uncle->color == true) {
        newNode->parent->color = false;
        uncle->color = false;
        newNode->parent->parent->color = true;
        newNode = newNode->parent->parent;
      } else {
        if (newNode == newNode->parent->right) {
          newNode = newNode->parent;
          leftRotate(newNode);
        }
        newNode->parent->color = false;
        newNode->parent->parent->color = true;
        rightRotate(newNode->parent->parent);
      }
    } else {
      uncle = newNode->parent->parent->left;
      if (uncle->color == true) {
        newNode->parent->color = false;
        uncle->color = false;
        newNode->parent->parent->color = true;
        newNode = newNode->parent->parent;
      } else {
        if (newNode == newNode->parent->left) {
          newNode = newNode->parent;
          rightRotate(newNode);
        }
        newNode->parent->color = false;
        newNode->parent->parent->color = true;
        leftRotate(newNode->parent->parent);
      }
    }
    if (newNode == root) {
      break;
    }
  }
  root->color = false;
}

/////
/*
  1. Brother black
    1.1a Right child is red
    1.1b The left child is red
    1.2 Both of my brother's children are black
  2 - brother is red, children will definitely be black
*/
/////

template <typename Key>
void RedBlackTree<Key>::eraseBalance(treeNode node) {
  while (node != this->root && node->color == BLACK) {
    treeNode brother;
    if (node == node->parent->left) {
      brother = node->parent->right;
      if (brother->color == RED) {  // 2
        brother->color = BLACK;
        node->parent->color = RED;
        leftRotate(node->parent);
        brother = node->parent->right;
      }
      if (brother->left->color == BLACK &&
          brother->right->color == BLACK) {  // 1.2
        brother->color = RED;
        node = node->parent;
      } else {
        if (brother->right->color == BLACK) {  // 1.1б
          brother->left->color = BLACK;
          brother->color = RED;
          rightRotate(brother);
          brother = node->parent->right;
        }
        brother->color = node->parent->color;  // 1.1а
        node->parent->color = BLACK;
        brother->right->color = BLACK;
        leftRotate(node->parent);
        node = this->root;
      }
    } else {
      brother = node->parent->left;
      if (brother->color == RED) {  // 2
        brother->color = BLACK;
        node->parent->color = RED;
        rightRotate(node->parent);
        brother = node->parent->left;
      }
      if (brother->left->color == BLACK &&
          brother->right->color == BLACK) {  // 1.2
        brother->color = RED;
        node = node->parent;
      } else {
        if (brother->left->color == BLACK) {  // 1.1б
          brother->right->color = BLACK;
          brother->color = RED;
          leftRotate(brother);
          brother = node->parent->left;
        }
        brother->color = node->parent->color;  // 1.1а
        node->parent->color = BLACK;
        brother->left->color = BLACK;
        rightRotate(node->parent);
        node = this->root;
      }
    }
  }
  node->color = BLACK;
}

// Rotate

template <typename Key>
void RedBlackTree<Key>::leftRotate(treeNode node) {
  treeNode value = node->right;
  node->right = value->left;
  if (value->left != nil) {
    value->left->parent = node;
  }
  value->parent = node->parent;
  if (value->parent == nullptr) {
    this->root = value;
  } else if (node == node->parent->left) {
    node->parent->left = value;
  } else {
    node->parent->right = value;
  }
  value->left = node;
  node->parent = value;
}

template <typename Key>
void RedBlackTree<Key>::rightRotate(treeNode node) {
  treeNode value = node->left;
  node->left = value->right;
  if (value->right != nil) {
    value->right->parent = node;
  }
  value->parent = node->parent;
  if (value->parent == nullptr) {
    this->root = value;
  } else if (node == node->parent->right) {
    node->parent->right = value;
  } else {
    node->parent->left = value;
  }
  value->right = node;
  node->parent = value;
}

// For deveop

template <typename Key>
typename RedBlackTree<Key>::treeNode RedBlackTree<Key>::getRoot() {
  return root;
}

template <typename Key>
typename RedBlackTree<Key>::treeNode RedBlackTree<Key>::getChild(
    treeNode node) {
  return node->left == nil ? node->right : node->left;
}

template <typename Key>
typename RedBlackTree<Key>::Node *RedBlackTree<Key>::createNil() {
  nil = new Node;
  nil->color = false;
  nil->parent = nullptr;
  nil->left = nullptr;
  nil->right = nullptr;
  return nil;
}

template <typename Key>
int RedBlackTree<Key>::getChildrenCount(treeNode node) {
  int count = 0;
  if (node->right != nil) {
    count += 1;
  }
  if (node->left != nil) {
    count += 1;
  }
  return count;
}

template <typename Key>
void RedBlackTree<Key>::clearTree(treeNode node) {
  if (node != nil) {
    clearTree(node->left);
    clearTree(node->right);
    delete node;
  }
}

template <typename Key>
void RedBlackTree<Key>::printTree(treeNode root, int depth) {
  const int SPACING = 4;
  if (root != nil && root != nullptr) {
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth * SPACING; ++i) {
      std::cout << " ";
    }
    std::cout << root->data << " (" << (root->color ? "Red" : "Black") << ")"
         << std::endl;
    printTree(root->left, depth + 1);
  }
}

template <typename Key>
void RedBlackTree<Key>::moving(treeNode toNode, treeNode fromNode) {
  if (toNode == nil || toNode == this->root) {
    this->root = fromNode;
  } else if (toNode == toNode->parent->right) {
    toNode->parent->right = fromNode;
  } else {
    toNode->parent->left = fromNode;
  }
  fromNode->parent = toNode->parent;
}

}  // namespace s21
