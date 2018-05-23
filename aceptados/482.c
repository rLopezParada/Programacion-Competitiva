#include <stdio.h>
#include <stdlib.h>

struct numero{
	long double value;
	char string[100];
};

typedef struct numero num;

int main(){
	char input[5000];
	int arr1[3500];
	char batch[100];
	int i,j,k,n,ncases,tam;
	num* v;
	int* arr2;
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

		arr2 = (int*)malloc(tam*sizeof(int));

		for(i=0;i<tam;i++){
			arr2[arr1[i]-1]=i;
		}

		v = (num*)malloc(tam*sizeof(num));
		
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

		for(i=0;i<tam;i++){
			printf("%s\n",v[arr2[i]].string);
		}
		if(n!=ncases-1){
			printf("\n");
		}

		free(arr2);
		free(v);
	}


	return 0;
}