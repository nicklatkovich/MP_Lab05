#include "Graph.h"
#include <vector>
#include <iostream>
#include "Utils.h"

void main() {
	//Graph<int> m(AMatrix<int>(5u, 5u, std::vector<int>{
	//		0, 1, 0, 0, 0,
	//		0, 0, 1, 1, 0,
	//		0, 0, 0, 0, 0,
	//		1, 0, 0, 0, 1,
	//		1, 0, 0, 0, 1,
	//}));
	Graph<int> m = Graph<int>::CreateGraph(5, std::list<std::tuple<unsigned int, unsigned int>>({
		std::make_tuple(0, 1),
		std::make_tuple(1, 2),
		std::make_tuple(1, 3),
		std::make_tuple(3, 0),
		std::make_tuple(3, 4),
		std::make_tuple(4, 4),
		std::make_tuple(4, 0),
	}), 0, 1);
	std::cout << m << std::endl;
	{
		using namespace SU;
		std::cout << "BFS = " << m.BFS(1) << std::endl;
		std::cout << "DFS = " << m.DFS(1) << std::endl;
	}

#ifdef _DEBUG
	std::cin.get();
#endif // _DEBUG

}
