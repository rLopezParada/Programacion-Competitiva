#include <stdio.h>
#include <string.h>

int main(){
	int n,i,j,indice,count;
	scanf("%d",&n);
	getchar();

	char string[n][76];

	char batch[76];

	for(i=0;i<n;i++){
		scanf("%[^\n]",batch);
		getchar();
		sscanf(batch,"%s",string[i]);
	}

	
	for(i=0;i<n;i++){
		indice=i;
		for(j=i+1;j<n;j++){
			if(strcmp(string[indice],string[j])>0){
				indice=j;
			}
		}

		if(indice!=j){
			strcpy(batch,string[i]);
			strcpy(string[i],string[indice]);
			strcpy(string[indice],batch);
		}
	}
	
	

	char countries[n][76];
	strcpy(countries[0],string[0]);
	count=1;
	for(i=1;i<n;i++){
		if(strcmp(string[i-1],string[i])){
			strcpy(countries[count],string[i]);
			count++;
		}
	}

	int score[count];


	for(i=0;i<count;i++){
		score[i]=0;
	}

	score[0]++;
	j=0;
	for(i=1;i<n;i++){
		

		if(strcmp(string[i-1],string[i])){
			j++;
		}
		score[j]++;
	}

	for(i=0;i<count;i++){
		printf("%s %d\n",countries[i],score[i]);
	}


	return 0;
}