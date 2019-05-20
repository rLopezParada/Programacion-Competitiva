//codigo propio
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		int arr[n];
		for(int i=0; i<n; i++)
			cin >> arr[i];
		sort(arr, arr+n);
		int n1 = arr[(n-1)/2],
			n2 = arr[n/2],
			times = 0;
		if(n%2) times = -1;
		for(int i=(n-1)/2; i>-1; i--){
			if(arr[i]==n1) times++;
			else break;
		}
		for(int i=n/2; i<n; i++){
			if(arr[i]==n2) times++;
			else break;
		}
		cout << n1 << ' ' << times << ' ' << n2-n1+1 << endl;
	}
	return 0;
}