#include <stdio.h>

long long int pot(int a, int b){
	if(a==0)return 0;
	long long int n=1;
	int i;
	for(i=0;i<b;i++){
		n*=a;
	}
	return n;
}

int main(){
	char input[5000];
	char batch[50];
	int arr1[3500];
	int arr2[3500];
	int i,j,l,tam1,tam2;
	long long int r;
	while(scanf("%[^\n]",input)!=EOF){
		getchar();
		i=j=tam1=0;
		while(1){
			batch[i]=input[j];
			if(input[j]==32){
					sscanf(batch,"%d",&arr1[tam1]);
					tam1++;
					i=-1;
				}
				else if(input[j]==0){
					sscanf(batch,"%d",&arr1[tam1]);
					tam1++;
					break;
				}
			i++;
			j++;
		}
		scanf("%[^\n]",input);
		getchar();
		i=j=tam2=0;
		while(1){
			batch[i]=input[j];
			if(input[j]==32){
					sscanf(batch,"%d",&arr2[tam2]);
					tam2++;
					i=-1;
				}
				else if(input[j]==0){
					sscanf(batch,"%d",&arr2[tam2]);
					tam2++;
					break;
				}
			i++;
			j++;
		}

		l=1;
		r=0;
		r+=arr1[tam1-1];
		for(j=tam1-2;j>-1;j--){
			r+=arr1[j]*pot(arr2[0],l);
			l++;
		}
		printf("%lld",r);

		for(i=1;i<tam2;i++){
			l=1;
			r=0;
			r+=arr1[tam1-1];
			for(j=tam1-2;j>-1;j--){
				r+=arr1[j]*pot(arr2[i],l);
				l++;
			}
			printf(" %lld",r);
		}
		printf("\n");
	}
	return 0;

}