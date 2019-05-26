#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct persona{
	string nombre;
	int dia, mes, anyo;
};

int *arr;
vector<persona> clase;

bool cmp(int a, int b){
	persona *per1 = &clase[arr[a]];
	persona *per2 = &clase[arr[b]];
	bool ans = per1->anyo != per2->anyo;
	if(ans) return per1->anyo < per2->anyo;
	ans = per1->mes != per2->mes;
	if(ans) return per1->mes < per2->mes;
	return per1->dia < per2->dia;
}

int main(){
	int n;
	cin >> n;
	int arreglo[n];
	arr = arreglo;
	for(int i=0; i<n; i++)
		arr[i] = i;
	clase.reserve(n);
	for(int i=0; i<n; i++){
		persona aux;
		cin >> aux.nombre >> aux.dia >> aux.mes >> aux.anyo;
		cout << aux.nombre << ' ' << aux.dia << ' ' << aux.mes << ' ' << aux.anyo << endl;
		clase.push_back(aux);
	}
	cout << endl;
	stable_sort(arr, arr+n, cmp);
	for(int i=0; i<n; i++){
		persona aux = clase[arr[i]];
		cout << aux.nombre << ' ' << aux.dia << ' ' << aux.mes << ' ' << aux.anyo << endl;
	}
	return 0;
}