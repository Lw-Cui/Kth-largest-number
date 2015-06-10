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
#include "function.h"
#define Swap(a, b) do {typeof(a) t = a; a = b; b = t;} while(0);
using namespace std;

const int LEN = 90000000;
const int k = 1234567;

int Array[LEN];
int tmp[LEN];
int Copy[LEN];
int lab[LEN];

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	for (int i = 0; i < LEN; i++)
		Array[i] = rand();
		//if we assign array[i] = i, then stack will be overflow.
	memcpy(tmp, Array, sizeof(int) * LEN);
	memcpy(Copy, Array, sizeof(int) * LEN);
	memcpy(lab, Array, sizeof(int) * LEN);

	DivideAndConquer(tmp, 0, LEN - 1, k - 1);
	cout << tmp[k - 1] << endl
		<< maxHeap(Copy, k, LEN) << endl;

	qsort(lab, 0, LEN - 1);
	cout << lab[k - 1] << endl;
	//cout<< selectionSort(Array, LEN, k) << endl;

	return 0;
}