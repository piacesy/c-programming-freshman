#include<stdio.h>
int main(){
    float init,rate,month;
    printf("Enter the initial deposit amount:");
    scanf("%f",&init);
    printf("Enter annual percentage yield:");
    scanf("%f",&rate);
    printf("Enter maturity period(number of months):");
    scanf("%f",&month);
    printf("Month   CD Value\n");
    for(int i=1;i<=month;i++){
        init += init*rate/1200;
        printf("%d %.2f\n",i,init);
    }
    return 0;
}