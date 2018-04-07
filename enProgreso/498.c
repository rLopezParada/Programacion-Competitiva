#include <stdio.h>

long long int pot(long long int a, long long int b){
	if(b==0){
		return 1;
	}
	long long int n=1;
	int i;

	for(i=0;i<b;i++){
		n*=a;
	}
	return n;
}

int main(){

	char arr1[100000][1000];
	char arr2[100000][1000];

	int i,j,k,l,ncases;
	for(i=0;scanf("%[^\n]",arr1[i])!=EOF;i++){
		getchar();
		scanf("%[^\n]",arr2[i]);
		getchar();
	}
	ncases=i;

	char auxc1[20];
	char auxc2[20];
	int auxi1[500];
	int auxi2[500];
	int tam1,tam2,p;
	long long int y[500];
	for(i=0;i<ncases;i++){
		j=0;
		k=0;
		l=0;
		while(1){
			auxc1[l]=arr1[i][j];
			l++;
			j++;
			if(auxc1[l-1]==32){
				sscanf(auxc1,"%d",&auxi1[k]);
				
				k++;
				l=0;
			}
			else if(auxc1[l-1]==0){
				sscanf(auxc1,"%d",&auxi1[k]);
				
				k++;
				break;
			}
		}
		tam1=k;
		j=0;
		k=0;
		l=0;
		while(1){
			auxc2[l]=arr2[i][j];
			l++;
			j++;
			if(auxc2[l-1]==32){
				sscanf(auxc2,"%d",&auxi2[k]);
				k++;
				l=0;
			}
			else if(auxc2[l-1]==0){
				sscanf(auxc2,"%d",&auxi2[k]);
				k++;
				break;
			}
		}
		tam2=k;

		for(j=0;j<500;j++){
			y[j]=0;
		}

		for(j=0;j<tam2;j++){
			for(k=tam1-1,p=0;k>-1;k--,p++){
				y[j]+=(long long int)auxi1[k]*pot(auxi2[j],p);
			}
		}
		for(j=0;j<tam2-1;j++){
			printf("%lld ",y[j]);
		}
		printf("%lld\n",y[j]);
	}

	return 0;
}