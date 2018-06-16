#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[100];
	int nstudents;
	char** student;
}project;

typedef struct{
	int nstudents;
	char** student;
}listaNegra;

int cmp(const void *a, const void *b){
	int r=((project*)b)->nstudents-((project*)a)->nstudents;
	if(r==0){
		r=strcmp(((project*)a)->name,((project*)b)->name);
	}
	return r;
}

void getlinea(char* in){
	int i;
	for(i=0;;i++){
		in[i]=getchar();
		if(in[i]=='\n' || in[i]==-1){
			in[i]=0;
			return;
		}
	}
}

void removeStudent(project* pro, int index){
	int n = --(*pro).nstudents;
	while(index<n){
		strcpy((*pro).student[index],(*pro).student[index+1]);
		index++;
	}
	return;
}

/*void pushBlackList(listaNegra* blackList,char* str){
	int i;
	int n = (*blackList).nstudents;
	for(i=0;i<n;i++){
		if(strcmp((*blackList).student[i],str)==0){
			return;
		}
	}
	(*blackList).nstudents++;
	strcpy((*blackList).student[n],str);
	return;
}*/

int pushBlackList(listaNegra* blackList,char* str){
	int i;
	int n = (*blackList).nstudents;
	for(i=0;i<n;i++){
		if(strcmp((*blackList).student[i],str)==0){
			return 0;
		}
	}
	strcpy((*blackList).student[n],str);
	return 1;
}

int main(){
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	int i,j,k,l,nprojects;
	char* in=(char*)malloc(100*sizeof(char));
	project* projects = (project*)malloc(100*sizeof(project));
	listaNegra blackList;
	blackList.student = (char**)malloc(10000*sizeof(char*));
	for(i=0;i<100;i++){
		blackList.student[i] = (char*)malloc(100*sizeof(char));
		projects[i].student = (char**)malloc(10000*sizeof(char*));
		for(j=0;j<10000;j++){
			projects[i].student[j]=(char*)malloc(100*sizeof(char));
		}
	}
	char go;
	char end=1;
	while(end){
		nprojects=0;
		for(;;){
			getlinea(in);
			if(in[0]>64 && in[0]<91){
				projects[nprojects].nstudents=0;
				strcpy(projects[nprojects++].name,in);
			}
			else if(in[0]>96 && in[0]<123){
				go=1;
				for(i=0;i<projects[nprojects-1].nstudents;i++){
					if(strcmp(projects[nprojects-1].student[i],in)==0){
						go=0;
					}
				}
				if(go){
					strcpy(projects[nprojects-1].student[projects[nprojects-1].nstudents++],in);
				}
			}
			else if(in[0]=='1'){
				blackList.nstudents=0;
				for(i=0;i<nprojects-1;i++){
					for(j=i+1;j<nprojects;j++){
						for(k=0;k<projects[i].nstudents;k++){
							for(l=0;l<projects[j].nstudents;l++){
								if(strcmp(projects[i].student[k],projects[j].student[l])==0){
									if(pushBlackList(&blackList,projects[i].student[k])){
										blackList.nstudents++;
									}
								}
							}
						}
					}
				}
				for(i=0;i<blackList.nstudents;i++){
					for(j=0;j<nprojects;j++){
						for(k=0;k<projects[j].nstudents;k++){
							if(strcmp(blackList.student[i],projects[j].student[k])==0){
								removeStudent(&projects[j],k);
								k--;
							}
						}
					}
				}
				for(i=0;i<nprojects;i++){
					qsort(projects,nprojects,sizeof(project),cmp);
				}
				for(i=0;i<nprojects;i++){
					printf("%s %d\n",projects[i].name,projects[i].nstudents);
				}
				break;
			}
			else{
				end=0;
				break;
			}
		}
	}
	free(in);
	for(i=0;i<100;i++){
		for(j=0;j<10000;j++){
			free(projects[i].student[j]);
		}
		free(blackList.student[i]);
		free(projects[i].student);
	}
	free(blackList.student);
	free(projects);

	return 0;
}