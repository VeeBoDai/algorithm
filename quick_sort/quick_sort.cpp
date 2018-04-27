#include <stdlib.h>
#include <iostream>
#include "quick_sort.h"


using namespace std;

void Display(int ar[], int n)
{
	for(int i=0; i<n; i++){
		cout<<ar[i]<<", ";
	}
	cout<<endl;
}

void QuickSort(int ar[], int low, int hight)
{
	if(low >= hight){
		return;
	}	

	int temp = ar[low];
	int first = low;
	int last = hight;

	while(first < last){
		while(first < last && ar[last] >= temp){
			last--;
		}
		ar[first] = ar[last];

		while(first < last && ar[first] < temp){
			first++;
		}
		ar[last] = ar[first];
	}
	ar[first] = temp;
	QuickSort(ar, low, first-1);
	QuickSort(ar, first+1, hight);
}	
