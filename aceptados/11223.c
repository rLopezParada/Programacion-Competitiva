#include <stdio.h>
#include <string.h>

void letter(char batch[7]){
	if(strcmp(".-",batch)==0){
		printf("A");
	}
	else if(strcmp("-...",batch)==0){
		printf("B");
	}
	else if(strcmp("-.-.",batch)==0){
		printf("C");
	}
	else if(strcmp("-..",batch)==0){
		printf("D");
	}
	else if(strcmp(".",batch)==0){
		printf("E");
	}
	else if(strcmp("..-.",batch)==0){
		printf("F");
	}
	else if(strcmp("--.",batch)==0){
		printf("G");
	}
	else if(strcmp("....",batch)==0){
		printf("H");
	}
	else if(strcmp("..",batch)==0){
		printf("I");
	}
	else if(strcmp(".---",batch)==0){
		printf("J");
	}
	else if(strcmp("-.-",batch)==0){
		printf("K");
	}
	else if(strcmp(".-..",batch)==0){
		printf("L");
	}
	else if(strcmp("--",batch)==0){
		printf("M");
	}
	else if(strcmp("-.",batch)==0){
		printf("N");
	}
	else if(strcmp("---",batch)==0){
		printf("O");
	}
	else if(strcmp(".--.",batch)==0){
		printf("P");
	}
	else if(strcmp("--.-",batch)==0){
		printf("Q");
	}
	else if(strcmp(".-.",batch)==0){
		printf("R");
	}
	else if(strcmp("...",batch)==0){
		printf("S");
	}
	else if(strcmp("-",batch)==0){
		printf("T");
	}
	else if(strcmp("..-",batch)==0){
		printf("U");
	}
	else if(strcmp("...-",batch)==0){
		printf("V");
	}
	else if(strcmp(".--",batch)==0){
		printf("W");
	}
	else if(strcmp("-..-",batch)==0){
		printf("X");
	}
	else if(strcmp("-.--",batch)==0){
		printf("Y");
	}
	else if(strcmp("--..",batch)==0){
		printf("Z");
	}
	else if(strcmp("-----",batch)==0){
		printf("0");
	}
	else if(strcmp(".----",batch)==0){
		printf("1");
	}
	else if(strcmp("..---",batch)==0){
		printf("2");
	}
	else if(strcmp("...--",batch)==0){
		printf("3");
	}
	else if(strcmp("....-",batch)==0){
		printf("4");
	}
	else if(strcmp(".....",batch)==0){
		printf("5");
	}
	else if(strcmp("-....",batch)==0){
		printf("6");
	}
	else if(strcmp("--...",batch)==0){
		printf("7");
	}
	else if(strcmp("---..",batch)==0){
		printf("8");
	}
	else if(strcmp("----.",batch)==0){
		printf("9");
	}
	else if(strcmp(".-.-.-",batch)==0){
		printf(".");
	}
	else if(strcmp("--..--",batch)==0){
		printf(",");
	}
	else if(strcmp("..--..",batch)==0){
		printf("?");
	}
	else if(strcmp(".----.",batch)==0){
		printf("'");
	}
	else if(strcmp("-.-.--",batch)==0){
		printf("!");
	}
	else if(strcmp("-..-.",batch)==0){
		printf("/");
	}
	else if(strcmp("-.--.",batch)==0){
		printf("(");
	}
	else if(strcmp("-.--.-",batch)==0){
		printf(")");
	}
	else if(strcmp(".-...",batch)==0){
		printf("&");
	}
	else if(strcmp("---...",batch)==0){
		printf(":");
	}
	else if(strcmp("-.-.-.",batch)==0){
		printf(";");
	}
	else if(strcmp("-...-",batch)==0){
		printf("=");
	}
	else if(strcmp(".-.-.",batch)==0){
		printf("+");
	}
	else if(strcmp("-....-",batch)==0){
		printf("-");
	}
	else if(strcmp("..--.-",batch)==0){
		printf("_");
	}
	else if(strcmp(".-..-.",batch)==0){
		printf("%c",34);
	}
	else if(strcmp(".--.-.",batch)==0){
		printf("@");
	}
	return;
}

int main(){
	int cases,n,i,j;
	scanf("%d",&cases);
	getchar();

	char input[2001];
	char batch[7];

	for(n=1;n<=cases;n++){
		scanf("%[^\n]",input);
		getchar();

		printf("Message #%d\n",n);

		i=0;
		j=0;
		while(1){
			batch[j]=input[i];
			if(input[i]==32){
				batch[j]=0;
				letter(batch);
				j=-1;
				if(input[i+1]==32){
					printf(" ");
					i++;
				}
			}
			else if(input[i]==0){
				batch[j]=0;
				letter(batch);
				break;
			}
			i++;
			j++;
		}
		printf("\n");
		if(n!=cases){
			printf("\n");
		}
	}

	return 0;
}