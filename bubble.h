#pragma once

#include <algorithm>

// sort_compare - Standard sort comparison function
//	Parameters: a, b - values of type T which is less-than comparable
//	Returns: true if a < b, false otherwise
template <typename T>
inline bool sort_compare (const T& a, const T& b) { return a < b; }

// sort - Bubble sort
//	Parameters:
//		a - an array of an arbitrary type T
//		n - size of array a
//		cmp - comparison function or function object for comparing type T
template <typename T, typename U>
void sort (T a[], size_t n, U cmp) {
	for (size_t i = 0; i < n - 1; i++)
		for (size_t j = 0; j < n - 1 - i; j++)
			if (cmp(a[j + 1], a[j]))
				std::swap(a[j], a[j + 1]);
}

// sort - Bubble sort using sort_compare as the comparison function
template <typename T>
void sort (T a[], size_t n) { sort(a, n, sort_compare<T>); }