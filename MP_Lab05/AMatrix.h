#pragma once

template <class T>
class AMatrix {
private:
	T** _arr;
	unsigned int _width;
	unsigned int _height;
public:
	AMatrix(unsigned int width, unsigned int height, T defaultValue = default(T)) {
		_width = width;
		_height = height;
		_arr = new T*[GetWidth()];
		for (unsigned int i = 0; i < GetWidth(); i++) {
			_arr = new T[GetHeight()];
			for (unsigned int j = 0; j < GetHeight(); j++) {
				Set(i, j, defaultValue);
			}
		}
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
};
