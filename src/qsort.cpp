/*
	using quick sort to sort the whole array 
	in descending order.
	the the array[k - 1] is answer.
	complexity: O(nlogn)
	attention: it's easy to stack overflow.
*/
	
#include "function.h"
#define Swap(a, b) do {typeof(a) t = a; a = b; b = t;} while(0);

void qsort(int array[], int left, int right)
{
	if (left >= right)
		return;
	int index = left;
	for (int i = left + 1; i <= right; i++)
		if (array[left] < array[i]) {
			++index;
			Swap(array[index], array[i]);
		}
	Swap(array[left], array[index]);
	qsort(array, left, index - 1);
	qsort(array, index + 1, right);
}