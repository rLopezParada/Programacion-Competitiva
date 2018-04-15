#include <stdio.h>
#include <string.h>

int toInt(char c){
	switch(c) {
		case'I':
			return 1;
		case'V':
			return 5;
		case'X':
			return 10;
		case'L':
			return 50;
		case'C':
			return 100;
		case'D':
			return 500;
		case'M':
			return 1000;
	}
	return 0;
}

void search(int *n,char *string){
	char c;
	if(*n>=1000){
		*n-=1000;
		strcat(string,"M");
	}
	else if(*n>=900){
		*n-=900;
		strcat(string,"CM");
	}
	else if(*n>=500){
		*n-=500;
		strcat(string,"D");
	}
	else if(*n>=400){
		*n-=400;
		strcat(string,"CD");
	}
	else if(*n>=100){
		*n-=100;
		strcat(string,"C");
	}
	else if(*n>=90){
		*n-=90;
		strcat(string,"XC");
	}
	else if(*n>=50){
		*n-=50;
		strcat(string,"L");
	}
	else if(*n>=40){
		*n-=40;
		strcat(string,"XL");
	}
	else if(*n>=10){
		*n-=10;
		strcat(string,"X");
	}
	else if(*n>=9){
		*n-=9;
		strcat(string,"IX");
	}
	else if(*n>=5){
		*n-=5;
		strcat(string,"V");
	}
	else if(*n>=4){
		*n-=4;
		strcat(string,"IV");
	}
	else if(*n>=1){
		*n-=1;
		strcat(string,"I");
	}
	return;
}

void romanToDec(char string[20]){
	int len=strlen(string);
	int i,total;

	int arr[len];

	for(i=0;i<len;i++){
		arr[i]=toInt(string[i]);
	}

	total=arr[len-1];
	for(i=len-2;i>-1;i--){
		if(arr[i]>=arr[i+1]){
			total+=arr[i];
		}
		else{
			total-=arr[i];
		}
	}

	printf("%d\n",total);

	return;
}

void decToRoman(char string[20]){
	int result;
	sscanf(string,"%d",&result);
	string[0]=0;
	while(result>0){
		search(&result,string);
	}
	printf("%s\n",string);
	return;
}

int main(){
	char string[20];
	while(scanf("%s",string)!=EOF){
		if(string[0]>57 || string[0]<48){
			romanToDec(string);
		}
		else{
			decToRoman(string);
		}
	}
	return 0;
}