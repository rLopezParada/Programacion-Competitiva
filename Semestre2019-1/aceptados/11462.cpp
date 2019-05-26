//codigo propio
#include <iostream>
#include <algorithm>
using namespace std;
#define empires 2000000

int main(){
	int n;
	scanf("%d", &n);
	char ageOf[empires];
	while(n){
		for(int i=0; i<n; i++)
			scanf("%d", &ageOf[i]);
		sort(ageOf, ageOf+n);
		printf("%d", ageOf[0]);
		for(int i=1; i<n; i++)
			printf(" %d", ageOf[i]);
		scanf("%d", &n);
		printf("\n");
	}
	return 0;
}