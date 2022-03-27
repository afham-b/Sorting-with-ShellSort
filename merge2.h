#pragma once

#include <algorithm>

// sort_compare - Standard sort comparison function
//	Parameters: a, b - values of type T which is less-than comparable
//	Returns: true if a < b, false otherwise
template <typename T>
inline bool sort_compare (const T& a, const T& b) { return a < b; }

// merge - Merge two adjacent sorted segments of an array.
//	Parameters:
//		a - an array of an arbitrary type T
//		p1 - pointer to first element of first sorted segment
//		p2 - pointer to first element of second sorted segment
//		p3 - pointer past last element of second sorted segment
//		tmp - Temporary array, for merging
//		cmp - comparison function or function object for comparing type T
template <typename T, typename U>
void merge (T* p1, T* p2, T* p3, T tmp[], U cmp) {

	T* a = p1; // points to an element in first segment
	T* b = p2; // points to an element in second segment
	T* c = tmp; // points to an element in the temporary array

	while (a < p2 && b < p3)
		*c++ = cmp(*a, *b) ? *a++ : *b++;
	while (a < p2)
		*c++ = *a++;
	while (b < p3)
		*c++ = *b++;

	for (a = p1, c = tmp; a < p3; a++, c++)
		*a = *c;
}

// sort - Merge sort
//	Parameters:
//		a - an array of an arbitrary type T
//		n - size of array a
//		cmp - comparison function or function object for comparing type T
template <typename T, typename U>
void sort (T a[], size_t n, U cmp) {
	T* tmp = new T[n];
	for (size_t size = 1; size < n; size *= 2) {
		for (size_t i = 0; i < n; i += 2 * size)
			merge(&a[i], std::min(&a[i + size], &a[n]),
				std::min(&a[i + 2 * size], &a[n]), tmp, cmp);
	}
	delete [] tmp;
}

// sort - Merge sort using sort_compare as the comparison function
template <typename T>
void sort (T a[], size_t n) { sort(a, n, sort_compare<T>); }