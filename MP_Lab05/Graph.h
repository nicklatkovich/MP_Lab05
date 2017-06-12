#pragma once
#include "AMatrix.h"
#include <algorithm>
#include <list>
#include <tuple>
#include <queue>
#include <stack>
#include <exception>

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
	unsigned int GetSize() {
		return _matrix.GetWidth();
	}
	std::vector<unsigned int> BFS(T wayValue, unsigned int start = 0) {
		std::vector<unsigned int> result;
		std::vector<bool> passes(GetSize());
		std::queue<unsigned int> q;
		q.push(start);
		passes[start] = true;
		while (q.empty() == false) {
			unsigned int cell = q.front();
			q.pop();
			result.push_back(cell);
			for (unsigned int i = 0; i < GetSize(); i++) {
				if (passes[i] == false && _matrix.Get(cell, i) == wayValue) {
					passes[i] = true;
					q.push(i);
				}
			}
		}
		return result;
	}
	std::vector<unsigned int> DFS(T wayValue, unsigned int start = 0) {
		std::vector<unsigned int> result;
		const int WHITE = 0;
		const int GRAY = 1;
		const int BLACK = 2;
		std::vector<int> passes(GetSize());
		for (unsigned int i = 0; i < GetSize(); i++) {
			passes[i] = WHITE;
		}
		passes[start] = GRAY;
		std::stack<unsigned int> q;
		q.push(start);
		while (q.empty() == false) {
			unsigned int cell = q.top();
			bool hasWay = false;
			for (unsigned int i = GetSize(); i > 0; i--) {
				if (passes[i - 1] == WHITE && _matrix.Get(cell, i - 1) == wayValue) {
					passes[i - 1] = GRAY;
					q.push(i - 1);
					hasWay = true;
				}
			}
			if (hasWay == false) {
				result.push_back(cell);
				passes[cell] = BLACK;
				q.pop();
			}
		}
		return result;
	}
	std::vector<unsigned int> TopologicalSorting(T wayValue) {
		std::vector<unsigned int> result;
		AMatrix<bool> temp(_matrix.GetWidth(), _matrix.GetHeight());
		for (unsigned int i = 0; i < GetSize(); i++) {
			for (unsigned int j = 0; j < GetSize(); j++) {
				temp.Set(i, j, _matrix.Get(i, j) == wayValue);
			}
		}
		while (result.size() != GetSize()) {
			bool hasMove = false;
			for (unsigned int i = 0; i < GetSize(); i++) {
				bool isIndependent = true;
				for (unsigned int j = 0; j < GetSize(); j++) {
					if (i != j) {
						if (temp.Get(j, i)) {
							isIndependent = false;
							break;
						}
					}
				}
				if (isIndependent) {
					result.push_back(i);
					for (unsigned int j = 0; j < GetSize(); j++) {
						temp.Set(i, j, false);
					}
					hasMove = true;
				}
			}
			if (hasMove == false) {
				throw std::exception("Graph is contour");
			}
		}
		return result;
	}
};
