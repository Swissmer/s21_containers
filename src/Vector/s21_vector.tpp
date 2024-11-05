#include "s21_vector.h"

namespace s21 {

template <typename T>
Vector<T>::Vector(std::initializer_list<value_type> const &items) {
  size_ = items.size();
  capacity_ = items.size();
  arr_ = new value_type[capacity_];
  std::copy(items.begin(), items.end(), arr_);
}

template <typename T>
Vector<T>::Vector(const Vector &v) {
  {
    this->size_ = v.size_;
    this->capacity_ = v.capacity_;
    this->arr_ = new value_type[this->size_];
    for (size_type i = 0; i < this->size_; i++) {
      this->arr_[i] = v.arr_[i];
    }
  }
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &v) {
  capacity_ = v.capacity_;
  size_ = v.size_;
  try {
    arr_ = new T[size_]();
  } catch (std::exception &err) {
    std::cerr << err.what() << std::endl;
  }
  for (size_t i = 0; i != size_; ++i) {
    arr_[i] = v.arr_[i];
  }
  return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&v) {
  this->swap(v);
  return *this;
}

template <typename T>
typename Vector<T>::reference Vector<T>::at(size_type pos) {
  return (pos >= this->size_) ? throw std::out_of_range(" error")
                              : this->arr_[pos];
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::at(size_type pos) const {
  if (pos >= size_) throw std::out_of_range("error");
  return arr_[pos];
}

template <typename T>
typename Vector<T>::reference Vector<T>::operator[](size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range(" bad index");
  }

  return arr_[pos];
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::operator[](size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("bad index");
  }

  return arr_[pos];
}

template <typename T>
typename Vector<T>::size_type Vector<T>::max_size() const {
  return (std::numeric_limits<size_type>::max() / sizeof(value_type) / 2);
}

template <typename T>
void Vector<T>::reserve(size_type size) {
  if (size > max_size()) {
    throw std::length_error("error_max_size");
  }
  if (size > size_) {
    value_type *newArray = new value_type[size];
    for (size_type i = 0; i < size_; ++i) {
      newArray[i] = std::move(arr_[i]);
    }
    delete[] arr_;
    arr_ = newArray;
    capacity_ = size;
  }
}

template <typename T>
void Vector<T>::shrink_to_fit() {
  if (capacity_ > size_) {
    value_type *newArray = new value_type[size_];
    for (size_type i = 0; i < size_; ++i) {
      newArray[i] = std::move(arr_[i]);
    }
    delete[] arr_;
    arr_ = newArray;
    capacity_ = size_;
  }
}

template <typename T>
void Vector<T>::clear() noexcept {
  size_ = 0;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::insert(iterator pos,
                                               const_reference &value) {
  size_type idx = pos - begin();
  size_type newCapacity;
  if (size_ == capacity_) {
    newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
    reserve(newCapacity);
  }

  if (idx < size_) {
    for (size_type i = size_; i > idx; --i) {
      arr_[i] = arr_[i - 1];
    }
  }

  arr_[idx] = value;
  ++size_;

  return begin() + idx;
}

template <typename T>
void Vector<T>::erase(iterator pos) {
  if (pos >= begin() && pos < end()) {
    size_type idx = pos - begin();

    for (size_type i = idx; i < size_ - 1; ++i) {
      arr_[i] = arr_[i + 1];
    }

    --size_;
  }
}

template <typename T>
typename Vector<T>::reference Vector<T>::back() {
  if (!size_) {
    throw std::out_of_range("BackError: Vector is empty");
  }

  return arr_[size_ - 1];
}

template <typename T>
void Vector<T>::push_back(const_reference value) {
  if (size_ == capacity_) {
    size_type newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
    reserve(newCapacity);
  }
  arr_[size_] = value;
  ++size_;
}

template <typename T>
void Vector<T>::pop_back() {
  if (!empty()) {
    size_--;
  }
}

template <typename T>
void Vector<T>::swap(Vector<T> &v) {
  std::swap(this->size_, v.size_);
  std::swap(this->capacity_, v.capacity_);
  std::swap(this->arr_, v.arr_);
}
}  // namespace s21
