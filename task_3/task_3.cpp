#include <iostream>
#include <stdexcept>

template<typename T>
class MyVector {
public:
    MyVector() {
        _arr = new T[_capacity];
    }
    
    ~MyVector() {
        delete[] _arr;
    }
    T at(const int index) const {
        if (index >= 0 && index < _size) {
            return _arr[index];
        }
        else {
            throw std::runtime_error("Out of range!");
        }
    }
    int size() const {
        return _size;
    }

    int capacity() const {
        return _capacity;
    }

    void push_back(const T& val) {
        if (_capacity <= _size) {
            _capacity *= 2;
            T* new_arr = new T[_capacity];
            for (int i = 0; i <= _size; ++i) {
                new_arr[i] = _arr[i];
            }
            delete[] _arr;
            _arr = new_arr;
        }
        _arr[_size++] = val;
    }

private:
    int _capacity{ 10 };
    int _size{ 0 };
    T* _arr{ nullptr };
};



int main()
{
    MyVector<int> myvector;
    for (int i = 0; i < 100; ++i) {
        myvector.push_back(i);
    }

    try {
        for (int i = 0; i < 101; ++i) {
            std::cout << "myvector.at(" << i << ") = " << myvector.at(i) << std::endl;
        }
    }
    catch (std::runtime_error& ex) {
        std::cout << ex.what() << std::endl;
    }
}
