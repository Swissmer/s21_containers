#ifndef CPP2_CONTAINERS_SRC_STACK_S21_STACK_H_
#define CPP2_CONTAINERS_SRC_STACK_S21_STACK_H_

#include "../Vector/s21_vector.h"

namespace s21 {
template <class T, class Parent = s21::Vector<T>>
class Stack {
 public:
  //  типы членов класса
  using pointer = T *;
  using value_type = typename Parent::value_type;
  using reference = typename Parent::reference;
  using const_reference = typename Parent::const_reference;
  using size_type = typename Parent::size_type;

  //  stack Member functions
  Stack() : stack_() {}
  Stack(std::initializer_list<value_type> const &items) : stack_(items) {}
  Stack(const Stack &s) : stack_(s.stack_) {}
  Stack(Stack &&s) : stack_(stack_(s.stack_)) {}
  ~Stack() {}

  Stack &operator=(Stack &&s) {
    this->stack_ = std::move(s.stack_);
    return *this;
  }

  // stack Element access
  const_reference top() { return stack_.back(); }

  // stack Capacity
  bool empty() { return stack_.empty(); }
  size_type size() { return stack_.size(); }

  // Stack Modifiers
  void push(const_reference value) { this->stack_.push_back(value); }
  void pop() { this->stack_.pop_back(); }
  void swap(Stack &other) { this->stack_.swap(other.stack_); }

 private:
  Parent stack_;
};

}  //  namespace s21

#endif  // CPP2_CONTAINERS_SRC_STACK_S21_STACK_H_
