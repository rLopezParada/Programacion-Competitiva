//codigo propio
#include <iostream>
using namespace std;

struct soldier{
	int left, right;
};

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int S, B, L, R, thisRight, thisLeft;
	soldier army[100000];
	for(;;){
		cin >> S >> B;
		if(S==0) return 0;
		for(int i=0; i<S; i++){
			army[i].left = i-1;
			army[i].right = i+1;
		}
		for(int i=0; i<B; i++){
			cin >> L >> R;
			L--;
			R--;
			thisLeft = army[L].left;
			thisRight = army[R].right;

			if(-1<thisRight && thisRight<S) army[thisRight].left = thisLeft;
			if(-1<thisLeft && thisLeft<S) army[thisLeft].right = thisRight;

			if(-1<thisLeft) cout << thisLeft+1 << " ";
			else cout << "* ";
			if(thisRight<S) cout << thisRight+1 << endl;
			else cout << "*\n";
		}
		cout << "-\n";
	}
	return 0;
}