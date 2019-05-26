//codigo propio
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct team{
	int n, score, tiempo, penalty[9];
	bool solved[9];
};

bool cmp(team team1, team team2){
	bool ans = team1.score != team2.score;
	if(ans) return team1.score > team2.score;
	ans = team2.tiempo != team1.tiempo;
	if(ans) return team2.tiempo > team1.tiempo;
	return team2.n > team1.n;
}

int main(){
	int N;
	cin >> N;
	cin.get();
	cin.get();
	string input;
	int n, problema, tiempo;
	char L;
	vector<team> teams;
	while(N--){
		teams.clear();
		while(getline(cin, input) && input[0]!='\0'){
			stringstream ss(input);
			ss >> n >> problema >> tiempo >> L;
			//cout << n << ' ' << problema << ' ' << tiempo << ' ' << L << endl; 
			problema--;
			bool doIt = true;
			int size = teams.size();
			int index;
			for(index = 0; index<size; index++)
				if(n==teams[index].n){
					doIt = false;
					break;
				}
			if(doIt){
				team aux;
				aux.n = n;
				aux.score = 0;
				aux.tiempo = 0;
				for(int i=0; i<9; i++){
					aux.penalty[i] = 0;
					aux.solved[i] = false;
				}
				teams.push_back(aux);
			}
			if(L == 'C' && !teams[index].solved[problema]){
				teams[index].score++;
				teams[index].solved[problema] = true;
				teams[index].tiempo += tiempo + teams[index].penalty[problema];
			}
			else if(L == 'I' && !teams[index].solved[problema])
				teams[index].penalty[problema] += 20;
		}
		sort(teams.begin(),teams.end(),cmp);
		int size = teams.size();
		for(int i=0; i<size; i++)
			cout << teams[i].n << ' ' << teams[i].score << ' ' << teams[i].tiempo << endl;

		if(N) cout << endl;
	}

	return 0;
}