#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
	char ori;
	char alive;
}robot;

int xMax;
int yMax;
robot* robots;
int nrobots=0;
int scentX[10000];
int scentY[10000];
int nscent=0;

int checkScent(){
	nrobots--;
	int i;
	for(i=0;i<nscent;i++){
		if(robots[nrobots].x==scentX[i] && robots[nrobots].y==scentY[i]){
			nrobots++;
			return 1;
		}
	}
	nrobots++;
	return 0;
}

void addScent(){
	nrobots--;
	int i;
	for(i=0;i<nscent;i++){
		if(robots[nrobots].x==scentX[i] && robots[nrobots].y==scentY[i]){
			nrobots++;
			return;
		}
	}
	scentX[nscent]=robots[nrobots].x;
	scentY[nscent]=robots[nrobots].y;
	nscent++;
	nrobots++;
	return;
}

void turn(char c){
	nrobots--;
	if(c=='R'){
		switch(robots[nrobots].ori){
			case 'N': robots[nrobots].ori='E'; break;
			case 'E': robots[nrobots].ori='S'; break;
			case 'S': robots[nrobots].ori='W'; break;
			default: robots[nrobots].ori='N';
		}
		nrobots++;
		return;
	}
	switch(robots[nrobots].ori){
		case 'N': robots[nrobots].ori='W'; break;
		case 'W': robots[nrobots].ori='S'; break;
		case 'S': robots[nrobots].ori='E'; break;
		default: robots[nrobots].ori='N';
	}
	nrobots++;
	return;
}

void move(char* in){
	int i;
	char alive=1;
	for(i=0;in[i]!=0 && alive;i++){
		if(in[i]!='F'){
			turn(in[i]);
		}
		else{
			switch(robots[nrobots-1].ori){
				case 'N':
					if(robots[nrobots-1].y+1>yMax){
						if(checkScent()){break;}
						robots[nrobots-1].alive=0;
						alive=0;
						addScent();
						break;
					}
					robots[nrobots-1].y++;
					break;
				case 'E':
					if(robots[nrobots-1].x+1>xMax){
						if(checkScent()){break;}
						robots[nrobots-1].alive=0;
						alive=0;
						addScent();
						break;
					}
					robots[nrobots-1].x++;
					break;
				case 'S':
					if(robots[nrobots-1].y-1<0){
						if(checkScent()){break;}
						robots[nrobots-1].alive=0;
						alive=0;
						addScent();
						break;
					}
					robots[nrobots-1].y--;
					break;
				default:
					if(robots[nrobots-1].x-1<0){
						if(checkScent()){break;}
						robots[nrobots-1].alive=0;
						alive=0;
						addScent();
						break;
					}
					robots[nrobots-1].x--;
			}
		}
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
	robots = (robot*)malloc(10000*sizeof(robot));
	int i;
	char input[101];
	char* in = input;
	getLine(in);
	sscanf(in,"%d %d",&xMax,&yMax);
	for(;;){
		getLine(in);
		if(in[0]==0){
			break;
		}
		sscanf(in,"%d %d %c",&robots[nrobots].x,&robots[nrobots].y,&robots[nrobots].ori);
		robots[nrobots].alive=1;
		nrobots++;
		getLine(in);
		move(in);
	}

	for(i=0;i<nrobots;i++){
		printf("%d %d %c",robots[i].x,robots[i].y,robots[i].ori);
		if(robots[i].alive==0){
			printf(" LOST");
		}
		printf("\n");
	}

	free(robots);
	return 0;
}