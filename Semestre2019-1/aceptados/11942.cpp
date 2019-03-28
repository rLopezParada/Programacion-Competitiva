//codigo propio
#include <iostream>
using namespace std;

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int N;
	cin>>N;
	int array[10];
	cout<<"Lumberjacks:\n";
	while(N>0){
		for(int i=0; i<10; i++)cin>>array[i];
		bool ordered = true;
		if(array[0]<array[1]){
			for(int i=1; i<9; i++){
				if(array[i]>array[i+1]){
					ordered = false;
					break;
				}
			}
		}
		else{
			for(int i=0; i<9; i++){
				if(array[i]<array[i+1]){
					ordered=false;
					break;
				}
			}
		}
		if(ordered){
			cout<<"Ordered\n";
		}
		else{
			cout<<"Unordered\n";
		}
		N--;
	}
	return 0;
}