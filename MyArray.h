#pragma once
#include <iostream>
#include <cassert>

template<typename T>
class MyArray{
  private:
    T *data;
    int capacity;
    int size;
    void grow();
  public:
    MyArray();
    MyArray(int cap);
    int getSize()const;
    int getCap()const;
    int getIndex(const T value)const;
    void push_back(T value);
    void erase(const int index);
    T& operator[](int index);
    const T& operator[](int index) const;
    MyArray(const MyArray &ma); // copy constructor
    MyArray& operator=(const MyArray &ma); // assignment operator overload
    ~MyArray(); // destructor

  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const MyArray<U>& ma);
};

template<typename T>
MyArray<T>:: MyArray():MyArray(10){}

template<typename T>
MyArray<T>:: MyArray(int cap):size(0){
    assert(cap >0);
    capacity=cap;
    data = new T[capacity]{};
}

template<typename T>
int MyArray<T>::getSize()const{return size;}

template<typename T>
int MyArray<T>::getCap()const{return capacity;}

template<typename T>
void MyArray<T>:: grow(){
    capacity = (capacity*2)+1;
    T *newArray = new T[capacity]{};
    for(int i =0; i <size; i++){
        newArray[i] = data[i];
    }
    delete [] data;
    data = newArray;
}

template<typename T>
int MyArray<T>::getIndex(const T value)const{
    for(int i =0;i <size; i++){
        if( data[i] == value){
            return i;
        }
    }
    return -1;

}

template <typename T>
void MyArray<T>::push_back(T value) {
    if(size==capacity){
        grow();
    }
    data[size] = value;
    size++;
}

template <typename T>
void MyArray<T>::erase(const int index){
    for(int i=index; i<size-1; i++){
  	    data[i] = data[i+1];
    }

    size--; 
}

template <typename T>
T& MyArray<T>::operator[](int index) {
    assert(index >=0 && index < size);
    return data[index];
}
template <typename T>
const T& MyArray<T>::operator[](int index) const {
    assert(index >=0 && index < size);
    return data[index];
}

template <typename T>
MyArray<T>::MyArray(const MyArray &ma):
    capacity(ma.capacity),
    size(ma.capacity),
    data(new T[ma.capacity]{} ){
    for(int i =0; i<ma.size; i++){
        data[i] = ma.data[i];
    }
}

template <typename T>
MyArray<T>& MyArray<T>::operator=(const MyArray &ma){
    if(this != &ma){
        if(capacity != ma.capacity){
            capacity = ma.capacity;
            delete [] data;
            data = new T[capacity];
        }
        size = ma.size;
        for(int i =0; i <size; i++){
            data[i] = ma.data[i];
        }
    }
    return *this;
}

template <typename T>
MyArray<T>::~MyArray(){
    delete [] data;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const MyArray<T>& ma)
{
    for(int i=0; i<ma.getSize();i++) {
        os << i << " " << ma[i] << " ";
    }
    os << "\n";

    return os;
}