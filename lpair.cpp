#include<iostream>
#include<algorithm>
using namespace std;
typedef struct point {
	int male;
	int fem;
}couple;
int m[1000001] = {0};
void create(int ind,int x,int y,couple a[],int n)
{
	//cout << "x and y are " << x << " " << y << endl;
	if(x == y) {
		m[ind]++;
	//cout << "index is " << ind << " and value is " << m[ind] << endl;
		return;
	}else if(x+1 == y) {
		if(a[m[2*ind+1]].fem > a[m[2*ind+2]].fem) {
			m[ind] = m[2*ind+1] + m[2*ind+2];
			return;
		}
	}
	create(2*ind+1,x,(x+y)/2,a,n);
	create(2*ind+2,(x+y)/2+1,y,a,n);
	m[ind] = m[2*ind+1]+m[2*ind+2];
	//cout << "index is " << ind << " and value is " << m[ind] << endl;
}
/*int rmq(int ind,int x,int y,couple a[],int n,int i,int j)
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
}*/

int main()
{
	int n;
	cin >> n;
	couple a[n];
	for(int i = 0; i< n;i++) {
		int u,v;
		cin >> u >> v;
		couple p;
		p.male = u;
		p.fem = v;
		a[i] = p;
	}
	create(0,0,n-1,a,n);
	cout << m[0] << endl;
	//cout << rmq(0,0,n-1,a,n,0,n-1) << endl;
	return 0;
}
