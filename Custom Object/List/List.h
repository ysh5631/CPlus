#ifndef ASSIGMENT_LIST_H
#define ASSIGMENT_LIST_H
#include <iostream>
#include <array>
#include <algorithm>
#include <optional>
#include <cassert>

template<typename T, size_t N>
class List {
public:
    void add(const T& t) {
        _data[_cur_pos] = t;
        _cur_pos += 1;
    }
    std::optional<T> find(const T& t) const {
        for(int i=0; i<_cur_pos; i++){
            if(_data[i] == t)
                return t;
        }
        return {};
    }
    std::optional<T> remove(const T& t) {
        for(int i=0;i<_cur_pos;i++){
            if(_data[i] == t){
                for(int j=i;j<_cur_pos-1;j++){
                    _data[j] = _data[j+1];
                }
                _cur_pos -= 1;
            }
        }
        T r;
        for(int i=_cur_pos;i<N;i++)
            _data[i] = r;
        return t;
    }
    T* begin() { return _data.begin(); }
    T* end() { return _data.end(); }
    size_t size() const { return _data.size(); }

private:
    int _cur_pos = 0;
    std::array<T, N> _data;
};


#endif //ASSIGMENT_LIST_H
