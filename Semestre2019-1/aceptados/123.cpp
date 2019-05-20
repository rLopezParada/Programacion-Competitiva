//codigo propio
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class dir{
public:
	int title,
		pos;
};

class word{
public:
	string text;
	vector<dir> dirs;
};

vector<word> words;

bool cmp(int a, int b){
	return words[a].text < words[b].text;
}

int main(){
	vector<vector<int>> titles;
	string input;
	getline(cin, input);
	while(input[0]!=':'){
		word aux;
		aux.text = input;
		words.push_back(aux);
		getline(cin, input);
	}
	int nBanned = words.size();

	string palabra;
	int titleIndex = -1;
	vector<int> thisTitle;
	while(getline(cin, input)){
		titleIndex++;
		thisTitle.clear();
		int wordIndex;
		int len = input.length();
		for(int i=0; i<len; i++)
			input[i] = tolower(input[i]);
		stringstream ss(input);
		string palabra;
		bool existe;
		int pos = -1;
		while(ss >> palabra){
			pos++;
			existe = false;
			for(wordIndex = 0; wordIndex<words.size(); wordIndex++){
				if(palabra == words[wordIndex].text){
					existe = true;
					break;
				}
			}
			if(!existe){
				word aux;
				aux.text = palabra;
				words.push_back(aux);
			}
			dir aux;
			aux.title = titleIndex;
			aux.pos = pos;
			words[wordIndex].dirs.push_back(aux);
			thisTitle.push_back(wordIndex);
		}
		titles.push_back(thisTitle);
	}
	vector<int> orden;
	for(int i = nBanned; i < words.size(); i++){
		orden.push_back(i);
	}

	sort(orden.begin(), orden.end(), cmp);

	//por cada palabra valida
	int nWords = orden.size();
	for(int i = 0; i < nWords; i++){
		//por cada mencion dentro de la palabra
		vector<dir> dirs = words[orden[i]].dirs;
		int nDirs = dirs.size();
		for(int j=0; j < nDirs; j++){
			//printf de la oracion pero con la plabra en mayuscula
			vector<int> thisTitle = titles[dirs[j].title];
			int titleLength = thisTitle.size();

			int k = 0;
			if(k == dirs[j].pos){
				string palabra = words[thisTitle[k]].text;
				int len = palabra.length();
				for(int l=0; l < len; l++)
					palabra[l] = toupper(palabra[l]);
				cout << palabra;
			}
			else cout << words[thisTitle[k]].text;

			for(int k = 1; k < titleLength; k++){
				if(k == dirs[j].pos){
					string palabra = words[thisTitle[k]].text;
					int len = palabra.length();
					for(int l=0; l < len; l++)
						palabra[l] = toupper(palabra[l]);
					cout << ' ' << palabra;
				}
				else cout << ' ' << words[thisTitle[k]].text;
			}
			cout << endl;
		}
	}

	return 0;
}