#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char ar[n];
	for(int p = 0;p < n;p++) {
		cin >> ar[p];
	}
	int j,ans;
	int i = 0;
	double sm = 0.0;
	while(i < n) {
		if(ar[i] == '0') {
			int temp = 0;
			int cnt = 0;
			ans = i;
			j = i;
			while(i < n && temp <= cnt) {
				if(ar[i] == '1') {
					temp++;
				}else if(ar[i] == '0'){
					cnt++;
					j = i;
					//cout << "j is " << j << endl;
				}
				i++;
			}
			cout << "window is " << ans << " " << j << endl;
			sm += sqrt(j-ans+1);
		}else {
			i++;
		}
	}
	printf("%.4f\n",sm);
	//cout << sm << endl;
	return 0;
}




