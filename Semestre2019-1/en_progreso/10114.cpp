//codigo propio
#include <iostream>
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	/*freopen("output.txt", "w", stdout);*/
 	double downPayment, initialValue, owes, value;
	int nMonths, nDepreciations, currentMonth;
	double depreciation[101];
	int active[101];
	int slot;
	for(;;){
		cin >> nMonths >> downPayment >> initialValue >> nDepreciations;
		if(nMonths<0) break;
		for(int i=0; i<101; i++){
			depreciation[i]=0;
			active[i]=0;
		}
		for(int i=0; i<nDepreciations; i++){
			cin >> slot;
			cin >> depreciation[slot];
			for(int j=slot; j>-1 && active[j]!=1; j--){
				depreciation[j]=depreciation[slot];
				active[j]=1;
			}
		}
		for(int i=slot; i<=nMonths; i++){
			depreciation[i]=depreciation[slot];
			active[i]=1;
		}
		/*for(int i=0; i<101; i++){
			cout << i << " " << depreciation[i] << " " << active[i] << endl;
		}*/
		owes = initialValue;
		value = initialValue + downPayment;
		for(currentMonth=0; owes < value; currentMonth++){
			value *= 1-depreciation[currentMonth];
			owes -= initialValue / nMonths;
		}
		cout << currentMonth << endl;
	}
	return 0;
}