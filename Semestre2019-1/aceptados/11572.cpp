//codigo propio
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	int t, n, aux, yet, max, last;
	cin >> t;
	while(t--){
		cin >> n;
		unordered_map<int,int> snows;
		max = yet = 0;
		last = -1;
		for(int i = 0; i < n; i++){
			cin >> aux;
			if(snows.count(aux)==0){
				yet++;
			}
			else{
				if(snows[aux] > last) last = snows[aux];
				yet = i - last;
			}
			if(yet > max) max = yet;
			snows[aux] = i;
		}
		cout << max << endl;
	}
	return 0;
}