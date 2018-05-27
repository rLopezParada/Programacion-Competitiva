#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*typedef struct {
	char name[31];
	int rank,
		points,
		games,
		wins,
		loses,
		goalDifference,
		goalsScored,
		goalsAgainst;
} team;*/

struct equipo{
	char name[31];
	int rank,
		points,
		games,
		wins,
		loses,
		goalDifference,
		goalsScored,
		goalsAgainst;
};

typedef struct equipo team;

int main(){
	int n,t,i,g;

	scanf("%d",&n);
	getchar();
	printf("n=%d\n",n);

	char tournamentName[101];

	team* teams;

	scanf("%[^\n]",tournamentName);
	getchar();
	printf("tournamentName=%s\n",tournamentName);

	scanf("%d",&t);
	getchar();
	printf("t=%d\n",t);

	teams=(team*)malloc(t*sizeof(team));
	for(i=0;i<t;i++){
		scanf("%[^\n]",teams[i].name);
		getchar();
		printf("team%d=%s\n",i,teams[i].name);

		teams[i].rank=0;
		teams[i].points=0;
		teams[i].games=0;
		teams[i].wins=0;
		teams[i].loses=0;
		teams[i].goalDifference=0;
		teams[i].goalsScored=0;
		teams[i].goalsAgainst=0;
	}

	scanf("%d",&g);
	getchar();
	printf("g=%d\n",g);


	char input[66];
	team* team1,team2;
	int p1,p2;
	char* ptr;
	int l1,l2,l3;
	int j;
	char str[31];
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

		printf("%d-%d\n",p1,p2);

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
		printf("team1=%s team2=%s\n",(*team1).name,(*team2).name);
	}

	free(teams);

	return 0;

}