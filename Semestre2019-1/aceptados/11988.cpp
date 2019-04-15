//codigo propio
#include <iostream>
#include <list>
using namespace std;

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	list<char> lista;
	list<char>::iterator it = lista.begin();
	char c;
	for(;;){
		c = getchar();
		if(c==']') it = lista.end();
		else if(c=='[') it = lista.begin();
		else if(c=='\n'){
			list<char>::iterator itEnd = lista.end();
			for(it=lista.begin(); it!=itEnd; it++)
				cout << *it;
			cout << endl;
			lista.clear();
		}
		else if(c==EOF){
			if(lista.empty()) return 0;
			list<char>::iterator itEnd = lista.end();
			for(it=lista.begin(); it!=itEnd; it++)
				cout << *it;
			cout << endl;
			return 0;
		}
		else lista.insert(it,c);
	}
}