#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N, M, aux, total;
	cin >> N >> M;
	while(N && M){
		vector<int> jack;
		jack.reserve(N);
	
		total = 0;
		for(int i=0; i<N; i++){
			cin >> aux;
			jack.push_back(aux);
			cout << aux << endl;
		}
		vector<int>::iterator it = jack.begin(), itEnd = jack.end();
		for(int i=0; i<M && it!=itEnd; i++){
			cin >> aux;
			cout << aux << endl;
			while(*it <= aux){
				if(it == itEnd) break;
				it++;
				if(*it == aux) total++;
			}




			while(*it < aux){
				if(it == itEnd) break;
				it++;
			}
			if(*it == aux){
				total++;
				it++;
			}
		}
		cin >> N >> M;
		cout << total << endl;
	}

	return 0;
}