//codigo propio
#include <iostream>
#include <vector>
using namespace std;

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int n;
	int series[3000];
	bool check[3000];
	bool jolly;
	while(cin >> n){
		for(int i=0; i<n; i++)
			cin >> series[i];

		for(int i=1; i<n; i++)
			check[i]=false;

		jolly = true;
		for(int i=1; i<n; i++)
			check[abs(series[i]-series[i-1])]=true;
		for(int i=1; i<n; i++){
			if(check[i]==false)
				jolly = false;
		}
		if(n==1)
			jolly = true;
		if(jolly)
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
	}


	return 0;
}