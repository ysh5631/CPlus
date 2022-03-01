#ifndef ASSIGMENT_MY_VECTOR_H
#define ASSIGMENT_MY_VECTOR_H
#include "my_vector_iterator.h"
#include <algorithm>
#include <initializer_list>
#include <memory>
#include <cassert>
#include <cstddef>
using namespace std;

template<typename T>
class my_vector {
public:
    explicit my_vector(size_t N=0) noexcept {
        _size = N;
    }
    my_vector(std::initializer_list<int> lst) noexcept{
        _data = make_unique<int[]>(lst.size());
        _size = lst.size();
        int idx = 0;
        for(auto& l : lst)
            _data[idx++] = l;
    }
    my_vector(const my_vector<T>& other) noexcept{
        _size = other._size;
        _data = make_unique<T[]>(other.size());
        for(int i=0;i<_size;i++)
            _data[i] = other._data[i];
    }
    T& operator[](int i){
        assert(i >=0 && i < _size);
        return _data[i];
    }
    size_t size() const {
        return _size;
    }
    my_vector_iterator<T> begin(){
        return my_vector_iterator<T>(_data.get());
    }

    my_vector_iterator<T> end(){
        return my_vector_iterator<T>(_data.get()+_size);
    }
private:
    size_t _size;
    std::unique_ptr<T[]> _data;
};

#endif //ASSIGMENT_MY_VECTOR_H
