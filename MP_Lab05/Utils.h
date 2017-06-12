#pragma once

namespace SU {
	template <class T>
	unsigned int GetArrayLength(T arr[]) {
		return sizeof(arr) / sizeof(*arr);
	}
};
