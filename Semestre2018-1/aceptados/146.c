#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){
	int r = (int)(*(char*)a-*(char*)b);
	return r;
}

int main(){
	char input[51],aux;
	int i,j,l,l2,found;
	char* ptr;

	while(1){
		scanf("%s",input);
		if(input[0]=='#'){
			break;
		}

		l=strlen(input);

		found=0;
		for(i=l-2;i>-1;i--){
			for(j=l-1;j>i;j--){
				if(input[j]>input[i]){
					aux=input[i];
					input[i]=input[j];
					input[j]=aux;
					found=1;
					break;
				}
			}
			if(found){
				break;
			}
		}

		if(i==-1){
			printf("No Successor\n");
		}
		else{
			i++;
			l2=l-i;
			ptr=input+i;

			qsort(ptr,l2,sizeof(char),cmp);

			printf("%s\n",input);
		}

	}

	return 0;
}