#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int n,
		time,
		score,
		problemPenalties[9];
	char problems[9];
} team;

int cmp(const void* a, const void* b){
	int r = (*(team*)b).score-(*(team*)a).score;
	if(r==0){
		r = (*(team*)a).time-(*(team*)b).time;
	}
	if(r==0){
		r = (*(team*)a).n-(*(team*)b).n;
	}
	return r;
}

int main(){

	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/

	int aux,nteams,i,c,p,t,index;
	char l,create,input[14];
	team* teams;
	nteams=0;
	scanf("%*d");
	getchar();

	aux=getchar();
	do{
		input[0]=aux;
		scanf("%[^\n]",input+1);
		sscanf(input,"%d %d %d %c",&c,&p,&t,&l);
		p--;
		create=1;
		for(i=0;i<nteams;i++){
			if(teams[i].n==c){
				create=0;
				index=i;
				break;
			}
		}
		if(create){
			index=nteams;
			nteams++;
			if(nteams==1){
				teams=(team*)malloc(sizeof(team));
			}
			else{
				teams=(team*)realloc(teams,nteams*sizeof(team));
			}
			teams[index].n=c;
			teams[index].time=0;
			teams[index].score=0;
			for(i=0;i<9;i++){
				teams[index].problems[i]=0;
				teams[index].problemPenalties[i]=0;
			}
		}
		if(l=='C' && teams[index].problems[p]==0){
			teams[index].problems[p]=1;
			teams[index].score++;
			teams[index].time+=teams[index].problemPenalties[p]+t;
		}
		else if(l=='I' && teams[index].problems[p]==0){
			teams[index].problemPenalties[p]+=20;
		}
		getchar();
		aux=getchar();
		if(aux=='\n' || aux==EOF){
			qsort(teams,nteams,sizeof(team),cmp);
			for(i=0;i<nteams;i++){
				printf("%d %d %d\n",teams[i].n,teams[i].score,teams[i].time);
			}
			free(teams);
			if(aux=='\n'){
				printf("\n");
				nteams=0;
				aux=getchar();
			}
		}
	}while(aux!=EOF);

	return 0;
}