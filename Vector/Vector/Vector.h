//
//  Vector.h
//  Vector
//
//  Created by Adam Saher on 16/01/2019.
//  Copyright © 2019 Adam Saher. All rights reserved.
//

//
//  Vector.h
//  Vector
//
//  Created by Adam Saher on 19/12/2018.
//  Copyright © 2018 Adam Saher. All rights reserved.
//

#ifndef Vector_h
#define Vector_h

namespace Container {
    template <typename T>
    class Vector {
        T* vector_;
        size_t size_;
        size_t capacity_;
    public:
        Vector();
        Vector(size_t);
        Vector(std::initializer_list<T>);
        ~Vector();
        Vector(const Vector&);
        const Vector& operator=(const Vector&);  //can't moidfy return value.
        Vector(Vector&&);
        const Vector& operator=(Vector&&);
        std::ostream& display(std::ostream&) const;
        T& operator[](size_t i) {return vector_[i];};
        T* data();
        void assign(size_t len, T value);
    };
    
    
    template <typename T>
    Vector<T>::Vector() {
        vector_ = nullptr;
        capacity_ = 0;
        size_ = 0;
    }
    
    
    template <typename T>
    Vector<T>::Vector(size_t capacity) {
        vector_ = new T[capacity];
        capacity_ = capacity;
        size_ = 0;
    }
    
    
    template <typename T>
    Vector<T>::Vector(std::initializer_list<T> lst) {
        size_ = lst.size();
        capacity_ = lst.size() * 2;
        vector_ = new T[capacity_];
        size_t i = 0u;
        for (auto& element : lst)
            vector_[i++] = element;
    }
    
    
    template <typename T>
    Vector<T>::~Vector() {
        delete[] vector_;
    }
    
    
    template <typename T>
    Vector<T>::Vector(const Vector& src) {
        vector_ = nullptr;
        *this = src;
    }
    
    
    template <typename T>
    const Vector<T>& Vector<T>::operator=(const Vector<T> & src) {
        if (this != &src) {
            delete[] vector_;
            size_ = src.size_;
            vector_ = new T[capacity_];
            
            for (size_t i = 0; i < size_; ++i)
                vector_[i] = src.vector_[i];
        }
        return *this;
    }
    
    
    template <typename T>
    Vector<T>::Vector(Vector<T>&& src) {
        vector_ = src.vector_;
        capacity_ = src.capacity_;
        size_ = src.size;
        
        src.vector_ = nullptr;
        src.capacity_ = 0;
        src.size_ = 0;
    }
    
    
    template <typename T>
    const Vector<T>& Vector<T>::operator=(Vector<T>&& src) {
        std::swap(src.vector_, vector_);
        std::swap(capacity_, src.capacity_);
        std::swap(size_, src.size_);
        return *this;
    }
    
    
    template <typename T>
    std::ostream& Vector<T>::display(std::ostream& os) const {
        os << '[';
        for (auto i = 0u; i < size_ - 1; ++i)
            os << vector_[i] << ", ";
        return os << vector_[size_ - 1] << ']';
    }
    
    
    template <typename T>
    void Vector<T>::assign(size_t len, T value) {
        delete[] vector_;
        size_ = len;
        vector_ = new T[size_];
        for (size_t i = 0; i < size_; ++i)
            vector_[i] = value;
    }
    
    
    template <typename T>
    T* Vector<T>::data() {
        return vector_;
    }
    
    template <typename T>
    std::ostream& operator<<(std::ostream& os, Vector<T>& v) {
        v.display(os);
        return os;
    }
}


#endif /* Vector_h */

