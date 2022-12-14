#include<stdio.h>
int main(){
    int  brackets[][5] = {
 {8350, 33950, 82250, 171550, 372950}, 
 {16700, 67900, 137050, 20885, 372950},
 {8350, 33950, 68525 , 10445, 186475}, 
 {11950, 45500, 117450, 190200, 372950}
};
    double rates[6] ={0.10, 0.15, 0.25, 0.28, 0.33,0.35};
printf("请输入纳税人类型：");
int type;
scanf("%d",&type);
printf("请输入可纳税收：");
int money;
scanf("%d",&money);
double tax=0;
for(int i=0;i<5;i++){
    if(money<0){
        break;
    }
    if(i==0){
        if(money<=brackets[type][0]){
            tax+=rates[0]*brackets[type][0];
        }
        else{
            tax+=brackets[type][0]*rates[0];
            money-=brackets[type][0];
        }
    }
    else{
        if(money<=brackets[type][i]-brackets[type][i-1]){
            tax+=rates[i]*(money-brackets[type][i]+brackets[type][i-1]);
            money-=(brackets[type][i]-brackets[type][i-1]);
        }
    }
}
printf("应缴纳的税收为：%.2lf",tax);
}