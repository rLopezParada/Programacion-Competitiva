//codigo propio
#include <iostream>
#include <queue>
using namespace std;

enum side {LEFT, RIGHT};

struct car{
	char lado;
	int hora;
};

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int c, n, t, m, hora;
	car autos[10000];
	queue<int> road, leftQ, rightQ, ferry;
	string input;
	char ladoActual;
	cin >> c;
	while(c--){
		//read input
		cin >> n >> t >> m;
		for(int i=0; i<m; i++){
			cin >> autos[i].hora >> input;
			if(input[0]=='l') autos[i].lado = LEFT;
			else autos[i].lado = RIGHT;
			road.push(i);
		}
		//execution
		ladoActual = LEFT;
		hora = autos[road.front()].hora;
		while(!leftQ.empty() || !rightQ.empty() || !ferry.empty() || !road.empty()){
			while(!road.empty() && autos[road.front()].hora <= hora){
				if(autos[road.front()].lado == LEFT) leftQ.push(road.front());
				else rightQ.push(road.front());
				road.pop();
			}
			if(ladoActual==LEFT){
				while(!ferry.empty()){
					autos[ferry.front()].hora = hora;
					ferry.pop();
				}
				while(!leftQ.empty() && ferry.size()<n){
					ferry.push(leftQ.front());
					leftQ.pop();
				}
				if(!ferry.empty() || !rightQ.empty()){
					hora += t-1;
					ladoActual = RIGHT;
				}
			}
			else{
				while(!ferry.empty()){
					autos[ferry.front()].hora = hora;
					ferry.pop();
				}
				while(!rightQ.empty() && ferry.size()<n){
					ferry.push(rightQ.front());
					rightQ.pop();
				}
				if(!ferry.empty() || !leftQ.empty()){
					hora += t-1;
					ladoActual = LEFT;
				}
			}
			hora++;
		}
		for(int i=0; i<m; i++) cout << autos[i].hora << endl;
		if(c) cout << endl;
	}
	return 0;
}