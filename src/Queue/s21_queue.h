#ifndef CPP2_CONTAINERS_SRC_QUEUE_S21_QUEUE_H_
#define CPP2_CONTAINERS_SRC_QUEUE_S21_QUEUE_H_

#include "../List/s21_list.h"

namespace s21 {

template <typename T, class Container = s21::List<T>>
class Queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  Queue() : qlist_() {}

  Queue(std::initializer_list<value_type> const &items) : qlist_(items) {}

  Queue(const Queue &q) : qlist_(q.qlist_) {}

  Queue(Queue &&q) : qlist_(std::move(q.qlist_)) {}

  ~Queue() {}

  Queue operator=(Queue &&q) {
    qlist_.clear();
    qlist_.swap(q);
  }

  bool operator==(Queue &q) { return *this == q; }

  const_reference front() { return qlist_.front(); }
  const_reference back() { return qlist_.back(); }

  bool empty() { return qlist_.empty(); }

  size_type size() { return qlist_.size(); }

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    ((qlist_.push_back(std::forward<Args>(args))), ...);
  }

  void push(const_reference value) { qlist_.push_back(value); }

  void pop() { qlist_.pop_front(); }

  void swap(Queue &other) { qlist_.swap(other); }

 private:
  Container qlist_;
};
}  // namespace s21

#endif  // CPP2_CONTAINERS_SRC_QUEUE_S21_QUEUE_H_