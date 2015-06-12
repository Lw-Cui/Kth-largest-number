/*
	using heap to maintain the largest number ranges from 1th largest
	to kth largest. the answer is easy to find.
	complexity: O(k + nlogk)
*/

#include "function.h"
#include <cstring>
void percolateDown(int heap[], int len, int pos);

int maxHeap(int array[], int len, int kth)
{
	int *heap = new int[kth + 1];
	memcpy(heap + 1, array, sizeof(int) * kth);
	for (int i = kth / 2; i >= 1; i--)
		percolateDown(heap, kth, i);

	for (int i = kth + 1; i < len; i++)
		if (array[i] > heap[1]) {
			heap[1] = array[i];
			percolateDown(heap, kth, 1);
		}

	int ans = heap[1];
	delete heap;
	return ans;
}

void percolateDown(int heap[], int len, int pos)
{
	int value = heap[pos];
	for (int child = pos * 2; child <= len; child *= 2) {
		if (child + 1 <= len && heap[child] > heap[child + 1])
			child++;
		if (value < heap[child])
			break;
		else
			heap[pos] = heap[child];
		pos = child;
	}
	heap[pos] = value;
}