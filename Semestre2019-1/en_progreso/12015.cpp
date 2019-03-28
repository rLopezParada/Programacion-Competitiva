//codigo propio
#include <iostream>
#include <vector>
using namespace std;

class Pagina{
public:
	string* url;
	int relevancia;
	Pagina(){
		url = new string();
	}
	~Pagina(){}
};

int main(){
	int T;
	cin>>T;

	vector<Pagina> lista(10);
	for(int i=0; i<10; i++)
		lista.emplace_back();

	for(int n=0; n<T; n++){
		for(int i=0; i<10; i++){
		}
	}




	return 0;
}