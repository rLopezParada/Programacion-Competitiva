//codigo propio
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
	int n, op, x, xCorrecto;
	bool esStk, esQ, esPq;
	while(cin >> n){
		stack<int> stk;
		queue<int> q;
		priority_queue<int> pq;
		esStk = esQ = esPq = true;
		while(n--){
			cin >> op >> x;
			if(op == 1){
				if(esStk) stk.push(x);
				if(esQ) q.push(x);
				if(esPq) pq.push(x);
			}
			else{
				if(esStk){
					esStk = false;
					if(!stk.empty()){
						xCorrecto = stk.top();
						stk.pop();
						if(x == xCorrecto) esStk = true;
					}
				}
				if(esQ){
					esQ = false;
					if(!q.empty()){
						xCorrecto = q.front();
						q.pop();
						if(x == xCorrecto) esQ = true;
					}
				}
				if(esPq){
					esPq = false;
					if(!pq.empty()){
						xCorrecto = pq.top();
						pq.pop();
						if(x == xCorrecto) esPq = true;
					}
				}
			}
		}
		if(esStk && !esQ && !esPq) cout << "stack\n";
		else if(!esStk && esQ && !esPq) cout << "queue\n";
		else if(!esStk && !esQ && esPq) cout << "priority queue\n";
		else if(!esStk && !esQ && !esPq) cout << "impossible\n";
		else cout << "not sure\n";
	}
	return 0;
}