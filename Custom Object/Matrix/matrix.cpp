#include "matrix.h"
#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
using namespace std;

matrix::matrix(size_t row, size_t col) noexcept {
    // 이중 벡터는 이런식으로 선언해야한다.(row, col) 크기의 벡터 생성됨
    this->_data = vector<vector<int>>(row,vector<int>(col));
}

matrix::matrix(std::initializer_list<std::initializer_list<int>> rows) {
    // 여기서 시간 많이 썼다.
    // initializer_list에 접근하려는것은 최대한 안하는게 좋을 것 같다. 계속 저장이안되더라.
    for(auto& r : rows)
        _data.push_back(r);
}

matrix matrix::operator+(const matrix &rhs) const {
    //col의 크기는 맨처음엔 _data.begin()->size() 이런식으로 했었는데 직관적으로 바꿨음.
    int rowL = _data.size(); int colL = _data.at(0).size();
    int rowR = rhs._data.size(); int colR = rhs._data.at(0).size();
    //if(rowL == rowR && colL == colR)
    matrix result(rowL,colL);
    for(int i=0;i<rowL;i++){
        for(int j=0;j<colL;j++)
            result._data[i][j] = _data[i][j] + rhs._data[i][j];
    }
    return result;
}

matrix matrix::operator-(const matrix &rhs) const {
    int rowL = _data.size(); int colL = _data.at(0).size();
    int rowR = rhs._data.size(); int colR = rhs._data.at(0).size();
    //if(rowL == rowR && colL == colR)
    matrix result(rowL,colL);
    for(int i=0;i<rowL;i++){
        for(int j=0;j<colL;j++)
            result._data[i][j] = _data[i][j] - rhs._data[i][j];
    }
    return result;
}

bool matrix::operator==(const matrix &rhs) const {
    int rowL = _data.size(); int colL = _data.at(0).size();
    int rowR = rhs._data.size(); int colR = rhs._data.at(0).size();
    auto startL = _data.begin(); auto startR = rhs._data.begin();
    auto endL = _data.end();
    if(rowL == rowR && colL == colR) {
        for (int i = 0; i < rowL; i++) {
            return equal(startL, endL, startR);
        }
        return true;
    }
    return false;
}

bool matrix::operator!=(const matrix &rhs) const {
    return !(this->operator==(rhs));
}

pair<size_t, size_t> matrix::size() const {
    pair<size_t, size_t> sz = {_data.size(),_data.at(0).size()};
    return sz;
}

matrix matrix::transpose() {
    int row = _data.size(); int col = _data.at(0).size();
    matrix result(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            result._data[i][j] = _data[j][i];
        }
    }
    return result;
}

ostream& operator << (ostream& os, const matrix& m){
    int row = m._data.size(); int col = m._data.at(0).size();
    for(int i=0;i<row;i++){
        os << "|\t";
        for(int j=0;j<col;j++){
            os << m._data[i][j] << "\t";
        }
        os << "|" << endl;
    }
    return os;
}

