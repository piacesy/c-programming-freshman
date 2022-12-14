#include<stdio.h>
int main(){
	int x=1;
	int y=1;
	char dir;
	int num;
	int n;
	scanf("%d",&n);
	printf("当前位置(1,1)\n");
	while(x!=n||y!=n){
		dir=getchar();
		scanf("%c,%d",&dir,&num);
		if(dir=='a'){
			x-=num;	
			if(x<1){
				x=1;
			}
		}
		else if(dir=='d'){
			x+=num;
			if(x>n){
				x=n;
			}
		}
		else if(dir=='w'){
			y-=num;
			if(y<1){
				y=1;
			}
		}
		else if(dir=='s'){
			y+=num;
			if(y>n){
				y=n;
			}
		}
	printf("当前位置(%d,%d)\n",x,y);
}
	return 0;
}
