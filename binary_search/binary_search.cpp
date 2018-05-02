#include <stdlib.h>
#include <iostream>
#include "binary_search.h"
using namespace std;

int  Search(int ar[], int low, int high, int k)
{
	if(low > high){
		return -1;
	}	
	int mid = low + (high - low)/2;

	if(k < ar[mid]){
		return Search(ar, low, mid-1, k);
	}else if(k > ar[mid]){	
		return Search(ar, mid+1, high, k);
	}else{
		return mid;
	}
}

void Display(int ar[], int n)
{
	for(int i = 0; i < n; i++){
		cout<<ar[i]<<", ";
	}
	cout<<endl;
}
