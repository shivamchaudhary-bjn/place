#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
void swap(string &s,int i,int j)
{
	char c = s[i];
	s[i] = s[j];
	s[j] = c;
}
void perm(string &s,int a,int b)
{
	if(a == b) {
		cout << s << endl;
	}else {
		for(int i = a;i <= b;i++) {
			swap(s,a,i);
			perm(s,a+1,b);
			swap(s,a,i);
		}
	}
}
int main()
{
	string s;
	cin >> s;
	int n = s.length();
	perm(s,0,n-1);
	return 0;
}
