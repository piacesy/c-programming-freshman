#include<stdio.h>
int main(){
	int n=0;
	for(int i=0;i<4;i++){
		int b;
		scanf("%d",&b);
		if(b!=0)
		n++;
	}
	if(n==0){
		printf("Typically Otaku");
	}
	else if(n==1){
		printf("Eye-opener");
	}
	else if(n==2){
		printf("Young Traveller");
	}
	else if(n==3){
		printf("Excellent Traveller");
	}
	else if(n==4){
		printf("Contemporary Xu Xiake");
	}
	return 0;
}
