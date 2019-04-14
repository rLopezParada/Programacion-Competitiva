//codigo propio
#include <iostream>
#include <stack>
using namespace std;

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int N, n, arr[1000];
	bool exit;
	stack<int> stk;
	for(;;){	//for each set
		cin >> N;
		if(N==0) return 0;
		for(;;){	//for each line
			exit = false;
			for(int i=0; i<N; i++){	//for each number
				cin >> arr[i];
				if(i==0 && arr[i]==0){
					exit = true;
					break;
				}
			}
			if(exit){
				cout << endl;
				break;
			}
			//execute
			n=1;
			for(int i=0; i<N && !exit; i++){
				for(;;){
					if(n >= N+2){
						exit = true;
						break;
					}
					if(!stk.empty() && arr[i]==stk.top()){
						stk.pop();
						break;
					}
					stk.push(n++);
				}
			}
			if(exit) cout << "No\n";
			else cout << "Yes\n";
			while(!stk.empty()) stk.pop();
		}
	}
}