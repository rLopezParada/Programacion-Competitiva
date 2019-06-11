//codigo propio
#include <iostream>
#include <queue>
using namespace std;

int main(){
	int N, cost, aux;
	cin >> N;
	priority_queue<int,vector<int>,greater<int>> cola;
	while(N){
		//read sequence
		while(N--){
			cin >> aux;
			cola.push(aux);
		}
		//add
		cost = 0;
		while(cola.size()>1){
			int a = cola.top();
			cola.pop();
			int b = cola.top();
			cola.pop();
			int res = a + b;
			cost += res;
			cola.push(res);
		}
		cin >> N;
		cout << cost << endl;
		cola.pop();
	}
	return 0;
}