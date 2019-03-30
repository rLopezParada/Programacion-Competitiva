//codigo propio
#include <iostream>
using namespace std;

enum axis {PX, NX, PY, NY, PZ, NZ, NO};
//X positivo, X negativo, Y positivo ...

class Beam{
private:
	char dir;	//direccion en que apunta el fierro
public:
	Beam(){
		dir = PX;
	}
	~Beam(){}
	void bend(char a){
		if(a==NO)return;
		else if(dir==PX){
			switch(a){
				case PY:
					dir=PY;
					break;
				case NY:
					dir=NY;
					break;
				case PZ:
					dir=PZ;
					break;
				default:
					dir=NZ;
			}
		}
		else if(dir==NX){
			switch(a){
				case PY:
					dir=NY;
					break;
				case NY:
					dir=PY;
					break;
				case PZ:
					dir=NZ;
					break;
				default:
					dir=PZ;
			}
		}else if(dir==PY){
			switch(a){
				case PY:
					dir=NX;
					break;
				case NY:
					dir=PX;
			}
		}else if(dir==NY){
			switch(a){
				case PY:
					dir=PX;
					break;
				case NY:
					dir=NX;
			}
		}else if(dir==PZ){
			switch(a){
				case PZ:
					dir=NX;
					break;
				case NZ:
					dir=PX;
			}
		}
		else if(dir==NZ){
			switch(a){
				case PZ:
					dir=PX;
					break;
				case NZ:
					dir=NX;
			}
		}
	}
	char getDir(){
		return dir;
	}
};

char convert(string input){
	switch(input[0]){
		case '+':
			switch(input[1]){
				case 'x':
					return PX;
				case 'y':
					return PY;
				default:
					return PZ;
			}
		case '-':
			switch(input[1]){
				case 'x':
					return NX;
				case 'y':
					return NY;
				default:
					return NZ;
			}
		default:
			return NO;
	}
}

string back(char a){
	switch(a){
		case PX:
			return "+x";
		case NX:
			return "-x";
		case PY:
			return "+y";
		case NY:
			return "-y";
		case PZ:
			return "+z";
		default:
			return "-z";
	}
}

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int L;
	cin >> L;
	string input;
	Beam* fierro;
	while(L!=0){
		fierro = new Beam();
		while(L>1){
			L--;
			cin >> input;
			fierro -> bend(convert(input));
		}
		cin >> L;
		cout << back(fierro->getDir()) << endl;
		delete fierro;
	}
	return 0;
}