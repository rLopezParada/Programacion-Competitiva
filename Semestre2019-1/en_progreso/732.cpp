//codigo propio
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

string input, target, stack, seq;
deque<char> in, tar;
int len, nPush, nPop, maxOps;

bool go(){
	if(len!=target.length()) return false;
	string cheapCopy1 = input;
	string cheapCopy2 = target;
	sort(cheapCopy1.begin(),cheapCopy1.end());
	sort(cheapCopy2.begin(),cheapCopy2.end());
	return cheapCopy1==cheapCopy2;
}

void TLE(){
	//cout << "seq: " << seq << endl;
	if(nPush < maxOps){
		stack.push_back(in.front());
		in.pop_front();
		seq.push_back('i');
		nPush++;
		TLE();
	}
	if(nPop < maxOps && !stack.empty()){
		in.push_back(stack.back());
		stack.pop_back();
		seq.push_back('o');
		nPop++;
		TLE();
	}
	if(seq.size() == len && in==tar){
		int i, aux = len - 1;
		for(i=0; i<aux; i++){
			cout << (char)seq[i] << " "; 
		}
		cout << (char)seq[i] << endl;
		//cout << "accept: "<< seq << endl;
	}
	if(!seq.empty()){
		if(seq.back()=='i'){
			in.push_front(stack.back());
			stack.pop_back();
			seq.pop_back();
			nPush--;
		}
		else{
			stack.push_back(in.back());
			in.pop_back();
			seq.pop_back();
			nPop--;
		}
	}
}

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	while(cin >> input){
		cin >> target;
		len = input.length();
		cout << "[\n";
		if(go()){
			in.clear();
			tar.clear();
			stack.clear();
			seq.clear();
			for(int i=0; i<len; i++) in.push_back(input[i]);
			for(int i=0; i<len; i++) tar.push_back(target[i]);
			maxOps = len;
			len *= 2;
			nPush=0;
			nPop=0;
			TLE();
		}
		cout << "]\n";
	}
	return 0;
}