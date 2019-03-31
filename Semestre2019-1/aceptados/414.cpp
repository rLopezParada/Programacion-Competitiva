//codigo propio
#include <iostream>
using namespace std;

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int N, gap, voids, spaces[12];
	char image[12][25];

	for(;;){
		cin>>N;
		getchar();
		if(N==0)return 0;

		for(int i=0; i<N; i++){
			for(int j=0; j<25; j++){
				image[i][j]=getchar();
			}
			getchar();
		}
		for(int i=0; i<N; i++){
			spaces[i]=0;
		}

		/*for(int i=0; i<N; i++){
			for(int j=0; j<25; j++){
				cout << image[i][j];
			}
			cout << endl;
		}
		cout << endl;*/

		for(int i=0; i<N; i++){
			for(int j=0; j<25; j++){
				if(image[i][j]==' ')
					spaces[i]++;
			}
		}

		gap=23;
		for(int i=0; i<N; i++){
			if(spaces[i]<gap)
				gap=spaces[i];
		}
		voids=0;
		for(int i=0; i<N; i++){
			voids += spaces[i] - gap;
		}
		cout << voids << endl;
	}
}