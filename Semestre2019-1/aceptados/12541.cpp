//codigo propio
#include <iostream>
#include <algorithm>
using namespace std;

struct persona{
	string nombre;
	int dia, mes, anyo;
};

bool cmp(persona a, persona b){
	bool ans = a.anyo!=b.anyo;
	if(ans) return a.anyo > b.anyo;
	ans = a.mes!=b.mes;
	if(ans) return a.mes > b.mes;
	return a.dia > b.dia;
}

int main(){
	int n;
	cin >> n;
	persona clase[n];
	for(int i=0; i<n; i++)
		cin >> clase[i].nombre >> clase[i].dia >> clase[i].mes >> clase[i].anyo;
	sort(clase, clase+n, cmp);
	cout << clase[0].nombre << endl << clase[n-1].nombre << endl;
	return 0;
}