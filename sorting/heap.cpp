#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int* ar,int i,int n)
{
	int root = i;
	int left = 2*i + 1;
	int right = 2*i + 2;
	//cout << root << " " << left << " " << right << endl;
	//cout << "values " << ar[root] << " " << ar[left] << " " << ar[right] << endl;
	if(left < n && ar[left] > ar[root]) {
		root = left;
	}
	if(right < n && ar[right] > ar[root]) {
		root = right;
	}
	if(root != i) {
		swap(&ar[root],&ar[i]);
		//cout << "root is " << root << endl;
		heapify(ar,root,n);
	}
}
void heapbuild(int* ar,int n)
{
	for(int i = (n-2)/2;i >= 0;--i) {
		heapify(ar,i,n);
	}
}
void heapsort(int *ar,int n)
{
	heapbuild(ar,n);
	/*for(int i = 0;i < n;i++) {
		cout << ar[i] << " ";
	}*/
	while(n > 1) {
		//cout << ar[0] << " ";
		swap(&ar[0],&ar[n-1]);
		n--;
		heapify(ar,0,n);
	}
	//cout << ar[0] << endl;
}
int main()
{
	int n;
	cout << "Enter the size of array\n";
	cin >> n;
	int ar[n];
	cout << "Enter the elements\n";
	for(int i = 0;i < n;i++) {
		cin >> ar[i];
	}
	heapsort(ar,n);
	for(int i = 0;i < n;i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
	return 0;
}
