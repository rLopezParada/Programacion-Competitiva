#include <stdio.h>

long long int pot(int a, int b){
	long long int n=1;
	int i;
	for(i=0;i<b;i++){
		n*=a;
	}
	return n;
}

int main(){
	char input[5000];
	char batch[30];
	int arr1[3500];
	int arr2[3500];

	int i,j,p,tam1,tam2;
	long long int r;
	while(scanf("%[^\n]",input)!=EOF){
		getchar();
		i=j=tam1=tam2=0;
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
		i=j=0;
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
		for(i=0,r=0;i<tam2-1;i++){
			for(j=tam1-1,p=0;j>-1;j--,p++){
				r+=arr2[i]*pot(arr1[j],p);
			}
			printf("%lld ",r);
		}
		for(j=tam1-1,r=0,p=0;j>-1;j--,p++){
			r+=arr2[i]*pot(arr1[j],p);
		}
		printf("%lld\n",r);
	}
	return 0;
}