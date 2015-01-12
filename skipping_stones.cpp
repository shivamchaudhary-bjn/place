#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,l,d;
	cin >> n >> l >> d;
	double prob[n+2];
	int dist[n+2];
	dist[0] = 0;
	prob[0] = 1.0;
	prob[n+1] = 1.0;
	dist[n+1] = d;
	for(int i = 1;i <= n;i++) {
		cin >> prob[i];
	}
	for(int i = 1;i <= n;i++) {
		cin >> dist[i];

	}
	double ans[n+1];
	ans[0] = 1.0;
	for(int i = 1;i <= n+1;i++) {
		double pt = -1.0;
		int j = i-1;
		while(j >= 0 && (dist[i]-dist[j] <= l)) {
			 pt = max(pt,prob[j]*prob[i]);
			 j--;
		}
		prob[i] = pt;
		//cout << "prob for " << i << " is " << prob[i] << endl;
		if(pt < 0) {
			cout << "IMPOSSIBLE\n";
			break;
		}
	}
	printf("%.6f\n",prob[n+1]);
	return 0;
}

