//codigo propio
#include <iostream>

using namespace std;

int main(){
	int T;
	cin>>T;
	int array[3];
	for(int n=0; n<T; n++){
		cin>>array[0]>>array[1]>>array[2];
		for(int i=1; i<3; i++){	//insertion sort
			for(int j=i; j>0; j--){
				if(array[j-1]>array[j]){
					int aux=array[j];
					array[j]=array[j-1];
					array[j-1]=aux;
				}
			}
		}
		cout<<"Case "<<n+1<<": "<<array[1]<<endl;
	}
	return 0;
}