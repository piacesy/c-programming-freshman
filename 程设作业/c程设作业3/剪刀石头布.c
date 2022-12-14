#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    srand((unsigned)time(NULL));
    int flag=0;
    while(flag<2){
        printf("flag:%d\n",flag);
        int op1=rand()%3;
        int op2;
        printf("请输入你的选择：");
        scanf("%d",&op2);
        if((op1==0&&op2==1)||(op1==1&&op2==2)||(op1==2&&op2==0)){
            flag++;
        }
        system("cls");
    }
    printf("你赢了");
    return 0;
}
