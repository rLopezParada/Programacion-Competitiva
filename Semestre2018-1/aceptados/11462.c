#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
	return (int)(*(char*)a-*(char*)b);
}

int main(){
	int n,i;
	char edades[2000000];
	scanf("%d",&n);
	while(n){
		for(i=0;i<n;i++){
			scanf("%d",&edades[i]);
		}
		qsort(edades,n,sizeof(char),cmp);
		n--;
		for(i=0;i<n;i++){
			printf("%d ",edades[i]);
		}
		printf("%d\n",edades[i]);
		scanf("%d",&n);
	}
	return 0;
}