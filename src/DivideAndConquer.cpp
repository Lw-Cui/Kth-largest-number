
/*
	using divide and conquer, aka optimized quick sort.
	complexity: O(k)
*/

#include "function.h"
#define Swap(a, b) do {typeof(a) t = a; a = b; b = t;} while(0);

void DivideAndConquer(int array[], int left, int right, int kth)
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
	if (kth == index)
		return;
	else if (kth > index)
		DivideAndConquer(array, index + 1, right, kth);
	else
		DivideAndConquer(array, left, index - 1, kth);
}