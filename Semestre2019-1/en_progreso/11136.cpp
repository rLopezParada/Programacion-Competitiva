//codigo propio
#include <iostream>
#include <set>
using namespace std;

int main(){
	int n, k, aux;
	unsigned long long int total;
	multiset<int> bills;
	cin >> n;
	while(n){
		total = 0;
		for(int i = 0; i < n; i++){
			cin >> k;
			for(int j = 0; j < k; j++){
				cin >> aux;
				bills.insert(aux);
			}
			multiset<int>::iterator end = bills.end();
			end--;
			multiset<int>::iterator begin = bills.begin();
			total += *end - *begin;
			bills.erase(end);
			bills.erase(begin);
		}
		bills.clear();
		cout << total << endl;
		cin >> n;
	}
	return 0;
}