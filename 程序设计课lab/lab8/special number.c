#include<stdio.h>
int transform(int i,int n){
    if(i<n){
        return i;
    }
    else{
        return i%n+transform(i/n,n);
    }
    return 0;

}
int main(){
    int n1,n2,n3;
    for(int i=1000;i<9999;i++){
        n1=i/1000+(i%1000)/100+(i%100)/10+i%10;
        n2=transform(i,12);
        n3=transform(i,16);
        if(n1==n2&&n2==n3){
            printf("%d\n",i);
        }
    }
    return 0;
}