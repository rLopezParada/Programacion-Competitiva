#include <iostream>
#include <vector>
using namespace std;

void add(vector<string>* vec, char c, int n){
	string str = vec -> at(n);
	str.push_back(c);
	vec -> erase(vec -> begin() + n);
	vec -> insert(vec -> begin() + n, str);
}

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/

	bool miss;
	int caso = 0;
	string input;
	vector<string> vec;
	for(;;){
		//reading input
		getline(cin,input);
		if(input=="end") return 0;
		caso++;
		//execution
		for(int i=0; i<input.length(); i++){
			if(vec.empty()){	//first element
				string aux;
				aux = input[0];
				vec.push_back(aux);
			}
			else{	//elements after the first
				miss = true;
				for(int j=0; j<vec.size(); j++){
					if(input[i]<=vec[j].back()){
						add(&vec, input[i], j);
						miss = false;
						break;
					}
				}
				if(miss){
					string aux;
					aux = input[i];
					vec.push_back(aux);
				}
			}
		}
		cout << "Case " << caso << ": " << vec.size() << endl;
		vec.clear();
	}
}