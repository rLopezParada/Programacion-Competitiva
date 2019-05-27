#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct squad{
	string name;
	int points, goalsScored, goalsSuffered, gamesPlayed;
};

bool cmp(squad a, squad b){
	bool ans = a.points != b.points;
	if(ans) return a.points < b.points;
	int goalDifference1 = a.goalsScored-a.goalsSuffered;
	int goalDifference2 = b.goalsScored-b.goalsSuffered;
	ans = goalDifference1 != goalDifference2;
	if(ans) return goalDifference1 < goalDifference2;
	ans = a.goalsScored != b.goalsScored;
	if(ans) return a.goalsScored < b.goalsScored;
	return a.name < b.name;
}

int main(){
	bool first = true;
	int T, G;
	cin >> T >> G;
	vector<squad> teams;
	while(T){
		if(first) first = false;
		else{
			teams.clear();
			cout << endl;
		}
		teams.reserve(T);
		for(int i=0; i<T; i++){
			teams.emplace_back();
			cin >> teams[i].name;
			teams[i].points = 0;
			teams[i].goalsScored = 0;
			teams[i].goalsSuffered = 0;
			teams[i].gamesPlayed = 0;
			cout << teams[i].name << endl;
		}
		for(int i=0; i<G; i++){
			string name1, name2;
			int goalsScored1, goalsScored2;
			cin >> name1 >> goalsScored1;
			cin.ignore(3, EOF);
			cin >> goalsScored2 >> name2;
			cout << name1 << ' ' << goalsScored1 << ' ' << goalsScored2 << ' ' << name2 << endl;
			int j = 0;
			while(name1!=teams[j].name) j++;
			int k = 0;
			while(name2!=teams[k].name) k++;
			if(goalsScored1 == goalsScored2){
				teams[j].points += 1;
				teams[k].points += 1;
			}
			else if(goalsScored1 > goalsScored2) teams[j].points += 3;
			else teams[k].points += 3;
			teams[j].goalsScored += goalsScored1;
			teams[j].goalsSuffered += goalsScored2;
			teams[j].gamesPlayed++;
			teams[k].goalsScored += goalsScored2;
			teams[k].goalsSuffered += goalsScored1;
			teams[k].gamesPlayed++;
		}
		sort(teams.begin(), teams.end(), cmp);
		int totalPoints = 0;
		for(int i=0; i<T; i++)
			totalPoints += teams[i].points;
		for(int i=0; i<T; i++){
			cout << teams[i].name << ' ' << teams[i].points
			<< ' ' << teams[i].gamesPlayed << ' ' << teams[i].goalsScored
			<< ' ' << teams[i].goalsSuffered << ' ' << teams[i].goalsScored - teams[i].goalsSuffered
			<< ' ' << (float)teams[i].points/(float)totalPoints/100 << endl;
		}
		cin >> T >> G;
	}
	return 0;
}