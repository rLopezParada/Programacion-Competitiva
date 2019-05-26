#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct equipo{
	int n, penalty[9];
	bool solved[9];
};

bool cmp(equipo team1, equipo team2){
	/*int score1 = 0,
		score2 = 0;
	for(int i=0; i<9; i++){
		if(team1.solved[i]) score1++;
		if(team2.solved[i]) score2++;
	}
	int d = score2 - score1;
	if(d==0){
		score1 = 0;
		score2 = 0;
		for(int i=0; i<9; i++){
			if(team1.solved[i]) score1 += team1.penalty[i];
			if(team2.solved[i]) score2 += team2.penalty[i];
		}
		d = score1 - score2;
	}
	if(d==0){
		return team1.n > team2.n;
	}

	return score1 > score2;*/
	int score1 = 0,
		score2 = 0;
	for(int i=0; i<9; i++){
		if(team1.solved[i]) score1++;
		if(team2.solved[i]) score2++;
	}
	if(score1 > score2) return true;
	else if(score1 < score2) return false;
	score1 = 0;
	score2 = 0;
	for(int i=0; i<9; i++){
		if(team1.solved[i]) score1 += team1.penalty[i];
		if(team2.solved[i]) score2 += team2.penalty[i];
	}
	if(score2 > score1) return true;
	else if(score2 < score1) return false;
	return team1.n < team2.n;
}

int main(){
	int N;
	cin >> N;
	cin.get();
	cin.get();
	string input;
	int team, problema, tiempo;
	char c;
	vector<equipo> teams;
	while(N--){
		teams.clear();
		int index, size;
		//cout << endl;
		while(getline(cin, input) && input[0]!='\0'){
			stringstream ss(input);
			ss >> team >> problema >> tiempo >> c;
			//cout << team << ' ' << problema << ' ' << tiempo << ' ' << c << endl;
			bool doIt = true;
			size = teams.size();
			for(index = 0; index < size; index++){
				if(teams[index].n == team){
					doIt = false;
					break;
				}
			}
			if(doIt){
				equipo aux;
				aux.n = team;
				for(int i=0; i<9; i++){
					aux.penalty[i] = 0;
					aux.solved[i] = false;
				}
				teams.push_back(aux);
			}
			if(c == 'C' && !teams[index].solved[problema]){
				teams[index].solved[problema] = true;
				teams[index].penalty[problema] += tiempo;
			}
			else if(c == 'I' && !teams[index].solved[problema]){
				teams[index].penalty[problema] += 20;
			}
		}
		sort(teams.begin(), teams.end(), cmp);
		size = teams.size();
		for(int i=0; i<size; i++){
			equipo aux = teams[i];
			int solved = 0;
			int penalty = 0;
			for(int j=0; j<9; j++){
				if(aux.solved[j]){
					penalty += aux.penalty[j];
					solved++;
				}
			}
			cout << teams[i].n << ' ' << solved << ' ' << penalty << endl;
		}
		if(N) cout << endl;
	}
	return 0;
}