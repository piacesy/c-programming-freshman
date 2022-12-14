#include<stdio.h>
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
    int mon[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
    int leap=leapYear(year);
    for(int i=0;i<month-1;i++){
        day=(day+mon[leap][i])%7;
    }
    return day;
}
int main(){
    int year,month;
    int mon[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
    printf("请输入年份：");
    scanf("%d",&year);
    getchar();
    printf("请输入月份:");
    scanf("%d",&month);
    int day=whatDay(year,month);
    day=(day+6)%7+2;
    printf("一\t二\t三\t四\t五\t六\t日\t\n");
    for(int i=1;i<day;i++){
        printf("\t");
    }
    for(int i=1;i<=mon[leapYear(year)][month];i++){
        printf("%d\t",i);
        if((day+i-1)%7==0){
            printf("\n");
        }
    }
    return 0;
}