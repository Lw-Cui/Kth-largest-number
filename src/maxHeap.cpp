/*
	using heap to maintain the largest number ranges from 1th largest
	to kth largest. the answer is easy to find.
	complexity: O(k + nlogk)
*/

#include "function.h"

int maxHeap(int array[], int kth, int len)
{
	const int MIN = - (1 << 30);
	int *heap = new int[kth + 1];
	for (int i = 1; i <= kth + 1; i++)
		heap[i] = MIN;

	for (int i = 0; i < len; i++)
		if (array[i] > heap[1]) {
			int hole;
			for (int curPos = 1 * 2; curPos <= kth; curPos *= 2) {
				if (curPos + 1 <= kth && heap[curPos] > heap[curPos + 1])
					curPos++;
				if (array[i] < heap[curPos]) {
					hole = curPos / 2;
					break;
				} else {
					heap[curPos / 2] = heap[curPos];
					hole = curPos;
				}
			}
			heap[hole] = array[i];
		}

	int ans = heap[1];
	delete[] heap;
	return ans;
}