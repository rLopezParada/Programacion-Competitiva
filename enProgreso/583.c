#include <stdio.h>
#include <math.h>

int main(){
	int nums[10000];
	int primes[33];
	int n=0;
	do{
		scanf("%d",&nums[n]);
		n++;
	}while(nums[n-1]!=0);
	n--;
	int i,j,k,pos,num;

	for(i=0;i<n;i++){
		num=nums[i];
		pos=0;
		if(num<0){
			num=num*-1;
			primes[pos]=-1;
			pos++;
		}
		j=2;
		while(j<=sqrt(num)){
			if(num%j==0){
				num=num/j;
				primes[pos]=j;
				pos++;
			}
			else{
				j++;
			}
		}
		primes[pos]=num;

		switch(nums[i]){
			case 1:
				printf("1 = \n");
				break;

			case -1:
				printf("-1 = -1 x \n");
				break;

			default:
				printf("%d = %d",nums[i],primes[0]);
				for(k=1;k<=pos;k++){
					printf(" x %d",primes[k]);
				}
				printf("\n");
		}
	}
	return 0;
}