#include <stdlib.h>
#include <iostream>
#include <assert.h>

using namespace std;


typedef struct Node{
	int v;
	Node* next;
	Node(int k = 0):v(k), next(NULL){}
}Node, *pnode;

Node *ArrToLink(int a[], int n)
{
	Node* ph = NULL;
	Node* p = NULL;
	if(n<1){
		return ph;	
	}
	else{
		p = ph = new Node(a[0]);
	}
	for(int i=1; i<n; i++){
		p->next = new Node(a[i]);
		p = p->next;
	}

	return ph;
}		

void DisplayLink(Node *p)
{
	while(p){
		cout<<p->v<<", ";
		p = p->next;
	}
	cout<<endl;
}

int Left(int i)
{
	return 2*i+1;
}

int Right(int i)
{
	return 2*i+2;
}

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void Adjust(Node* a[], int i, int n)
{
	int li = Left(i);
	int ri = Right(i);
	int min;
	int min_id; 
	if(li < n){
		min = a[li]->v;
		min_id = li;
		if(ri < n && min > a[ri]->v){
			min = a[ri]->v;
			min_id = ri;
		}
		
		if(min < a[i]->v){
			swap(a[i], a[min_id]);	
			Adjust(a, min_id, n);
		}
	}
}


void DisplayMinHeap(Node* a[], int n)
{	
	for(int i=0; i<n; i++){
		if(NULL != a[i]){	
			cout<<a[i]->v<<", ";
		}
	}
	cout<<endl;
}		

void BuildMinHeap(Node* a[], int n){
	for(int i=n/2-1; i>=0; i--){
		Adjust(a, i, n);
	}
	cout<<endl<<"after build:"<<endl;
	DisplayMinHeap(a,n);
}

int getKmin(Node* a[], int n, int k)
{
	int min = a[0]->v;
	int realn = n;
	for(int i=0; i<k; i++){
		min = a[0]->v;	
		if(a[0]->next){
			a[0] = a[0]->next;
			Adjust(a, 0, realn);
		}else{
			if(realn > 1){
				realn--;
				a[0] = a[realn];
				Adjust(a,0, realn);
			}else{
				if(i == k-1){
					return min;
				}	
				cout<<"k is lager all elements;"<<endl;
				return 0;
			}
		}
	}
	return min;
}

int main()
{
	Node* a[3];	
	int a1[] = {11,12,13,14,15,17};
	int n = sizeof(a1)/sizeof(int);
	a[0] = ArrToLink(a1,n);
	
	int a2[] = {9,10,16,18};
	n = sizeof(a2)/sizeof(int);
	a[1] = ArrToLink(a2,n);


	int a3[] = {1,2,3,4,5};
	n = sizeof(a3)/sizeof(int);
	a[2] = ArrToLink(a3,n);

	BuildMinHeap(a,3);

//	assert(1 == getKmin(a, 3, 1));

	assert(18 == getKmin(a, 3, 15));

//	cout<<"kmin:"<<kmin<<endl;

	return 0;
}











