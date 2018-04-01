#include <stdio.h>

int cycleLenght(int a, int b){
	int count,aux,cycleLenght;

	if(a>b){
		aux=a;
		a=b;
		b=aux;
	}
	cycleLenght=1;
	for(a;a<=b;a++){
		count=1;
		for(aux=a;aux>1;){
			if(aux%2==0){
				aux=aux/2;
			}
			else{
				aux=aux*3+1;
			}
			count++;
		}
		if(count>cycleLenght){
			cycleLenght=count;
		}
	}

	return cycleLenght;
}


int main(){
	int a[10000];
	int b[10000];
	int i=0;

	while(scanf("%d %d",&a[i],&b[i])==2){
		i++;
	}
	int j;
	for(j=0;j<i;j++){
		printf("%d %d %d\n",a[j],b[j],cycleLenght(a[j],b[j]));
	}
	return 0;
}