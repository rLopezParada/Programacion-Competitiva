#include <stdio.h>

int main(){
	int cases,n,i,j,aux,indice;
	scanf("%d",&cases);
	getchar();

	int arr[3];

	for(n=1;n<=cases;n++){
		scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
		getchar();

		indice=1;
		for(i=0;i<3;i++){
			indice=i;
			for(j=i+1;j<3;j++){
				if(arr[j]<arr[indice]){
					indice=j;
				}
			}
			if(indice!=j){
				aux=arr[i];
				arr[i]=arr[indice];
				arr[indice]=aux;
			}
		}
		printf("Case %d: %d\n",n,arr[1]);
	}

	return 0;
}