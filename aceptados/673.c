#include <stdio.h>

void leer(char* in){
	int i;
	for(i=0;;i++){
		in[i]=getchar();
		if(in[i]=='\n' || in[i]==-1){
			in[i]=0;
			return;
		}
	}
}

void removeChar(char* in,int index){
	int l=0;	
	while(in[l]!=0){
		l++;
	}
	while(index<l){
		in[index]=in[index+1];
		index++;
	}
	return;
}

void cleanup(char* in){
	int i;
	int l=0;
	while(in[l]!=0){
		l++;
	}
	for(i=0;i<l;i++){
		if(in[i]==32){
			removeChar(in,i);
			i--;
			l--;
		}
	}
	return;
}

int check(char* in){
	int i;
	if(in[0]==0 || in[0]=='\n' || in[0]==32){
		return 1;
	}
	for(i=0;in[i+1]!=0;i++){
		if((in[i]=='(' && in[i+1]==')') || (in[i]=='[' && in[i+1]==']')){
			removeChar(in,i);
			removeChar(in,i);
			i=-1;
		}
	}
	if(in[0]==0){
		return 1;
	}
	return 0;
}

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int n;
	scanf("%d",&n);
	getchar();
	char input[129];
	char* in = input;

	int i;
	for(i=0;i<n;i++){
		leer(in);
		cleanup(in);
		if(check(in)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}

	return 0;
}