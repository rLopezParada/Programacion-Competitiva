#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int vs[100];
	int gs;
	char visitado;
}vertex;

vertex* vertices;
int nvertices;
int verC[100];
int aCheckear;
int inac[100];
int ninac;

void dfs(int index){
	int i,num;
	for(i=0;i<vertices[index].gs;i++){
		num=vertices[index].vs[i];
		if(vertices[num].visitado==0){
			vertices[num].visitado=1;
			dfs(num);
		}
	}
	return;
}

void answer(){
	int i,j,k;
	for(i=0;i<aCheckear;i++){
		ninac=0;
		for(j=0;j<nvertices;j++){
			vertices[j].visitado=0;
		}

		dfs(verC[i]);

		for(j=0,k=0;j<nvertices;j++){
			if(vertices[j].visitado==0){
				inac[k]=j;
				k++;
				ninac++;
			}
		}
		printf("%d",ninac);
		for(j=0;j<ninac;j++){
			printf(" %d",inac[j]+1);
		}
		printf("\n");
	}
	return;
}

void getLine(char* in){
	int i=0;
	in[0]=getchar();
	while(in[i]!='\n' && in[i]!=EOF){
		in[++i]=getchar();
	}
	in[i]=0;
	return;
}

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	vertices = (vertex*)malloc(100*sizeof(vertex));
	char input[1000];
	char* in=input;
	char* ptr;
	int i,dir,index;
	for(;;){
		getLine(in);
		if(in[0]=='0'){break;}
		sscanf(in,"%d",&nvertices);
		for(i=0;i<nvertices;i++){
			vertices[i].gs=0;
		}
		for(i=0;;i++){	/*armando lista de adyacencias*/
			getLine(in);
			if(in[0]=='0'){break;}
			sscanf(in,"%d",&index);
			index--;
			ptr=in+1;
			for(;;){
				while(*ptr!=32){
					ptr++;
				}
				ptr++;
				sscanf(ptr,"%d",&dir);
				if(dir==0){
					break;
				}
				dir--;
				vertices[index].vs[vertices[index].gs]=dir;
				vertices[index].gs++;
			}
		}
		getLine(in);
		sscanf(in,"%d",&aCheckear);
		ptr=in+1;
		for(i=0;i<aCheckear;i++){
			while(*ptr!=32){
				ptr++;
			}
			ptr++;
			sscanf(ptr,"%d",&dir);
			verC[i]=--dir;
		}
		/*lista terminada*/
		answer();/*calculando*/
	}

	free(vertices);

	return 0;
}