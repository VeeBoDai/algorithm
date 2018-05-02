#include <stdlib.h>
#include <iostream>
#include "binary_search.h"

using namespace std;
int main()
{
	int ar[] = {1,3,5,7,9,11};

	int n = sizeof(ar)/sizeof(int);

	Display(ar, n);

	cout<<"find 4, index:"<<Search(ar, 0, n-1, 4)<<endl;
	return 0;
}
