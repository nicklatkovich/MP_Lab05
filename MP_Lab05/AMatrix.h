#pragma once

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
		_width = copy.GetWidth();
		_height = copy.GetHeight();
		_arr = new T*[GetWidth()];
		for (unsigned int i = 0; i < GetWidth(); i++) {
			_arr = new T[GetHeight()];
		}
	}
public:
	AMatrix(unsigned int width, unsigned int height, T defaultValue = default(T)) {
		Init(width, height);
		for (unsigned int i = 0; i < GetWidth(); i++) {
			for (unsigned int j = 0; j < GetHeight(); j++) {
				Set(i, j, defaultValue);
			}
		}
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
	}
};
