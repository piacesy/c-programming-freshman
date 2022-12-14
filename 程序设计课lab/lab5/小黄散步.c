#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int x=0;
    int y=0;
    char dir;
    int num;
    while(x!=n-1||y!=n-1){
        scanf("%c,%d",&dir,&num);
        switch(dir){
            case 's':{
                x+=num;
                break;
            }
            case 'a':{
                y-=num;
                break;
            }
            case 'w':{
                x-=num;
                break;
            }
            case 'd':{
                y+=num;
                break;
            }
        }
        printf("当前位置(%d,%d)\n",y+1,x+1);
    }
    return 0;
}