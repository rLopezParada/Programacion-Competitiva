//codigo propio
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	cin.get();
	cin.get();
	string input;
	while(n--){
		int total = 0;
		unordered_map<string, int> mapa;
		while(getline(cin, input) && input[0]!='\0'){
			total++;
			mapa[input]++;
		}
		vector<pair<string,int>> res;
		unordered_map<string, int>::iterator it, itEnd = mapa.end();
		for(it = mapa.begin(); it != itEnd; it++)
			res.push_back(*it);
		sort(res.begin(), res.end());
		for(int i=0; i<res.size(); i++)
			printf("%s %.4lf\n", res[i].first.c_str(), res[i].second*100/(double)total);
		if(n) cout << endl;
	}
	return 0;
}