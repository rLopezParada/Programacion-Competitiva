#include <stdio.h>

int wins(char matrix[3][3]){
	int i,j,x,o;
	x=o=0;
	for(i=0;i<3;i++){
		if(matrix[i][0]=='X' && matrix[i][1]=='X' && matrix[i][2]=='X'){
			x=1;
			break;
		}
		if(matrix[0][i]=='X' && matrix[1][i]=='X' && matrix[2][i]=='X'){
			x=1;
			break;
		}
	}
	if(x==0 && matrix[0][0]=='X' && matrix[1][1]=='X' && matrix[2][2]=='X'){
		x=1;
	}
	else if(matrix[0][2]=='X' && matrix[1][1]=='X' && matrix[2][0]=='X'){
		x=1;
	}

	
	
	for(i=0;i<3;i++){
		if(matrix[i][0]=='O' && matrix[i][1]=='O' && matrix[i][2]=='O'){
			o=1;
			break;
		}
		if(matrix[0][i]=='O' && matrix[1][i]=='O' && matrix[2][i]=='O'){
			o=1;
			break;
		}
	}
	if(o==0 && matrix[0][0]=='O' && matrix[1][1]=='O' && matrix[2][2]=='O'){
		o=1;
	}
	else if(matrix[0][2]=='O' && matrix[1][1]=='O' && matrix[2][0]=='O'){
		o=1;
	}

	if(x==1 && o==0){
		return 2;
	}
	if(x==0 && o==1){
		return 1;
	}
	if(x==0 && o==0){
		return 0;
	}
	return -1;
}

int main(){
	int cases,n,i,j,k,l;
	int nX;
	int nO;
	int r,w;
	char matrix[3][3];
	scanf("%d",&n);
	for( cases=0 ; cases<n ; cases++ ){
		nX=nO=0;
		getchar();
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				scanf("%c",&matrix[i][j]);
			}
			if(cases!=n-1 || i!=2){
				getchar();
			}
		}

		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(matrix[i][j]=='X'){
					nX++;
				}
				else if(matrix[i][j]=='O'){
					nO++;
				}
			}
		}

		r=1;

		if(nX!=nO+1 && nX!=nO){
			r=0;
		}
		else{
			w=wins(matrix);
			if(w==-1){
				r=0;
			}
			else if(nX==nO+1 && w==1){
				r=0;
			}
			else if(nX==nO && w==2){
				r=0;
			}
		}
		
		if(r){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}

	}
	return 0;
}