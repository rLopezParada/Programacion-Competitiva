#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int n,
		time,
		playing,
		score,
		problem[9],
		problemPenalties[9];
} team;

int cmp(const void *a, const void *b){
	int r = (*(team*)b).score-(*(team*)a).score;
	if(r==0){
		r = (*(team*)a).time-(*(team*)b).time;
	}
	if(r==0){
		r = (*(team*)a).n-(*(team*)b).n;
	}
	return r;
}

void swap(team* team1,team* team2){
	int aux;
	aux=(*team2).n;
	(*team2).n=(*team1).n;
	(*team1).n=aux;

	aux=(*team2).time;
	(*team2).time=(*team1).time;
	(*team1).time=aux;

	aux=(*team2).playing;
	(*team2).playing=(*team1).playing;
	(*team1).playing=aux;

	aux=(*team2).score;
	(*team2).score=(*team1).score;
	(*team1).score=aux;

	int i;
	for(i=0;i<9;i++){
		aux=(*team2).problem[i];
		(*team2).problem[i]=(*team1).problem[i];
		(*team1).problem[i]=aux;

		aux=(*team2).problemPenalties[i];
		(*team2).problemPenalties[i]=(*team1).problemPenalties[i];
		(*team1).problemPenalties[i]=aux;
	}
	return;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int ncases,n,i,j,contestant,problem,time,ch,size,last;
	team aux;
	char input[14];
	team* teams;
	scanf("%d",&ncases);
	getchar();

	for(n=0;n<ncases;n++){
		teams=(team*)malloc(100*sizeof(team));	/*new objects*/
		for(i=0;i<100;i++){	/*constructor*/
			teams[i].n=i+1;
			teams[i].time=teams[i].playing=teams[i].score=0;
			for(j=0;j<9;j++){
				teams[i].problem[j]=teams[i].problemPenalties[j]=0;
			}
		}
		getchar();
		while(1){
			ch=getchar();
			if(ch==EOF || ch=='\n') break;
			input[0]=ch;
			scanf("%[^\n]",input+1);
			getchar();

			sscanf(input,"%d %d %d %c",&contestant,&problem,&time,&ch);
			contestant--;
			problem--;
			teams[contestant].playing=1;
			if((ch=='I' || ch=='C') && teams[contestant].problem[problem]!=1 ){
				if(ch=='C'){
					teams[contestant].score++;
					teams[contestant].problem[problem]=1;
					teams[contestant].time+=time+teams[contestant].problemPenalties[problem];
				}else{
					teams[contestant].problemPenalties[problem]+=20;
				}
			}
		}
		size=last=0;
		for(i=0;i<100;i++){
			if(teams[i].playing==1){
				size++;
			}
		}
		while(last<100){
			for(i=last;i<100;i++){
				if(teams[i].playing==0){
					last=i;
					break;
				}
			}
			for(i=last;i<100;i++){
				if(teams[i].playing==1){
					swap(&teams[i],&teams[last]);
					/*aux.n=aux.time=aux.playing=aux.score=0;
					aux=teams[last];
					teams[last]=teams[i];
					teams[i]=aux;*/
					break;
				}
			}
			last++;
		}
		qsort(teams,size,sizeof(team),cmp);
		for(i=0;i<size;i++){
			printf("%d %d %d\n",teams[i].n,teams[i].score,teams[i].time);
		}
		free(teams);
		if(n!=ncases-1){
			printf("\n");
		}
	}
	return 0;
}