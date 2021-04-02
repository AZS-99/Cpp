//
//  vector.h
//  Vector
//
//  Created by Adam Saher on 2021-03-25.
//

#ifndef vector_h
#define vector_h

#include "const_iterator.h"


template <typename T>
class Vector {
    T* data_;
    unsigned size_;
    unsigned capacity_;
    void expand();
    
public:
    Vector();
    Vector(const unsigned&);
    Vector(const Vector&);
    Vector(Vector&&);
    Vector& operator=(const Vector&);
    Vector& operator=(Vector&&);
    bool operator==(const Vector&);
    T& operator[](const unsigned&) const;
    const T* data() const;
    const unsigned& capacity() const;
    const unsigned& size() const;
    T& back() const;
    T& front() const;
    bool empty() const;
    const_iterator<T> cbegin() const;
    const_iterator<T> cend() const;
    void clear();
    void push_back(const T&);
    void pop_back(const T&);
    void shrink_to_fit();
    friend std::ostream& operator<<(std::ostream&, const Vector&);
    std::ostream& print(std::ostream&) const;
};


template <typename T>
Vector<T>::Vector() {
    data_ = nullptr;
    size_ = capacity_ = 0u;
}


template <typename T>
Vector<T>::Vector(const unsigned& size) {
    data_ = new T[size]();
    this->size_ = size;
    capacity_ = size;
}


template <typename T>
Vector<T>::Vector(const Vector& src) {
    std::cout << "Copy Contructor" << std::endl;
    data_ = new T[src.capacity_];
    std::copy(src.data_, src.data_ + src.size_, data_);
    size_ = src.size_;
    capacity_ = src.capacity_;
}


template <typename T>
Vector<T>::Vector(Vector&& vec) {
    data_ = vec.array;
    size_ = vec.size;
    capacity_ = vec.capacity;
    vec.array = nullptr;
}


template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& src) {
    delete[] data_;
    data_ = new T[src.capacity_];
    for (auto i = 0u; i < size_; ++i)
        data_[i] = src.data_[i];
    size_ = src.size_;
    capacity_ = src.capacity_;
}


template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& src) {
    std::swap(data_, src.data_);
    std::swap(size_, src.size_);
    std::swap(capacity_, capacity_);
    return *this;
}


template <typename T>
bool Vector<T>::operator==(const Vector<T>& other) {
    for (auto i = 0u; i < size_; ++i) {
        if (data_[i] != other.data_[i])
            return false;
    }
    return true;
}


template <typename T>
T& Vector<T>::operator[](const unsigned& index) const {
    return data_[index];
}


template <typename T>
const T* Vector<T>::data() const {
    return data_;
}


template <typename T>
const unsigned& Vector<T>::capacity() const {
    return capacity_;
}


template <typename T>
const unsigned& Vector<T>::size() const {
    return size_;
}


template <typename T>
T& Vector<T>::back() const {
    return data_[size_ - 1];
}


template <typename T>
T& Vector<T>::front() const {
    return *data_;
}


template <typename T>
bool Vector<T>::empty() const {
    return size_ == 0u;
}


template <typename T>
void Vector<T>::clear() {
    size_ = 0u;
}


template <typename T>
void Vector<T>::push_back(const T& element) {
    if (capacity_ == size_)
        expand();
    data_[size_++] = element;
}


template <typename T>
void Vector<T>::expand() {
    capacity_ *= 2;
    auto tmp = new T[capacity_];
    for (auto i = 0u; i < size_; ++i)
        tmp[i] = data_[i];
    delete[] data_;
    data_ = tmp;
}


template <typename T>
void Vector<T>::pop_back(const T& element) {
    --size_;
}


template <typename T>
const_iterator<T> Vector<T>::cbegin() const {
    return const_iterator<T>(data_, this);
}


template <typename T>
const_iterator<T> Vector<T>::cend() const {
    return const_iterator<T>(data_ + size_, this);
}


template <typename T>
void Vector<T>::shrink_to_fit() {
    capacity_ = size_;
    auto tmp = new T[size_];
    std::copy(data_, data_ + size_, tmp);
    delete[] data_;
    data_ = tmp;
}


template <typename T>
std::ostream& Vector<T>::print(std::ostream& os) const {
    os << '[';
    for (auto i = 0u; i < size_ - 1; ++i)
        os << data_[i] << ", ";
    return os << data_[size_ - 1] << ']';
}


template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vector) {
    os << '[';
    for (auto i = 0u; i < vector.size_ - 1; ++i)
        os << vector.data_[i] << ", ";
    return os << vector.data_[vector.size_ - 1] << ']';
}

#endif /* vector_h */
