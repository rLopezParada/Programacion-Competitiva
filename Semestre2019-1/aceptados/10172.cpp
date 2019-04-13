//codigo propio
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

bool done(stack<int>* carrier, vector<queue<int>>* stations){
	if(!carrier->empty()) return false;
	for(int i=0; i<stations->size(); i++){
		if(!stations->at(i).empty()) return false;
	}
	return true;
}

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int SET;
	cin >> SET;
	int N,S,Q;
	int inc;
	int input;
	int actual;
	int time;
	vector<queue<int>> stations;
	stack<int> carrier;
	while(SET--){//for each set
		//read input
		cin >> N >> S >> Q;
		for(int i=0; i<N; i++){
			stations.emplace_back();
			cin >> inc;
			while(inc--){
				cin >> input;
				stations[i].push(input-1);
			}
		}
		//and execute solution
		actual = 0;
		time = 0;
		for(;;){
			while(!carrier.empty()){	//unloading
				if(carrier.top()==actual){	//unloading to platform A
					carrier.pop();
					time++;
				}
				else{
					if(stations[actual].size()<Q){	//unloading to platform B
						stations[actual].push(carrier.top());
						carrier.pop();
						time++;
					}
					else break;
				}
			}
			//loading to carrier
			while(!stations[actual].empty() && carrier.size()<S){
				carrier.push(stations[actual].front());
				stations[actual].pop();
				time++;
			}
			//stop if done
			if(done(&carrier, &stations)) break;
			//move to next station
			actual = (actual +1) % N;
			time += 2;
		}
		cout << time << endl;
		stations.clear();
	}
	return 0;
}