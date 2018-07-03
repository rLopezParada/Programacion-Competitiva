#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int maxVal;
	int forward;
	char visitado;
}vertice;

vertice* vertices;
int nvertices;
int cola[50000];
int nCola;

void dfs(int index){
	int thisVertice=index;
	int aux;
	cola[0]=index;
	nCola=1;
	for(;;){
		aux=vertices[thisVertice].forward;
		if(vertices[aux].maxVal>0){
			//vertices[thisVertice].maxVal=vertices[aux].maxVal+1;
			nCola--;
			for(nCola;nCola>-1;nCola--){
				vertices[cola[nCola]].maxVal=vertices[aux].maxVal+1;
				aux=thisVertice;
			}
			return;
		}
		if(vertices[thisVertice].visitado==1){
			//printf("verticeCritico=%d ",thisVertice+1);
			int cycleLength,verticeCritico;
			verticeCritico=thisVertice;
			//searching cycle length	
			for(cycleLength=1;;cycleLength++){
				thisVertice=vertices[thisVertice].forward;
				if(thisVertice==verticeCritico){
					//printf("cycleLength=%d\n",cycleLength);
					break;
				}
			}
			//maxVal=cycleLength
			for(;;){
				vertices[thisVertice].maxVal=cycleLength;
				thisVertice=vertices[thisVertice].forward;
				if(thisVertice==verticeCritico){
					break;
				}
			}
			break;
		}
		vertices[thisVertice].visitado=1;
		thisVertice=aux;
		cola[nCola]=thisVertice;
		nCola++;
	}
	
	return;
}

int search(){
	int i,j,index;
	for(i=0;i<nvertices;i++){
		vertices[i].maxVal=0;
	}
	for(i=0;i<nvertices;i++){
		for(j=0;j<nvertices;j++){
			vertices[j].visitado=0;
		}
		if(vertices[i].maxVal==0){
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
	freopen("input.txt", "r", stdin);
	/*freopen("output.txt", "w", stdout);*/
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