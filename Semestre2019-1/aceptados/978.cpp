//codigo propio
#include <iostream>
#include <set>
#include <vector>
#include <iterator>
using namespace std;

int main(){
	int N, B, SG, SB, aux;
	cin >> N;
	while(N--){
		//read imput
		cin >> B >> SG >> SB;
		multiset<int,greater<int>> greens, blues;
		for(int i = 0; i < SG; i++){
			cin >> aux;
			greens.insert(aux);
		}
		for(int i = 0; i < SB; i++){
			cin >> aux;
			blues.insert(aux);
		}

		//battle
		vector<int> greenRemnants, blueRemnants;
		greenRemnants.reserve(B);
		blueRemnants.reserve(B);
		while(!greens.empty() && !blues.empty()){
			multiset<int,greater<int>>::iterator it1, itEnd1, it2, itEnd2;
			it1 = greens.begin();
			itEnd1 = greens.end();
			it2 = blues.begin();
			itEnd2 = blues.end();
			int i;
			for(i = 0; i < B; i++){
				if(it1 == itEnd1 || it2 == itEnd2) break;
				int delta = *it1 - *it2;
				it1++;
				it2++;
				if(delta){
					if(delta > 0) greenRemnants.push_back(delta);
					else blueRemnants.push_back(-delta);
				}
			}
			it1 = greens.begin();
			advance(it1, i);
			greens.erase(greens.begin(), it1);
			it2 = blues.begin();
			advance(it2, i);
			blues.erase(blues.begin(), it2);

			int size = greenRemnants.size();
			for(i = 0; i < size; i++)
				greens.insert(greenRemnants[i]);
			size = blueRemnants.size();
			for(i = 0; i < size; i++)
				blues.insert(blueRemnants[i]);

			greenRemnants.clear();
			blueRemnants.clear();
		}

		//result
		if(greens.empty() && blues.empty()) cout << "green and blue died\n";
		else if(blues.empty()){
			cout << "green wins\n";
			multiset<int,greater<int>>::iterator it, itEnd = greens.end();
			for(it = greens.begin(); it != itEnd; it++)
				cout << *it << endl;
		}
		else{
			cout << "blue wins\n";
			multiset<int,greater<int>>::iterator it, itEnd = blues.end();
			for(it = blues.begin(); it != itEnd; it++)
				cout << *it << endl;
		}
		if(N) cout << endl;
	}
	return 0;
}