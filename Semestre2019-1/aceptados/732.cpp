//codigo propio
#include <iostream>
#include <algorithm>
using namespace std;

string input, target, stack, seq, popped;
string::iterator it1, it2, it1End, it2End;
int len, maxOps;
char back;

void TLE(){
	//cout << "seq: " << seq << endl;
	if(it1 == it1End && it2 == it2End){
		int i, aux = maxOps - 1;
		for(i=0; i<aux; i++){
			cout << (char)seq[i] << " "; 
		}
		cout << (char)seq[i] << endl;
		//cout << "accept: "<< seq << endl;
		return;
	}
	if(it1 != it1End && it2 != it2End){	//primero i tal vez
		stack += *it1++;
		seq += 'i';
		TLE();
		it1--;
		seq.pop_back();
		stack.pop_back();
	}
	back = stack.back();
	if(!stack.empty() && back==*it2){	//luego o tal vez
		it2++;
		popped += back;
		stack.pop_back();
		seq += 'o';
		TLE();
		it2--;
		stack += popped.back();
		popped.pop_back();
		seq.pop_back();
	}
}

bool go(){
	if(len != target.length()) return false;
	string str1 = input, str2 = target;
	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	return str1==str2;
}

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	while(cin >> input){
		cin >> target;
		len = input.length();
		cout << "[\n";
		if(go()){
			stack.clear();
			seq.clear();
			popped.clear();
			it1 = input.begin();
			it1End = input.end();
			it2 = target.begin();
			it2End = target.end();
			maxOps = 2*len;
			TLE();
		}
		cout << "]\n";
	}
	return 0;
}