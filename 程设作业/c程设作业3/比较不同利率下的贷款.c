#include<stdio.h>
int main(){
    int amount,year;
    printf("Loan Amount:");
    scanf("%d",&amount);
    printf("Number of Years:");
    scanf("%d",&year);
    printf("Interest Rate Monthly Payment Total Payment\n");
    float rate=5;
    while(rate<=8){  
        float total=amount*rate/100*year+amount;
        float monthly=total/year/12;
        printf("%.3f%% %.2f %.2f\n",rate,monthly,total);
        rate+=0.125;
    }
    return 0;
}