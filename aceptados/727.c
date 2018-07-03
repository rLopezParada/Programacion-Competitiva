#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeS(char** in,int index){
	int l=0;
	int i;
	while(in[l][0]!=0){
		l++;
	}
	while(index<l){
		for(i=0;i<100;i++){
			in[index][i]=in[index+1][i];
		}
		index++;
	}
	return;
}

void solve(char** in){
	int i,j;
	char** ptr;
	for(i=0;in[i][0]!=0 && in[i][0]!=')';i++){
		if(in[i][0]=='('){
			ptr=in+i+1;
			solve(ptr);
			j=i+1;
			while(in[j][0]!=')'){
				j++;
			}
			removeS(in,j);
			removeS(in,i);
		}
	}
	
	for(i=0;in[i][0]!=0 && in[i][0]!=')';i++){
		if(in[i][0]=='*' || in[i][0]=='/'){
			strcat(in[i-1],in[i+1]);
			strcat(in[i-1],in[i]);
			removeS(in,i+1);
			removeS(in,i);
			i--;
		}
	}
	for(i=0;in[i][0]!=0 && in[i][0]!=')';i++){
		if(in[i][0]=='+' || in[i][0]=='-'){
			strcat(in[i-1],in[i+1]);
			strcat(in[i-1],in[i]);
			removeS(in,i+1);
			removeS(in,i);
			i--;
		}
	}
	return;
}

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int n,i,j,k,tam;
	char** in =(char**)malloc(51*sizeof(char*));
	for(i=0;i<51;i++){
		in[i]=(char*)malloc(100*sizeof(char));
	}
	scanf("%d",&n);
	getchar();
	getchar();
	for(i=0;i<n;i++){
		tam=0;
		for(j=0;;j++){
			in[j][0]=getchar();
			if(in[j][0]=='\n' || in[j][0]==EOF){
				in[j][0]=0;
				tam=j;
				break;
			}
			in[j][1]=getchar();
			if(in[j][1]==EOF){
				in[++j][0]=0;
				tam=j;
				break;
			}
		}
		for(j=0;j<tam;j++){
			in[j][1]=0;
		}
		if(i>0){
			printf("\n");
		}
		solve(in);
		j=0;
		while(in[j][0]!=0){
			j++;
		}
		for(j=0;in[j][0]!=0;j++){
			printf("%s",in[j]);
		}
		printf("\n");
	}

	return 0;
}