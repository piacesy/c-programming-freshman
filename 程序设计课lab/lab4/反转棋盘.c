#include<stdio.h>
int main(){
	char map[10][10];
	for(int i=0;i<10;i++){
		scanf("%s",map[i]);
	}
	int m,n;
	char op[10];
	for(;;){
		scanf("%s",&op);
		if(op[0]=='e'){
			break;
		}
		switch(op[0]){
			case 'r':{
				scanf("%d",&m);	
				for(int i=0;i<10;i++){
					if(map[m-1][i]=='0'){
						map[m-1][i]='1';
					}
					else{
						map[m-1][i]='0';
					}
					printf("%c",map[m-1][i]);
				}
				printf("\n");
				break;
			}
			case 'a':{
				scanf("%d%d",&m,&n);
				for(int i=0;i<10;i++){
					printf("%d",map[m-1][i]-'0'&map[n-1][i]-'0');
				}
				printf("\n");
				break;
			}
			case 'o':{
				scanf("%d%d",&m,&n);
				for(int i=0;i<10;i++){
					printf("%d",map[m-1][i]-'0'|map[n-1][i]-'0');
				}
				printf("\n");
				break;
			}
			case 'd':{
				scanf("%d%d",&m,&n);
				for(int i=0;i<10;i++){
					printf("%d",map[m-1][i]-'0'^map[n-1][i]-'0');
				}
				printf("\n");
				break;
			}
			default:{
				
				break;
			}
			
	}
	}
}
