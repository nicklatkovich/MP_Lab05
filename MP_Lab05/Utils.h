#pragma once
#include <vector>

namespace SU {
	template <class T>
	unsigned int GetArrayLength(T arr[]) {
		return sizeof(arr) / sizeof(*arr);
	}

	template <class T>
	std::ostream& operator << (std::ostream& out, std::vector<T> v) {
		for each (T var in v) {
			out << var << " ";
		}
		return out;
	}
};
