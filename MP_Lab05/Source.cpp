#include "Graph.h"
#include <vector>
#include <iostream>

void main() {
	Graph<int> m(AMatrix<int>(5u, 5u, std::vector<int>{
			0, 1, 0, 0, 0,
			0, 0, 1, 1, 0,
			0, 0, 0, 0, 0,
			1, 0, 0, 0, 1,
			1, 0, 0, 0, 1,
	}));
	std::cout << m << std::endl;
}
