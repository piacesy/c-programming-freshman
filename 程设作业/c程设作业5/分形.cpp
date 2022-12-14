#include<stdio.h>
#include<malloc.h>
#include<math.h>
char **box;
void set_box(int m,int x,int y);
int main(){
	for(;;){
		int m;
		scanf("%d",&m);
		getchar();
		if(m==0){
			break;
		}
		int len=pow(3,m);
		box=(char**)malloc(len*sizeof(char*));
		for(int i=0;i<len;i++){
			box[i]=(char*)malloc(len*sizeof(char));
		}
		for(int i=0;i<len;i++){
			for(int j=0;j<len;j++){
				box[i][j]=0;
			}
		}
		set_box(m,0,0);
		for(int i=0;i<len;i++){
			for(int j=0;j<len;j++){
				if(box[i][j]==1){
					printf("X");
				}
				else{
					printf(" ");
				}
			}
			printf("\n");
		}
		free(box);
	}
	return 0;
}
void set_box(int m,int x,int y){
	if(m==1){
		int seq=1;
		for(int i=x;i<x+3;i++){
			for(int j=y;j<y+3;j++){
				if(seq%2==0){
					box[i][j]=0;
				}
				else{
					box[i][j]=1;
				}
				seq++;
			}
		}
	}
	else{
		int len=pow(3,m-1);
		set_box(m-1,x,y);
		set_box(m-1,x+len*2,y);
		set_box(m-1,x,y+len*2);
		set_box(m-1,x+len*2,y+len*2);
		set_box(m-1,x+len,y+len);
	}
}
