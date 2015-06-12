
/*
	using divide and conquer, aka optimized quick sort.
	complexity: O(k)
*/

#include "function.h"
#include <cstring>

#define Swap(a, b) do {typeof(a) t = a; a = b; b = t;} while(0);
void divideAndConquerAux(int array[], int left, int right, int kth);

int divideAndConquer(int array[], int len, int kth)
{
	int *data = new int[len];
	memcpy(data, array, sizeof(int) * len);
	divideAndConquerAux(data, 0, len - 1, kth - 1);
	int ans = data[kth - 1];
	delete[] data;
	return ans;
}

void divideAndConquerAux(int array[], int left, int right, int kth)
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
		divideAndConquerAux(array, index + 1, right, kth);
	else
		divideAndConquerAux(array, left, index - 1, kth);
}