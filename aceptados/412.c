#include <stdio.h>
#include <math.h>

int coprimes(int a, int b){
	int r;

	if(a<b){
		r=a;
		a=b;
		b=r;
	}

	while(b!=0){
		r=a%b;
		a=b;
		b=r;
	}

	if(a==1){
		return 1;
	}
	return 0;
}

int main(){
	int npa[10000];		
	int aoa[10000][50];	
	int aux[2450];
	int ncases=0;
	int i,j,k,pos,num,npairs;

	while(1){
		scanf("%d",&npa[ncases]);
		if(npa[ncases]==0)break;
		for(i=0;i<npa[ncases];i++){
			scanf("%d",&aoa[ncases][i]);
		}
		ncases++;
	}

	for(i=0;i<ncases;i++){
		pos=0;
		for(j=0;j<npa[i]-1;j++){
			for(k=j+1;k<npa[i];k++,pos+=2){
				aux[pos]=aoa[i][j];
				aux[pos+1]=aoa[i][k];
			}
		}

		num=0;
		npairs=(npa[i]*npa[i]-npa[i])>>1;
		
		for(j=0;j<npairs;j++){
			if(coprimes(aux[2*j],aux[2*j+1])){
				num++;
			}
		}
		if(num==0){
			printf("No estimate for this data set.\n");
		}
		else{
			printf("%.6lf\n",sqrt(6*(double)npairs/num));
		}
	}

	return 0;
}