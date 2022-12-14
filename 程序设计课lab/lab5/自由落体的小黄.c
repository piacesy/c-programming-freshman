#include<stdio.h>
int main(){
    float h,sum=0;
    int n;
    scanf("%f,%d",&h,&n);
    int i=1;
    while(i<=n){
        if(i==1){
            sum+=h;
        }
        else{
            sum+=(2*h);
        }
        h/=2;
        i++;
    }
    printf("%.1f,%.1f",h,sum+h);
    return 0;
}