#include <stdio.h>
#include <stdlib.h>

struct numero{
	double value;
	char string[100];
};

typedef struct numero num;

int main(){
	char input[5000];
	scanf("%[^\n]",input);
	getchar();
	int i,j,k,tam;

	int arr1[3500];
	char batch[100];
	i=j=tam=0;
	while(1){
		batch[i]=input[j];
		if(input[j]==32){
			sscanf(batch,"%d",&arr1[tam]);
			tam++;
			i=-1;
		}
		else if(input[j]==0){
			sscanf(batch,"%d",&arr1[tam]);
			tam++;
			break;
		}
		i++;
		j++;
	}

	num* v = (num*)malloc(tam*sizeof(num));
	
	scanf("%[^\n]",input);
	getchar();
	
	j=0;
	k=0;
	i=0;
	while(i<tam){
		batch[j]=input[k];
		if(input[k]==32 || input[k]==0){
			sscanf(batch,"%lf",&v[i].value);
			sscanf(batch,"%s",v[i].string);
			i++;
			j=-1;
		}
		k++;
		j++;
	}

	for(i=0;i<tam;i++){
		printf("%lf\n",v[i].value);
		printf("%s\n",v[i].string);
	}

	return 0;
}