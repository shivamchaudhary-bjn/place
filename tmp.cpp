#include<iostream>
int main(){
	int t;
	cin >> t;
	while(t--){
		int ans= 0;
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0;i < n;i++){
			cin >> arr[i];
			ans ^= arr[i];
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				ans ^= arr[i]^arr[j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
