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
#include "function.h"
#define Swap(a, b) do {typeof(a) t = a; a = b; b = t;} while(0);
using namespace std;

const int LEN = 900000;
const int k = 12345;

int Array[LEN];
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	for (int i = 0; i < LEN; i++)
		Array[i] = rand();
		//if we assign array[i] = i, then stack will be overflow.

	cout << maxHeap(Array, LEN, k) << endl
		<< qsort(Array, LEN, k) << endl
		<< divideAndConquer(Array, LEN, k) << endl
		<< selectionSort(Array, LEN, k) << endl;
	return 0;
}