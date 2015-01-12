#include<iostream>
using namespace std;
void insertion_sort(int a[],int n)
{
	int cnt = 0;
	for(int i = 1;i < n;i++) {
		int temp = a[i];
		int j = i-1;
		while(j >= 0 && a[j] > temp) {
			a[j+1] = a[j];
			j--;
			cnt++;
		}
		a[j+1] = temp;
	}
	cout << cnt << endl;
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i < n;i++) {
		cin >> a[i];
	}
	insertion_sort(a,n);
	for(int i = 0;i < n;i++) {
		cout << a[i] << " ";
	}
	return 0;
}
