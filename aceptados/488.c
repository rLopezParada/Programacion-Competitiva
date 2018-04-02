#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);

	int a[n];
	int f[n];
	int i,j,k,l;

	for(i=0;i<n;i++){
		scanf("%d%d",&a[i],&f[i]);
	}

	int p,q;
	p=n-1;
	q=f[n-1]-1;

	for(i=0;i<n;i++){

		for(j=0;j<f[i];j++){
			
			for(k=1;k<=a[i];k++){
				for(l=1;l<=k;l++){
					printf("%d",k);
				}
				printf("\n");
			}
			k=k-2;
			for(k;k>0;k--){
				for(l=1;l<=k;l++){
					printf("%d",k);
				}
				printf("\n");
			}
			if(i!=p || j!=q){
				printf("\n");
			}
		}
	}
	return 0;
}