#include <iostream>
#include <set>
#include <vector>
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
			cout << aux << endl;
		}
		for(int i = 0; i < SB; i++){
			cin >> aux;
			blues.insert(aux);
			cout << aux << endl;
		}
		cout << endl;
		for(int i=0; i<SG ; i++){
			cout << *(greens.begin()) << endl;
			greens.erase(greens.begin());
		}
		cout << endl;
		for(int i=0; i<SB ; i++){
			cout << *(blues.begin()) << endl;
			blues.erase(blues.begin());
		}
		cout << endl;

		//battle
		vector<int> greenSide, blueSide;
		greenSide.reserve(B);
		blueSide.reserve(B);
		while(!greens.empty() && !blues.empty()){
			multiset<int,greater<int>>::iterator it, itEnd;
			while(!greenSide.empty() && !blueSide.empty()){
				it = greens.begin();
				itEnd = greens.end();
			}
			do{
				multiset<int,greater<int>>::iterator it, itEnd;
				it = greens.begin();
				itEnd = greens.end();
				for(int i = 0; i < B; i++){
					if(it == itEnd) break;
					greenSide.push_back(*it);
					it++;
				}
				int initialG = greenSide.size();
				it = blues.begin();
				itEnd = blues.end();
				for(int i=0; i < B; i++){
					if(it == itEnd) break;
					blueSide.push_back(*it);
					it++;
				}
				int initialB = blueSide.size();


			}while(!greenSide.empty() && !blueSide.empty());
		}

		//result
		/*if(greens.empty() && blues.empty()) cout << "green and blue died\n";
		else if(blues.empty()){
			cout << "green wins\n";
		}
		else{
			cout << "blue wins\n";
		}*/
		if(N) cout << endl;
	}
	return 0;
}