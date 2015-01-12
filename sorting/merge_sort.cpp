#include<iostream>
using namespace std;
void merge(int ar[],int l,int m,int r)
{
	int a = m-l+1;
	int b = r-m;
	int u[a],v[b];
	//cout << "a and b are " << a << " " << b << endl;
	//cout << "\nleft\n";
	for(int i = 0;i < a;i++) {
		u[i] = ar[l+i];
		//cout << u[i] << " ";
	}
	//cout << endl << "\nright\n";
	for(int i = 0;i < b;i++) {
		v[i] = ar[m+i+1];
		//cout << v[i] << " ";
	}
	//cout << endl;
	int p = 0;int q = 0;
	int k = 0;
	while(p < a && q < b) {
		if(u[p] <= v[q]) {
			ar[k+l] = u[p];
			//cout << ar[k] << " left ";
			p++;
		}else {
			ar[k+l] = v[q];
			//cout << ar[k] << " right ";
			q++;
		}
		k++;
	}
	//cout << endl;
	while(p < a) {
		ar[k+l] = u[p];
		//cout << ar[k] << " left ";
		p++;k++;
	}
	while(q < b) {
		ar[k+l] = v[q];
		//cout << ar[k] << " right ";
		q++;k++;
	}
	for(int i = 0;i < k;i++) {
		//cout << ar[i] << " ";
	}
	//cout << endl;
}
void merge_sort(int ar[],int l,int r)
{
	if(l < r) {
		int mid = (l+r)/2;
		//cout << "l , mid , r " << l << " " << mid << " " << r << endl;
		merge_sort(ar,l,mid);
		merge_sort(ar,mid+1,r);
		//cout << "merging "<< l << " " << mid << " " << r << "\n";
		merge(ar,l,mid,r);
	}else {
		return;
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
	merge_sort(ar,0,n-1);
	cout << endl;
	for(int i = 0;i < n;i++) {
		cout << ar[i] << " ";
	}
	cout << endl;
	return 0;
}
