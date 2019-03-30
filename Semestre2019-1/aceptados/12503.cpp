//codigo propio
#include <iostream>
using namespace std;

class Data{
private:
	int n,position;
	string* history;
public:
	Data(){
		history = new string[100];
		position=0;
		n=0;
	}
	~Data(){
		delete[] history;
	}
	void take(string input){
		history[n] = input;
		move(n);
		n++;
	}
	void move(int index){	//ejecuta instrucciones
		switch(history[index][0]){
			case 'R':
				position++;
				break;
			case 'L':
				position--;
				break;
			default:
				string substr = history[index].substr(8,3);
				int newIndex = stoi(substr) - 1;
				move(newIndex);	//recursivo para instrucciones "SAME AS #"
		}
	}
	int getPosition(){
		return position;
	}
};

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	Data* data;
	int T,n;
	string input;
	cin >> T;
	while(T>0){
		T--;
		cin >> n;
		data = new Data();
		for(int i=0; i<n; i++){
			cin >> input;
			if(input[0]=='S'){
				string input1, input2;
				cin >> input1;
				cin >> input2;
				input=input+" "+input1+" "+input2;
			}
			data->take(input);
		}
		cout << data->getPosition() << endl;
		delete data;
	}
	return 0;
}