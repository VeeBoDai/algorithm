#include <stdlib.h>
#include <iostream>
#include <assert.h>
#include "quick_sort.h"

using namespace std;
int main()
{
	int ar[] = {9,4,1,8,3,3,7};
	int n = sizeof(ar)/sizeof(int);
	Display(ar, n);
	QuickSort(ar, 0, n-1);
	Display(ar, n);

	return 0;
}
