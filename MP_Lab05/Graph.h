#pragma once
#include "AMatrix.h"
#include <algorithm>
#include <list>
#include <tuple>

template <class T>
class Graph {
private:
	AMatrix<T> _matrix;
public:
	Graph(AMatrix<T>& matrix) {
		unsigned int size = std::min(matrix.GetWidth(), matrix.GetHeight());
		_matrix = AMatrix<T>(size, size);
		for (unsigned int i = 0; i < size; i++) {
			for (unsigned int j = 0; j < size; j++) {
				_matrix.Set(i, j, matrix.Get(i, j));
			}
		}
	}
	T Get(unsigned int x, unsigned int y) {
		return _matrix.Get(x, y);
	}
	friend std::ostream& operator << (std::ostream& out, Graph& g) {
		return out << g._matrix;
	}
	static Graph<T> CreateGraph(unsigned int size, std::list<std::tuple<unsigned int, unsigned int>> list, T emptyWayValue, T wayValue) {
		Graph<T> result(AMatrix<T>(size, size, emptyWayValue));
		for each (std::tuple<unsigned int, unsigned int> way in list) {
			result._matrix.Set(std::get<0>(way), std::get<1>(way), wayValue);
		}
		return result;
	}

};
