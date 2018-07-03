#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int maxVal;
	int forward;
	char ready;
}vertice;

vertice* vertices;
int nvertices;

void dfs(int index){
	int thisVertice=index;
	int aux;
	int val=1;
	for(;;){
		vertices[thisVertice].maxVal=val;
		aux=vertices[thisVertice].forward;
		if(vertices[aux].ready){
			/*vertice aux ya tenia valor*/
			val+=vertices[aux].maxVal;
			vertices[index].maxVal=val;
			vertices[index].ready=1;
			thisVertice=vertices[index].forward;
			for(;;){
				/*backtrack con val*/
				if(vertices[thisVertice].ready){
					return;
				}
				vertices[thisVertice].maxVal=--val;
				vertices[thisVertice].ready=1;
				thisVertice=vertices[thisVertice].forward;
			}
		}
		else if(vertices[aux].maxVal>0){
			/*vertice aux es inicio y final de un ciclo*/
			int finalVal=val;
			val=val-vertices[aux].maxVal+1;
			thisVertice=aux;
			for(;;){
				if(vertices[thisVertice].ready){
					/*backtrack con finalVal*/
					thisVertice=index;
					for(;;){
						if(vertices[thisVertice].ready){
							return;
						}
						vertices[thisVertice].maxVal=finalVal--;
						vertices[thisVertice].ready=1;
						thisVertice=vertices[thisVertice].forward;
					}
				}
				vertices[thisVertice].maxVal=val;
				vertices[thisVertice].ready=1;
				thisVertice=vertices[thisVertice].forward;
			}
		}
		thisVertice=aux;
		val++;
	}
}

int search(){
	int i,index;
	for(i=0;i<nvertices;i++){
		vertices[i].maxVal=0;
		vertices[i].ready=0;
	}
	for(i=0;i<nvertices;i++){
		if(vertices[i].ready==0){
			dfs(i);
		}
	}
	index=0;
	for(i=1;i<nvertices;i++){
		if(vertices[index].maxVal<vertices[i].maxVal){
			index=i;
		}
	}
	return index;
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
	char input[1000];
	char* in=input;
	int ncases,n,i,index,dir,r;
	getLine(in);
	sscanf(in,"%d",&ncases);

	for(n=0;n<ncases;n++){
		getLine(in);
		sscanf(in,"%d",&nvertices);

		vertices = (vertice*)malloc(nvertices*sizeof(vertice));

		for(i=0;i<nvertices;i++){
			getLine(in);
			sscanf(in,"%d %d",&index,&dir);
			index--;
			dir--;
			vertices[index].forward=dir;
		}

		r=search();

		free(vertices);

		printf("Case %d: %d\n",n+1,r+1);
	}

	return 0;
}