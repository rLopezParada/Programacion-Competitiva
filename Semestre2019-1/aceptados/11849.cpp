//codigo propio
#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
	int N, M, aux, total;
	cin >> N >> M;
	unordered_set<int> jack;
	while(N && M){
		jack.clear();
		total = 0;
		for(int i=0; i<N; i++){
			cin >> aux;
			jack.insert(aux);
		}
		for(int i=0; i<M; i++){
			cin >> aux;
			if(jack.count(aux)) total++;
		}
		cin >> N >> M;
		cout << total << endl;
	}
	return 0;
}