#include <stdio.h>

typedef struct{
	int 	x,
			y;
	char	orientation,
			alive; /*0=lost, 1=alive*/
}Robot;

typedef struct{
	int x,
		y;
	char orientation;
}Scent;

int maxX,maxY;
int nlost;
char cont;
char end;

void pushScent(int x,int y,char orientation,Scent* scent){
	scent[nlost].x=x;
	scent[nlost].y=y;
	scent[nlost].orientation=orientation;
	nlost++;
	return;
}

int read(int* x,int* y,char* orientation,char ins[100]){
	int i;
	signed char in[200];
	char c = getchar();
	if(c==-1){
		return 0;
	}
	in[0]=c;
	for(i=1;;i++){
		in[i]=getchar();
		if(in[i]=='\n'){
			in[i]=32;
			break;
		}
	}
	i++;
	for(;;i++){
		in[i]=getchar();
		if(in[i]=='\n'){
			in[i]=0;
			break;
		}
		else if(in[i]==-1){
			end=1;
			in[i]=0;
			break;
		}
	}
	sscanf(in,"%d %d %c %s",x,y,orientation,ins);
	return 1;
}

void turn(Robot* robots,int index,char ins){
	if(ins=='L'){
		switch(robots[index].orientation){
			case 'N':
				robots[index].orientation='W';
				return;
			case 'E':
				robots[index].orientation='N';
				return;
			case 'W':
				robots[index].orientation='S';
				return;
			default:
				robots[index].orientation='E';
				return;
		}
	}
	switch(robots[index].orientation){
		case 'N':
			robots[index].orientation='E';
			return;
		case 'E':
			robots[index].orientation='S';
			return;
		case 'W':
			robots[index].orientation='N';
			return;
		default:
			robots[index].orientation='W';
			return;
	}
}

int forward(Robot* robots,int index,char ins,Scent* scent){
	int i;
	int xi,yi,xf,yf;
	xi=robots[index].x;
	yi=robots[index].y;
	switch(robots[index].orientation){
		case 'N':
			xf=xi;
			yf=yi+1;
			break;
		case 'E':
			xf=xi+1;
			yf=yi;
			break;
		case 'W':
			xf=xi-1;
			yf=yi;
			break;
		default:
			xf=xi;
			yf=yi-1;
	}
	if(xf>maxX || xf<0 || yf>maxY || yf<0){
		for(i=0;i<nlost;i++){
			if(robots[index].orientation==scent[i].orientation && xi==scent[i].x && xi==scent[i].y){
				return 1;
			}
		}
		pushScent(xi,yi,robots[index].orientation,scent);
		robots[index].alive=0;
		return 0;
	}
	robots[index].x=xf;
	robots[index].y=yf;
	return 1;
}

int move(Robot* robots,int index,char ins,Scent* scent){
	if(ins=='L' || ins=='R'){
		turn(robots,index,ins);
		return 1;
	}
	return forward(robots,index,ins,scent);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i;
	int nrobots=0;
	int lenght;
	char ins[100];
	cont=1;
	end=0;
	nlost=0;
	Robot robots[10000];
	Scent scent[10000];
	if(scanf("%d %d",&maxX,&maxY)==EOF){
		cont=0;
	}
	if(cont){
		getchar();
	}
	while(cont && read(&robots[nrobots].x,&robots[nrobots].y,&robots[nrobots].orientation,ins)){
		//printf("%d %d %c %s\n",robots[nrobots].x,robots[nrobots].y,robots[nrobots].orientation,ins);
		robots[nrobots].alive=1;
		lenght=0;
		while(ins[lenght]){
			lenght++;
		}
		//printf("moving\n");
		for(i=0;i<lenght;i++){
			
			if(move(robots,nrobots,ins[i],scent)==0){
				break;
			}
			//printf("%d %d %c\n",robots[nrobots].x,robots[nrobots].y,robots[nrobots].orientation);
		}
		//printf("end\n");

		nrobots++;
		if(end){
			break;
		}
	}
	if(cont){
		for(i=0;i<nrobots;i++){
			printf("%d %d %c",robots[i].x,robots[i].y,robots[i].orientation);
			if(robots[i].alive==0){
				printf(" LOST");
			}
			printf("\n");
		}
	}

	return 0;
}