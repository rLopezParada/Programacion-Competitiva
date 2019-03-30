//codigo propio
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Pagina{
public:
	string url;
	int relevancia;
	Pagina(){}
	~Pagina(){}
};

bool compare(Pagina* a, Pagina* b){
	return (a->relevancia > b->relevancia);
}

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int T;
	cin>>T;

	vector<Pagina> lista(10);

	for(int i=0; i<10; i++)
		lista.emplace_back();

	vector<Pagina*> pointerVector(10);
	int highest;
	for(int n=0; n<T; n++){
		for(int i=0; i<10; i++){
			cin >> lista[i].url >> lista[i].relevancia;
			//cout << lista[i].url << " " << lista[i].relevancia << endl;
			pointerVector[i]=&lista[i];
		}
		stable_sort(pointerVector.begin(),pointerVector.end(),compare);
		cout << "Case #" << n+1 << ":\n" << pointerVector[0]->url << endl;
		highest = pointerVector[0]->relevancia;
		for(int i=1; i<10; i++){
			if(pointerVector[i]->relevancia==highest){
				cout << pointerVector[i]->url << endl;
			}
		}
	}

	return 0;
}