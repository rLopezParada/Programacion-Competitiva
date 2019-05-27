//codigo propio
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
	if(ans) return a.points > b.points;
	int goalDifference1 = a.goalsScored-a.goalsSuffered;
	int goalDifference2 = b.goalsScored-b.goalsSuffered;
	ans = goalDifference1 != goalDifference2;
	if(ans) return goalDifference1 > goalDifference2;
	ans = a.goalsScored != b.goalsScored;
	if(ans) return a.goalsScored > b.goalsScored;
	string *src, str1, str2;
	src = &a.name;
	int size = a.name.length();
	for(int i=0; i<size; i++)
		str1 += tolower(src->at(i));
	src = &b.name;
	size = b.name.length();
	for(int i=0; i<size; i++)
		str2 += tolower(src->at(i));
	return str1 < str2;
}

bool iguales(squad a, squad b){
	return (a.points == b.points &&
		a.goalsScored == b.goalsScored &&
		a.goalsScored - a.goalsSuffered == b.goalsScored - b.goalsSuffered);
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
			squad aux;
			aux.points = 0;
			aux.goalsScored = 0;
			aux.goalsSuffered = 0;
			aux.gamesPlayed = 0;
			cin >> aux.name;
			teams.push_back(aux);
		}
		for(int i=0; i<G; i++){
			string name1, name2;
			int goalsScored1, goalsScored2;
			cin >> name1 >> goalsScored1;
			cin.ignore(3, EOF);
			cin >> goalsScored2 >> name2;
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
		squad anterior = teams[0];
		for(int i=0; i<T; i++){
			if(i && iguales(teams[i],anterior)) printf("%4c",' ');
			else{
				printf("%2d. ", i+1);
				anterior = teams[i];
			}
			printf("%15s%4d%4d%4d%4d%4d", teams[i].name.c_str(), teams[i].points, teams[i].gamesPlayed,
				teams[i].goalsScored, teams[i].goalsSuffered, teams[i].goalsScored - teams[i].goalsSuffered);
			if(teams[i].gamesPlayed) printf("%7.2lf\n", (double)teams[i].points*100/(3*teams[i].gamesPlayed));
			else printf("%7s\n", "N/A");
		}
		cin >> T >> G;
	}
	return 0;
}