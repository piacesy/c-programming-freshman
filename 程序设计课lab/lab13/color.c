#include<stdio.h>
#include<string.h>
#define RED "\033[0;32;31m"
#define GREEN "\033[0;32;32m"
#define BLUE "\033[0;32;34m"
#define BLACK "\033[0;30;40m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[0;35;45m"
#define CYAN "\033[0;36m"
#define WHITE "\033[1;37m"
int main(){
	int state[100];
	int top=-1;
	char input[1000];
	char temp;
	int len=0;
	while(temp=getchar()){
		if(temp=='#'){
			break;
		}else if(temp=='\n'){
			continue;
		}else{
			input[len]=temp;
			len++;
		}
	}
	input[len]=0;
	for(int i=0;i<len;i++){
		if(input[i]=='<'){
			if(input[i+1]=='/'){
				top--;
			}else if(input[i+8]=='r'){
				top++;
				state[top]=1;
			}else if(input[i+8]=='g'&&input[i+9]=='r'){
				top++;
				state[top]=2;
			}else if(input[i+8]=='b'&&input[i+10]=='u'){
				top++;
				state[top]=3;
			}else if(input[i+8]=='b'&&input[i+10]=='a'){
				top++;
				state[top]=4;
			}else if(input[i+8]=='y'){
				top++;
				state[top]=5;
			}else if(input[i+8]=='m'){
				top++;
				state[top]=6;
			}else if(input[i+9]=='c'){
				top++;
				state[top]=7;
			}
		}else if(input[i]=='@'){
			if(top==-1){
				printf(WHITE"@");
			}else{
				switch(state[top]){
					case 1:{
						printf(RED"@");
						break;
					}
					case 2:{
						printf(GREEN"@");
						break;
					}
					case 3:{
						printf(BLUE"@");
						break;
					}
					case 4:{
						printf(BLACK"@");
						break;
					}
					case 5:{
						printf(YELLOW"@");
						break;
					}
					case 6:{
						printf(MAGENTA"@");
						break;
					}
					case 7:{
						printf(CYAN"@");
						break;
					}
				}
			}
		}
	}
	return 0;
}
