//codigo propio
#include <iostream>
#include <stack>
using namespace std;

int main(){
	int n;
	string input;
	bool matriz[26][26];
	cin >> n;
	cin.get();
	for(int i=0; i<n; i++){
		for(int j=0; j<26; j++)
			for(int k=0; k<26; k++)
				matriz[j][k] = false;
		stack<char> stk;
		getline(cin, input);
		int len = input.length();
		for(int j=0; j<len; j++)
			input[j] -= 65;
		stk.push(input[0]);
		for(int j=1; j<len; j++){
			char top = stk.top();
			char actual = input[j];
			if(top == actual) stk.pop();
			else{
				stk.push(actual);
				matriz[top][actual] = true;
				matriz[actual][top] = true;
			}
		}
		cout << "Case " << i+1 << endl;
		for(int j=0; j<26; j++){
			int total = 0;
			for(int k=0; k<26; k++){
				if(matriz[j][k] == true){
					total++;
				}
			}
			if(total){
				char letra = (char)(j+65);
				cout << letra << " = " << total << endl;
			}
		}
	}
	return 0;
}