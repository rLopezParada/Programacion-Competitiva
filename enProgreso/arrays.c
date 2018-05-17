#include <stdio.h>
#include <stdlib.h>

struct numero{
	long double value;
	char string[100];
};

typedef struct numero num;

int cmp(const void *a, const void *b){
	long double r = (*(num*)a).value-(*(num*)b).value;
	if(r<0){
		return -1;
	}
	else if(r>0){
		return 1;
	}
	return 0;
}

int main(){
	char input[5000];
	int arr1[3500];
	char batch[100];
	int i,j,k,n,ncases,tam;

	scanf("%d",&ncases);
	getchar();

	for(n=0;n<ncases;n++){
		getchar();
		scanf("%[^\n]",input);
		getchar();
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
		
		i=j=k=0;
		while(i<tam){
			batch[j]=input[k];
			if(input[k]==32 || input[k]==0){
				sscanf(batch,"%Lf",&v[i].value);
				sscanf(batch,"%s",v[i].string);
				i++;
				j=-1;
			}
			k++;
			j++;
		}

		qsort(v,tam,sizeof(num),cmp);

		for(i=0;i<tam;i++){
			printf("%s\n",v[arr1[i]-1].string);
		}
		free(v);
	}

	return 0;
}