#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char* str;
	int uns;
}string;

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/

	int ncases,n,i,j,k,length,cant;
	int* uns;
	string* list;
	string aux;
	scanf("%d",&ncases);

	for(n=0;n<ncases;n++){
		scanf("%d %d",&length,&cant);
		getchar();

		list=(string*)malloc(cant*sizeof(string));
		for(i=0;i<cant;i++){
			list[i].uns=0;
			list[i].str=(char*)malloc((length+1)*sizeof(char));
			scanf("%s",list[i].str);
			for(j=0;j<length-1;j++){
				for(k=j+1;k<length;k++){
					if(list[i].str[j]>list[i].str[k]){
						list[i].uns++;
					}
				}
			}
		}
		do{
			k=0;
			for(i=1;i<cant;i++){
				if(list[i].uns<list[i-1].uns){
					aux=list[i];
					list[i]=list[i-1];
					list[i-1]=aux;
					k=1;
				}
			}
		}while(k);

		if(n!=0){
			printf("\n");
		}
		for(i=0;i<cant;i++){
			printf("%s\n",list[i].str);
		}
		free(list);
	}

	return 0;
}