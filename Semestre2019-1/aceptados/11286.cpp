//codigo propio
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n){
		map<vector<int>,int> mapa;
		for(int i=0; i<n; i++){
			int aux[5];
			cin >> aux[0] >> aux[1] >> aux[2] >> aux[3] >> aux[4];
			sort(aux, aux+5);
			vector<int> combinacion;
			combinacion.reserve(5);
			combinacion.push_back(aux[0]);
			combinacion.push_back(aux[1]);
			combinacion.push_back(aux[2]);
			combinacion.push_back(aux[3]);
			combinacion.push_back(aux[4]);
			mapa[combinacion]++;
		}
		int max = 0;
		map<vector<int>,int>::iterator it, itEnd = mapa.end();
		for(it = mapa.begin(); it != itEnd; it++)
			if(it->second > max) max = it->second;
		int frosh = 0;
		for(it = mapa.begin(); it != itEnd; it++)
			if(it->second == max) frosh+=it->second;
		cout << frosh << endl;
		cin >> n;
	}
	return 0;
}