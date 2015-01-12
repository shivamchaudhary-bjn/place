#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int flag = 0;
		int sm = 0;
		int cnt = 0;
		map<int> m;
		map<int>::iterator it;
		int n;
		cin >> n;
		for(int i = 0;i < n;i++) {
			int temp;
			cin >> temp;
			m[temp]++;
		}
		for(it = m.begin();it != m.end();it++) {
			if((*it).second <= ((*it).first - (sm+cnt))) {
				sm += (*it).second;
				cnt = sm/6;
			}else {
				cout << "Goodbye Rick\n";
				cout << sm%

				



