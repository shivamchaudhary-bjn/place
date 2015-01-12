#include<iostream>
#include<algorithm>
using namespace std;
int m[1000001];
void create(int ind,int x,int y,int a[],int n)
{
	//cout << "x and y are " << x << " " << y << endl;
	if(x == y) {
		m[ind] = x;
	//cout << "index is " << ind << " and value is " << m[ind] << endl;
		return;
	}
	create(2*ind+1,x,(x+y)/2,a,n);
	create(2*ind+2,(x+y)/2+1,y,a,n);
	if(a[m[2*ind+1]] <= a[m[2*ind+2]]) {
		m[ind] = m[2*ind+1];
	}else {
		m[ind] = m[2*ind+2];
	}
	//cout << "index is " << ind << " and value is " << m[ind] << endl;
}
int rmq(int ind,int x,int y,int a[],int n,int i,int j)
{
	if(i > y || j < x) {
		return -1;
	}

	if(i >= x && y >= j) {
		return m[ind];
	}
	int l = rmq(2*ind+1,x,y,a,n,i,(i+j)/2);
	int r = rmq(2*ind+2,x,y,a,n,(i+j)/2+1,j);
	if(l == -1) {
		m[ind] = r;
	}else if(r == -1) {
		m[ind] = l;
	}else if(a[l] <= a[r]) {
		m[ind] = l;
	}else if(a[r] <= a[l]) {
		m[ind] = r;
	}
	return m[ind];
	//int temp =  min(rmq(2*ind+1,x,y,a,n,i,(i+j)/2),rmq(2*ind+2,x,y,a,n,(i+j)/2+1,j));
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	//int sz = 2*pow(2,log(n)+1);
	for(int i = 0; i< n;i++) {
		cin >> a[i];
	}
	create(0,0,n-1,a,n);
	int q;
	cin >> q;
	while(q--) {
		int x,y;
		cin >> x >> y;
		cout << a[rmq(0,x,y,a,n,0,n-1)] << endl;
	}
	return 0;
}
