//codigo propio
#include <iostream>
using namespace std;

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int nMonths, lines, currentMonth, month;
	double 	downPayment, initialDepreciation, dep,
			owes, value, initialValue, depreciation[100];

	for(;;){
		cin >> nMonths >> downPayment >> initialValue >> lines;
		//cout << nMonths << " " << downPayment << " " << initialValue << " " << lines << endl;
		if(nMonths<0) return 0;

		cin >> currentMonth >> initialDepreciation;
		lines--;
		for(int i=0; i<100; i++) depreciation[i] = initialDepreciation;

		while(lines>0){
			lines--;
			cin >> month >> dep;
			for(int i=month-1; i<100; i++) depreciation[i]=dep;
		}
		
		//check contents
		/*cout << currentMonth << " " << initialDepreciation << endl;
		for(int i=0; i<100; i++){
			cout << i+1 << " " << depreciation[i] << endl;
		}*/

		//ejecucion
		owes = initialValue;
		value = (initialValue + downPayment) * (1-initialDepreciation);
		for(currentMonth; currentMonth<nMonths && owes>=value; currentMonth++){
			owes -= initialValue / nMonths;
			value *= 1-depreciation[currentMonth];
		}
		if(currentMonth==1){
			cout << "1 month\n";
		}
		else{
			cout << currentMonth << " months\n";
		}
	}
}