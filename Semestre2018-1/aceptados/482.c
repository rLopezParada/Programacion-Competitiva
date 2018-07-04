#include <stdio.h>

struct numero{
	double value;
	char string[50];
};

typedef struct numero num;

int main(){
	int n,i,j,k,l,m,tam,p;
	num aux;
	char input[50000];
	char batch[50];
	int nums1[25000];
	num nums2[25000];


	scanf("%d",&n);
	getchar();

	for(i=0;i<n;i++){
		getchar();
		scanf("%[^\n]",input);
		getchar();
		j=k=l=0;
		while(1){
			batch[l]=input[j];
			l++;
			j++;
			if(batch[l-1]==32){
				sscanf(batch,"%d",&nums1[k]);
				k++;
				l=0;
			}
			else if(batch[l-1]==0){
				sscanf(batch,"%d",&nums1[k]);
				k++;
				break;
			}
		}
		tam=k;
		scanf("%[^\n]",input);
		getchar();

		j=k=l=0;
		for(m=0;m<tam;){
			batch[l]=input[j];
			l++;
			j++;
			if(batch[l-1]==32 || batch[l-1]==0){
				sscanf(batch,"%lf",&nums2[k].value);
				for(p=0;p<l;p++){
					nums2[k].string[p]=batch[p];
				}
				nums2[k].string[l-1]=0;
				k++;
				m++;
				l=0;
			}
		}


		for(j=0;j<tam;j++){
			l=j;
			for(k=j+1;k<tam;k++){
				if(nums2[k].value<nums2[l].value){
					l=k;
				}
			}

			if(l!=j){
				aux=nums2[j];
				nums2[j]=nums2[l];
				nums2[l]=aux;
			}
		}


		for(j=0;j<tam;j++){
			printf("%s\n",nums2[nums1[j]-1].string);
		}


	}
	return 0;
}