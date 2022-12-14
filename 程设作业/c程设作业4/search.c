#include<stdio.h>
#include<limits.h>
int search(int arr[],int len){
    int max=INT_MIN;
    for(int i=0;i<len;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}
int fun(int m,int score[],int below[]){
    int num=0;
    int ave=0;
    for(int i=0;i<m;i++){
        ave+=score[i];
    }
    ave/=m;
    for(int i=0;i<m;i++){
        if(score[i]<ave){
            below[num++]=score[i];
        }
    }
    return num;
}
int fib(int n){
    if(n==1){
        return 1;
    }
    else if(n==0){
        return 0;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
int foldTimes(double dis,double thick){
    int i=0;
    while(thick<dis*1000000){
        thick*=2;
        i++;
    }
    return i;
}
int leapYear(int y){
    if((y%4==0&&y%100!=0)||(y%400==0)){
        return 1;
    }
    else{
        return 0;
    }
    return 0;
}
int whatDay(int year,int month){
    int day=(year/4-year/100+year/400+year-1)%7;
    
}
int main(){

}