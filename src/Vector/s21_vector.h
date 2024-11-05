#ifndef CPP2_CONTAINERS_3_SRC_VECTOR_VECTOR_H_
#define CPP2_CONTAINERS_3_SRC_VECTOR_VECTOR_H_

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {

template <typename T>
class Vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 public:
  Vector() : size_(0), capacity_(0), arr_(nullptr) {}

  explicit Vector(size_type n)
      : size_(n), capacity_(n), arr_(n ? new value_type[n]() : nullptr) {}

  Vector(std::initializer_list<value_type> const &items);
  Vector(const Vector &v);
  Vector(Vector &&v) : size_(v.size_), capacity_(v.capacity_), arr_(v.arr_){};

  ~Vector() {
    if (this->arr_) {
      delete[] this->arr_;
    }
  }

  Vector &operator=(Vector &v);
  Vector &operator=(Vector &&v);

  // Accsess

  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;

  reference front() {
    return this->empty() ? throw std::out_of_range("Out of range") : arr_[0];
  }
  const_reference front() const {
    return this->empty() ? throw std::out_of_range("Out of range") : arr_[0];
  }

  reference back();

  const_reference back() const {
    return this->empty() ? std::out_of_range("Out of range") : arr_[size_ - 1];
  }

  T *data() { return arr_; }  //++

  // iterators

  iterator begin() noexcept { return arr_; }
  iterator end() noexcept { return arr_ + size_; }
  const_iterator begin() const noexcept { return arr_; }
  const_iterator end() const noexcept { return arr_ + size_; }
  reference operator++() { return *(++arr_); }
  reference operator--() { return *(--arr_); }
  const_reference operator++(int) { return *(arr_++); }
  const_reference operator--(int) { return *(arr_--); }
  const_reference operator+(int i) { return *(arr_ + i); }
  const_reference operator-(int i) { return *(arr_ - i); }
  bool operator==(const iterator &it) { return arr_ == it; }
  bool operator!=(const iterator &it) { return arr_ != it; }

  // capacity

 public:
  bool empty() const { return size_ != 0 ? false : true; }
  size_type size() const { return size_; };
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const { return capacity_; }
  void shrink_to_fit();

  // Modifier

  void clear() noexcept;
  iterator insert(iterator pos, const_reference &value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(Vector &other);

 private:
  size_type size_;
  size_type capacity_;
  T *arr_;
};

}  // namespace s21

#include "s21_vector.tpp"

#endif  // CPP2_CONTAINERS_3_SRC_VECTOR_VECTOR_H
