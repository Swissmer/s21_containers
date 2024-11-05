
namespace s21 {

template <class T>
inline s21::List<T>::List() : list_size_(0) {
  carbin_ = new Node(value_type{});
  base_list();
}

template <class T>
inline s21::List<T>::List(size_t n) : List() {
  while (n > 0) {
    push_back(value_type{});
    --n;
  }
}

template <class T>
inline s21::List<T>::List(const std::initializer_list<T> &items) : List() {
  for (const_reference i : items) push_back(i);
}

template <class T>
inline s21::List<T>::List(const s21::List<T> &l) : List() {
  if (!l.empty())
    for (iterator i = l.begin(); i != l.end(); i++) push_back(*i);
}

template <class T>
inline s21::List<T>::List(s21::List<T> &&l) : List() {
  if (!l.empty()) {
    swap(l);
  }
}

template <typename T>
s21::List<T>::~List() {
  clear();
  delete carbin_;
}

template <class T>
inline s21::List<T> &s21::List<T>::operator=(const s21::List<T> &l) {
  if (this != &l) {
    clear();
    if (!l.empty())
      for (iterator i = l.begin(); i != l.end(); i++) push_back(*i);
  }
  return *this;
}

template <class T>
inline s21::List<T> &s21::List<T>::operator=(s21::List<T> &&l) noexcept {
  if (this != &l && !l.empty()) {
    clear();
    swap(l);
  } else {
    //   undefined behavior при this = &l
    clear();
  }
  return *this;
}

template <class T>
inline s21::List<T> &s21::List<T>::operator=(
    const std::initializer_list<T> &items) {
  clear();
  for (const_reference i : items) push_back(i);
  return *this;
}

// List Iterators

template <typename T>
typename s21::List<T>::iterator s21::List<T>::begin() noexcept {
  iterator it;
  it.current_ = head_ ? head_ : carbin_;
  return it;
}

template <class T>
inline typename s21::List<T>::const_iterator s21::List<T>::begin()
    const noexcept {
  const_iterator it;
  it.current_ = head_ ? head_ : carbin_;
  return it;
}

// List Modifiers

template <class T>
inline void s21::List<T>::clear() {
  while (!empty()) pop_back();
}

template <class T>
inline typename s21::List<T>::iterator s21::List<T>::insert(
    s21::List<T>::iterator pos, const T &value) {
  Node *inserted_node = new Node(value);
  inserted_node->prev_ = pos.current_->prev_;
  inserted_node->prev_->next_ = inserted_node;
  inserted_node->next_ = pos.current_;
  inserted_node->next_->prev_ = inserted_node;
  head_ = carbin_->next_;
  tail_ = carbin_->prev_;
  ++list_size_;
  return iterator(inserted_node);
}

template <class T>
template <typename... Args>
inline typename s21::List<T>::iterator s21::List<T>::insert_many(
    s21::List<T>::const_iterator pos, Args &&...args) {
  iterator it = pos;
  ((it = insert(it, std::forward<Args>(args))), ...);
  return it;
}

template <class T>
template <typename... Args>
inline void s21::List<T>::insert_many_back(Args &&...args) {
  ((push_back(std::forward<Args>(args))), ...);
}

template <class T>
template <typename... Args>
inline void s21::List<T>::insert_many_front(Args &&...args) {
  ((push_front(std::forward<Args>(args))), ...);
}

template <class T>
inline void s21::List<T>::erase(s21::List<T>::iterator pos) {
  if (pos.current_ != carbin_) {
    pos.current_->prev_->next_ = pos.current_->next_;
    pos.current_->next_->prev_ = pos.current_->prev_;
    --list_size_;
    delete pos.current_;
    head_ = carbin_->next_;
    tail_ = carbin_->prev_;
  }
}

template <class T>
inline void s21::List<T>::swap(s21::List<T> &other) noexcept {
  if (this != &other) {
    std::swap(list_size_, other.list_size_);
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(carbin_, other.carbin_);
  }
}

template <class T>
inline void s21::List<T>::merge(s21::List<T> &other) {
  if (this == &other || other.empty()) return;
  iterator it1 = begin();
  iterator it2 = other.begin();
  while (it1 != end() && it2 != other.end()) {
    if (*it2 < *it1) {
      insert(it1, *it2);
      ++it2;
    } else {
      ++it1;
    }
  }
  while (it2 != other.end()) {
    insert(it1, *it2);
    ++it2;
  }
  other.clear();
}

template <class T>
void s21::List<T>::splice(s21::List<T>::const_iterator pos,
                          s21::List<T> &other) {
  iterator it = other.begin();
  for (size_t i = 0; i < other.size(); ++i) {
    insert(pos, *it);
    ++it;
  }
  other.clear();
}

template <class T>
inline void s21::List<T>::reverse() {
  if (size() < 2 || unique_list()) return;
  List<T> rlist;
  Node *i = carbin_->prev_;
  iterator r_it = rlist.end();
  while (i != carbin_) {
    rlist.insert(r_it, i->value_);
    i = i->prev_;
  }
  clear();
  *this = rlist;
  head_ = carbin_->next_;
  tail_ = carbin_->prev_;
}

template <class T>
inline void s21::List<T>::unique() {
  if (size() < 2) return;
  iterator tmp = begin();
  while (tmp.current_->next_ != carbin_) {
    iterator it = tmp++;
    if (*it == it.current_->next_->value_) {
      erase(it);
    }
  }
  head_ = carbin_->next_;
  tail_ = carbin_->prev_;
}

template <class T>
void s21::List<T>::sort() {
  if (size() < 2) return;
  for (Node *i = tail_; i != carbin_; i = i->prev_) {
    for (Node *j = head_; j != i; j = j->next_) {
      if (j->value_ > j->next_->value_) {
        value_type tmp_val = j->value_;
        j->value_ = j->next_->value_;
        j->next_->value_ = tmp_val;
      }
    }
  }
}

// ListIterator

template <class T>
inline typename s21::List<T>::ListIterator &
s21::List<T>::ListIterator::operator++() noexcept {
  current_ = current_->next_;
  return *this;
}

template <class T>
inline typename s21::List<T>::ListIterator &
s21::List<T>::ListIterator::operator--() noexcept {
  current_ = current_->prev_;
  return *this;
}

template <class T>
inline typename s21::List<T>::ListIterator
s21::List<T>::ListIterator::operator++(int) {
  iterator it = iterator(current_);
  current_ = current_->next_;
  return it;
}

template <class T>
inline typename s21::List<T>::ListIterator
s21::List<T>::ListIterator::operator--(int) {
  iterator it = iterator(current_);
  current_ = current_->prev_;
  return it;
}

template <class T>
inline bool s21::List<T>::ListIterator::operator==(
    s21::List<T>::ListIterator other) noexcept {
  return current_ == other.current_;
}

template <class T>
inline bool s21::List<T>::ListIterator::operator!=(
    s21::List<T>::ListIterator other) noexcept {
  return current_ != other.current_;
}

// For develop

template <class T>
inline void s21::List<T>::print() const {
  std::cout << "[";
  for (const_iterator it = begin(); it != end(); ++it) {
    std::cout << *it;
    if (it != --end()) {
      std::cout << ", ";
    }
  }
  std::cout << "]\n";
}

// Methods not available

template <class T>
inline void s21::List<T>::base_list() noexcept {
  list_size_ = 0;
  head_ = nullptr;
  tail_ = nullptr;
  carbin_->next_ = carbin_;
  carbin_->prev_ = carbin_;
}

template <class T>
inline bool s21::List<T>::unique_list() {
  List<T> uno = *this;
  uno.unique();
  return uno.list_size_ == 1;
}

}  // namespace s21