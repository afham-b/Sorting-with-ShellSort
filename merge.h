#pragma once

#include <algorithm>

// sort_compare - Standard sort comparison function
//	Parameters: a, b - values of type T which is less-than comparable
//	Returns: true if a < b, false otherwise
template <typename T>
inline bool sort_compare (const T& a, const T& b) { return a < b; }

// sort - Merge sort, array segment
//	Parameters:
//		a - an array of an arbitrary type T
//		low - low index of segment
//		high - low index of segment
//		tmp - Temporary array, for merging
//		cmp - comparison function or function object for comparing type T
template <typename T, typename U>
void sort (T a[], size_t low, size_t high, T tmp[], U cmp) {
	if (low < high) {
		size_t mid = (low + high) / 2;
		sort(a, low, mid, tmp, cmp);
		sort(a, mid + 1, high, tmp, cmp);
		size_t i = low;
		size_t j = mid + 1;
		size_t k = 0;
		while (i <= mid && j <= high)
			tmp[k++] = cmp(a[i], a[j]) ? a[i++] : a[j++];
		while (k < high - low + 1)
			tmp[k++] = i <= mid ? a[i++] : a[j++];
		for (i = low, k = 0; k < high - low + 1; i++, k++)
			a[i] = tmp[k];
	}
}

// sort - Merge sort
//	Parameters:
//		a - an array of an arbitrary type T
//		n - size of array a
//		cmp - comparison function or function object for comparing type T
template <typename T, typename U>
void sort (T a[], size_t n, U cmp) {
	T* tmp = new T[n];
	sort(a, 0, n - 1, tmp, cmp);
	delete [] tmp;
}

// sort - Merge sort using sort_compare as the comparison function
template <typename T>
void sort (T a[], size_t n) { sort(a, n, sort_compare<T>); }