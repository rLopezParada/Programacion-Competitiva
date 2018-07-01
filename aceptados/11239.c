#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char name[100];
	int nstudents;
	char** students;
}project;

int nprojects;
project projects[100];

int cmp(const void *a, const void *b){
	project x,y;
	x=*(project*)a;
	y=*(project*)b;
	int r=y.nstudents-x.nstudents;
	if(r){
		return r;
	}

	return strcmp(x.name,y.name);
}

void removeStudent(int a, int b){
	int i;
	projects[a].nstudents--;
	for(i=b;i<projects[a].nstudents;i++){
		strcpy(projects[a].students[i],projects[a].students[i+1]);
	}
	return;
}

void purge(char* std){
	int i,j;
	for(i=0;i<nprojects;i++){
		for(j=0;j<projects[i].nstudents;j++){
			if(strcmp(std,projects[i].students[j])==0){
				removeStudent(i,j);
				j--;
			}
		}
	}
	return;
}

void push(char* in){
	int i;
	nprojects--;
	for(i=0;i<projects[nprojects].nstudents;i++){
		if(strcmp(in,projects[nprojects].students[i])==0){
			nprojects++;
			return;
		}
	}

	int nstudents = projects[nprojects].nstudents;
	strcpy(projects[nprojects].students[nstudents],in);
	projects[nprojects].nstudents++;
	nprojects++;
	return;
}

void getLine(char* in){
	int i=-1;
	do{
		i++;
		in[i]=getchar();
	}while(in[i]!='\n' && in[i]!=EOF);
	in[i]=0;

	return;
}

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int i,j,k,l;
	
	for(i=0;i<100;i++){
		projects[i].students = (char**)malloc(10000*sizeof(char*));
		for(j=0;j<10000;j++){
			projects[i].students[j] = (char*)malloc(100*sizeof(char));
		}
	}

	char input[10000];
	char student1[100];
	char student2[100];
	char* in=input;
	char* std1=student1;
	char* std2=student2;

	do{
		nprojects=0;
		do{
			getLine(in);
			if(in[0]!='1' && in[0]!='0'){
				if(64<in[0] && in[0]<91){	/*is project*/
					strcpy(projects[nprojects].name,in);
					projects[nprojects].nstudents=0;
					nprojects++;
				}
				else{						/*is student*/
					push(in);
				}
			}
		}while(in[0]!='1' && in[0]!='0');

		/*buscando students que esten en dos listas a la vez*/
		for(i=0;i<nprojects-1;i++){
			for(j=i+1;j<nprojects;j++){
				for(k=0;k<projects[i].nstudents;k++){
					for(l=0;l<projects[j].nstudents;l++){
						strcpy(std1,projects[i].students[k]);
						strcpy(std2,projects[j].students[l]);
						if(strcmp(std1,std2)==0){
							purge(std1);/*eliminar al student de todas las listas*/
							k=-1;
							break;
						}
					}
				}
			}
		}

		qsort(projects,nprojects,sizeof(project),cmp);

		for(i=0;i<nprojects;i++){
			printf("%s %d\n",projects[i].name,projects[i].nstudents);
		}

	}while(in[0]!='0');

	for(i=0;i<100;i++){
		for(j=0;j<10000;j++){
			free(projects[i].students[j]);
		}
		free(projects[i].students);
	}

	return 0;
}