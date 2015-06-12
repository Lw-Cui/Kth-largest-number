/*
	using quick sort to sort the whole array 
	in descending order.
	the the array[k - 1] is answer.
	complexity: O(nlogn)
	attention: it's easy to stack overflow.
*/
	
#include "function.h"
#include <cstring>
#define Swap(a, b) do {typeof(a) t = a; a = b; b = t;} while(0);
void qsortAux(int array[], int left, int right);

int qsort(int array[], int len, int kth)
{
	int *data = new int[len];
	//memcpy(data, array, sizeof(array));
	memcpy(data, array, sizeof(int) * len);
	qsortAux(data, 0, len - 1);
	int ans = data[kth - 1];
	delete[] data;
	return ans;
}

void qsortAux(int array[], int left, int right)
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
	qsortAux(array, left, index - 1);
	qsortAux(array, index + 1, right);
}