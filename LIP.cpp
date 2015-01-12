#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >>  t;
	while(t--) {
		int n,m;
		cin >> n >> m;
		int ar[n][m];
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				cin >>  ar[i][j];
			}
		}
		int ans[102][102] = {0};
		int mx = 1;
		ans[0][0] = 1;
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				if(ans[i][j] > mx) mx = ans[i][j];
				if(ans[i][j] > 0 && ar[i+1][j] > ar[i][j]) {
					ans[i+1][j] = ans[i][j] + 1;
				}
				if(ans[i][j] > 0 && ar[i][j+1] > ar[i][j]) {
					ans[i][j+1] = ans[i][j] + 1;
				}
			}
		}
		/*for(int i = 0;i < n;i++) {
			for(int j = 0;j < m;j++) {
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}*/
		cout << mx << endl;
	}
	return 0;
}
