//codigo propio
#include <iostream>
#include <vector>
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	/*freopen("output.txt", "w", stdout);*/

	vector<string> vec;
	string input;
	string aux;
	bool mis;
	while(getline(cin,input)){

		if(input=="end") break;

		for(int i=0; i<input.length(); i++){
			mis = true;

			for(int j=0; j<vec.size() && mis; j++){

				cout << input[i] << " " << vec[j].back() << endl;
				if(input[i]<=vec[j].back()){
					cout << input[i] << endl;
					cout << vec[j].back();
					aux = vec[j];
					cout << aux << endl;
					aux.push_back(input[i]);
					vec.erase(vec.begin()+j);
					vec.insert(vec.begin()+j, aux);
					mis=false;
					cout << aux << endl;
				}
			}

			if(mis){
				aux[0] = input[i];
				aux[1] = '\0';
				vec.push_back(aux);
			}
		}

		for(int i=0; i<vec.size(); i++){
			//cout << vec[i] << endl;
		}
		vec.clear();
	}

	return 0;
}