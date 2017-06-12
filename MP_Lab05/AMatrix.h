#pragma once
#include "Utils.h"
#include <vector>
#include <ostream>

template <class T>
class AMatrix {
private:
	T** _arr;
	unsigned int _width;
	unsigned int _height;
	void Clear() {
		for (unsigned int i = 0; i < GetWidth(); i++) {
			delete[] _arr[i];
		}
		delete[] _arr;
	}
	void Init(unsigned int width, unsigned int height) {
		_width = width;
		_height = height;
		_arr = new T*[GetWidth()];
		for (unsigned int i = 0; i < GetWidth(); i++) {
			_arr[i] = new T[GetHeight()];
		}
	}
public:
	AMatrix(unsigned int width, unsigned int height, T defaultValue) : AMatrix(width, height) {
		for (unsigned int i = 0; i < GetWidth(); i++) {
			for (unsigned int j = 0; j < GetHeight(); j++) {
				Set(i, j, defaultValue);
			}
		}
	}
	AMatrix(unsigned int width, unsigned int height) {
		Init(width, height);
	}
	AMatrix(unsigned int width, unsigned int height, std::vector<T> values) : AMatrix(width, height) {
		for (unsigned int i = 0; i < GetWidth(); i++) {
			for (unsigned int j = 0; j < GetHeight(); j++) {
				Set(i, j, values[(i * GetHeight() + j) % values.size()]);
			}
		}
	}
	AMatrix() : AMatrix(1, 1) {

	}
	~AMatrix() {
		Clear();
	}
	AMatrix(AMatrix<T>& copy) {
		this = copy;
	}
	unsigned int GetWidth() {
		return _width;
	}
	unsigned int GetHeight() {
		return _height;
	}
	void Set(unsigned int x, unsigned int y, T value) {
		_arr[x][y] = value;
	}
	T Get(unsigned int x, unsigned int y) {
		return _arr[x][y];
	}
	AMatrix<T>& operator = (AMatrix<T>& copy) {
		Clear();
		Init(copy.GetWidth(), copy.GetHeight());
		for (unsigned int i = 0; i < GetWidth(); i++) {
			for (unsigned int j = 0; j < GetHeight(); j++) {
				Set(i, j, copy.Get(i, j));
			}
		}
		return *this;
	}
	friend std::ostream& operator << (std::ostream& out, AMatrix& m) {
		for (unsigned int i = 0; i < m.GetWidth(); i++) {
			for (unsigned int j = 0; j < m.GetHeight(); j++) {
				out << m.Get(i, j) << " ";
			}
			out << std::endl;
		}
		return out;
	}
};
