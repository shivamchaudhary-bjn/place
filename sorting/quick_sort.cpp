#include<iostream>
using namespace std;
int partition(int *ar,int start,int end)
{
	int pivot = ar[end];
	int Pindex = start;
	for(int i = start;i < end;i++) {
		if(ar[i] <= pivot) {
			int temp = ar[i];
			ar[i] = ar[Pindex];
			ar[Pindex] = temp;
			Pindex++;
		}
	}
	int t = ar[end];
	ar[end] = ar[Pindex];
	ar[Pindex] = t;
	return Pindex;
}
void quick_sort(int *ar,int start,int end)
{
	if(start < end) {
		int index = partition(ar,start,end);
		quick_sort(ar,start,index-1);
		quick_sort(ar,index+1,end);
	}
}
int main()
{
	int n;
	cin >> n;
	int ar[n];
	for(int i = 0;i < n;i++) {
		cin >> ar[i];
	}
	quick_sort(ar,0,n-1);
	for(int i = 0;i < n;i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
	return 0;
}
