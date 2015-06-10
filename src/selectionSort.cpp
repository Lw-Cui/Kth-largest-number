/*
	using selection sort k times to get a sorted sub-array
	which length is k. 
	then we can get kth largest number.
	complexity: O(nk)
*/

#include "function.h"
#define Swap(a, b) do {typeof(a) t = a; a = b; b = t;} while(0);
	
int selectionSort(int array[], int len, int kth)
{
	for (int i = 0; i < kth; i++) {
		int max = i;
		for (int index = i + 1; index < len; index++)
			if (array[index] > array[max])
				max = index;
		Swap(array[max], array[i]);
	}
	return array[kth - 1];
}