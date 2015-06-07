/*
 	this program is to implement different algorithm
	that aim to find the Kth largest element 
	in a given interge array.
 	then we analysis their strengths and weakness.

 	compiler: GNU G++ 4.82
 	OS: Ubuntu
 	date: 06/07/15
*/

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <functional>
#include <algorithm>
#define Swap(a, b) do {typeof(a) t = a; a = b; b = t;} while(0);
using namespace std;


/*
	using selection sort k times to get a sorted sub-array
	which length is k. 
	then we can get kth largest number.
	complexity: O(nk)
*/
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


/*
	using quick sort to sort the whole array 
	in descending order.
	the the array[k - 1] is answer.
	complexity: O(nlogn)
	attention: it's easy to stack overflow.
*/
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


/*
	using divide and conquer, aka optimized quick sort.
	complexity: O(k)
*/
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
	swap(array[left], array[index]);
	if (kth == index)
		return;
	else if (kth > index)
		DivideAndConquer(array, index + 1, right, kth);
	else
		DivideAndConquer(array, left, index - 1, kth);
}


const int LEN = 90000000;
const int k = 1234567;

int Array[LEN];
int tmp[LEN];
int Copy[LEN];

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	for (int i = 0; i < LEN; i++)
		Array[i] = rand();
		//if we assign array[i] = i, then stack will be overflow.
	memcpy(tmp, Array, sizeof(int) * LEN);
	memcpy(Copy, Array, sizeof(int) * LEN);

	DivideAndConquer(tmp, 0, LEN - 1, k - 1);
	qsort(Copy, 0, LEN - 1);

	cout << tmp[k - 1] << endl
		<< Copy[k - 1] << endl;
		//<< selectionSort(Array, LEN, k) << endl;

	return 0;
}