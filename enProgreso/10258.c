#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int n,time,playing,score;
	int problem[9];
	int problemPenalties[9];
}team;

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

/*int cmp(const void *a, const void *b){
	int r = (int)(*(char*)a-*(char*)b);
	return r;
}*/

int main(){
	int ncases,n,i,j;
	int contestant, problem, time;
	int ch;
	int size;
	int last;
	team aux;
	char input[14];
	team* teams=(team*)malloc(100*sizeof(team));	//new objects
	for(i=0;i<20;i++){
		printf("%ld\n",&teams[i]);
	}
	scanf("%d",&ncases);
	getchar();

	for(n=0;n<ncases;n++){
		for(i=0;i<100;i++){	//constructor
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
			//printf("%d %d %d %c\n",contestant,problem,time,ch);
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
		size=0;
		last=0;
		for(i=0;i<100;i++){
			if(teams[i].playing==1){
				aux=teams[last];
				teams[last]=teams[i];
				teams[i]=aux;
				size++;
				last=i+1;
			}
		}
		qsort(teams,size,sizeof(team),cmp);
		for(i=0;i<size;i++){
			printf("%d %d %d\n",teams[i].n,teams[i].score,teams[i].time);
		}
	}
	free(teams);
	return 0;
}