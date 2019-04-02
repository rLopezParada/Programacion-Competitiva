//codigo propio
#include <iostream>
#include <vector>
using namespace std;

enum side {LEFT, RIGHT};

class Queue{
private:
	vector<int> vec;
public:
	Queue(){}
	~Queue(){}
	void add(int largoAuto){
		vec.insert(vec.begin(),largoAuto);
	}
	void clear(){
		vec.clear();
	}
	int back(){
		return vec.back();
	}
	void pop(){
		vec.pop_back();
	}
	int size(){
		return vec.size();
	}
	int at(int i){
		return vec[i];
	}
};

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int c, l, m;
	int largoAuto;
	string input;
	Queue leftQueue;
	Queue rightQueue;
	int ladoActual;
	int largoAcumulado;
	int viajes;

	cin >> c;
	while(c){
		c--;
		cin >> l >> m;
		l*=100;
		while(m){	//leer input
			m--;
			cin >> largoAuto >> input;
			largoAuto;

			if(input[0]=='l') leftQueue.add(largoAuto);
			else rightQueue.add(largoAuto);
		}
		//ejecucion
		ladoActual = LEFT;
		largoAcumulado = 0;
		viajes = 0;
		while(leftQueue.size()>0 || rightQueue.size()>0){
			if(ladoActual==LEFT){
				while(leftQueue.size()>0 && largoAcumulado + leftQueue.back() <= l){
					largoAcumulado += leftQueue.back();
					leftQueue.pop();
				}
				ladoActual = RIGHT;
				largoAcumulado = 0;
				viajes++;
			}
			else{
				while(rightQueue.size()>0 && largoAcumulado + rightQueue.back() <= l){
					largoAcumulado += rightQueue.back();
					rightQueue.pop();
				}
				ladoActual = LEFT;
				largoAcumulado = 0;
				viajes++;
			}
		}
		leftQueue.clear();
		rightQueue.clear();
		cout << viajes << endl;
	}
	return 0;




}