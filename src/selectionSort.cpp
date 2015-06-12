/*
	using selection sort k times to get a sorted sub-array
	which length is k. 
	then we can get kth largest number.
	complexity: O(nk)
*/

#include "function.h"
#include <cstring>
#define Swap(a, b) do {typeof(a) t = a; a = b; b = t;} while(0);
void selectionSortAux(int array[], int len, int kth);
	
int selectionSort(int array[], int len, int kth)
{
	int *data = new int[len];
	memcpy(data, array, sizeof(int) * len);
	selectionSortAux(data, len, kth);
	int ans = data[kth - 1];
	delete data;
	return ans;
}

void selectionSortAux(int array[], int len, int kth)
{
	for (int i = 0; i < kth; i++) {
		int max = i;
		for (int index = i + 1; index < len; index++)
			if (array[index] > array[max])
				max = index;
		Swap(array[max], array[i]);
	}
}