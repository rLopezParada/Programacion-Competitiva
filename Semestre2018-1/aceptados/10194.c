#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[31];
	int points,
		games,
		wins,
		loses,
		ties,
		goalDifference,
		goalsScored,
		goalsAgainst;
} team;

int cmp(const void *a, const void *b){
	int r = (*(team*)b).points-(*(team*)a).points;
	if(r==0){
		r = (*(team*)b).wins-(*(team*)a).wins;
	}
	if(r==0){
		r = (*(team*)b).goalDifference-(*(team*)a).goalDifference;
	}
	if(r==0){
		r = (*(team*)b).goalsScored-(*(team*)a).goalsScored;
	}
	if(r==0){
		r = (*(team*)a).games-(*(team*)b).games;
	}
	if(r==0){
		char str1[31], str2[32];
		int l1,l2;
		strcpy(str1,(*(team*)a).name);
		strcpy(str2,(*(team*)b).name);
		l1=strlen(str1);
		l2=strlen(str2);
		for(r=0;r<l1;r++){
			if(str1[r]>64 && str1[r]<91)str1[r]+=32;
		}
		for(r=0;r<l2;r++){
			if(str2[r]>64 && str2[r]<91)str2[r]+=32;
		}
		r = strcmp(str1,str2);
	}
	return r;
}

int main(){	
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	
	int n,ncases,t,i,j,g,p1,p2,l1,l2,l3;

	scanf("%d",&ncases);
	getchar();

	char tournamentName[101],input[66],str[31];
	char* ptr;

	team* teams;
	team* team1;
	team* team2;

	for(n=0;n<ncases;n++){
		scanf("%[^\n]",tournamentName);
		getchar();

		scanf("%d",&t);
		getchar();

		teams=(team*)malloc(t*sizeof(team));
		for(i=0;i<t;i++){
			scanf("%[^\n]",teams[i].name);
			getchar();

			teams[i].points=0;
			teams[i].games=0;
			teams[i].wins=0;
			teams[i].loses=0;
			teams[i].ties=0;
			teams[i].goalDifference=0;
			teams[i].goalsScored=0;
			teams[i].goalsAgainst=0;
		}

		scanf("%d",&g);
		getchar();

		for(i=0;i<g;i++){
			scanf("%[^\n]",input);
			getchar();
			ptr=strchr(input,'#');
			l1=ptr-input;
			ptr=strchr(input,'@');
			l2=ptr-input;
			ptr=strrchr(input,'#');
			l3=ptr-input;
			ptr=input+l1+1;
			sscanf(ptr,"%d",&p1);
			ptr=input+l2+1;
			sscanf(ptr,"%d",&p2);


			strncpy(str,input,l1);
			str[l1]=0;

			for(j=0;j<t;j++){
				if(strcmp(str,teams[j].name)==0){
					team1=&teams[j];
					break;
				}
			}

			strcpy(str,input+l3+1);
			for(j=0;j<t;j++){
				if(strcmp(str,teams[j].name)==0){
					team2=&teams[j];
					break;
				}
			}

			(*team1).games++;
			(*team2).games++;
			(*team1).goalsScored+=p1;
			(*team2).goalsScored+=p2;
			(*team1).goalsAgainst+=p2;
			(*team2).goalsAgainst+=p1;
			if(p1>p2){
				(*team1).wins++;
				(*team1).points+=3;
				(*team2).loses++;
			}
			else if(p1<p2){
				(*team1).loses++;
				(*team2).wins++;
				(*team2).points+=3;
			}
			else if(p1==p2){
				(*team1).points++;
				(*team1).ties++;
				(*team2).points++;
				(*team2).ties++;
			}
		}
		for(i=0;i<t;i++){
			teams[i].goalDifference=teams[i].goalsScored-teams[i].goalsAgainst;
		}
		qsort(teams,t,sizeof(team),cmp);
		
		printf("%s\n",tournamentName);
		for(i=0;i<t;i++){
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
				i+1,
				teams[i].name,
				teams[i].points,
				teams[i].games,
				teams[i].wins,
				teams[i].ties,
				teams[i].loses,
				teams[i].goalDifference,
				teams[i].goalsScored,
				teams[i].goalsAgainst);
		}
		free(teams);
		if(n!=ncases-1){
			printf("\n");
		}
	}

	return 0;

}