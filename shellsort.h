//Afham Bashir. Assignment 3. 
#pragma once

#include <algorithm>
using namespace std; 

// sort_compare - Standard sort comparison function
//	Parameters: a, b - values of type T which is less-than comparable
//	Returns: true if a < b, false otherwise
template <typename T>
inline bool sort_compare (const T& a, const T& b) { return a < b; }

// sort - Insertion sort
//	Parameters:
//		a - an array of an arbitrary type T
//		n - size of array a
//		cmp - comparison function or function object for comparing type T
template <typename T, typename U>      
void sort (T a[], size_t n, U cmp) {   
	for (size_t gap = n/2; gap > 0 ; gap/=2 ) {     //here the gap size for shell sort is set to n/2, half the size of the array, the loop with each passed decreased the gap by half. 
		for (size_t i = gap; i < n; ++i){            //loop looks at indexes that the gap away from each other
        T temp = a[i];
        size_t j=i;  
        for(; j>= gap && cmp(temp, a[j-gap]); j-= gap){  //inner loop to compare the two values the index
          a[j]= a[j-gap]; } 
        a[j]= temp;        //does the swap 
    }
	}
}


// sort - Shell sort using sort_compare as the comparison function
template <typename T>
void sort (T a[], size_t n) { sort(a, n, sort_compare<T>);
 }
