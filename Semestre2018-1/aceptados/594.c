#include <stdio.h>

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int num;
	unsigned int a,b,c,d,aux1,aux2,aux3,aux4,newnum;
	a=255;
	b=65280;
	c=16711680;
	d=4278190080;

	while(scanf("%d",&num)==1){
		aux1=a&num;
		aux2=b&num;
		aux3=c&num;
		aux4=d&num;

		aux1=aux1<<24;
		aux2=aux2<<8;
		aux3=aux3>>8;
		aux4=aux4>>24;

		newnum = 0;
		newnum=newnum|aux1;
		newnum=newnum|aux2;
		newnum=newnum|aux3;
		newnum=newnum|aux4;

		printf("%d converts to %d\n",num,newnum);
	}

	return 0;
}