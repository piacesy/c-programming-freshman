#include<stdio.h>
int main(){
    int a,n=1;
    scanf("%d",&a);
    while(a!=495){
        int n1=a/100;
        int n2=(a/10)%10;
        int n3=a%10;
        if(n1<n2){
            int tmp=n1;
            n1=n2;
            n2=tmp;
        }
        if(n1<n3){
            int tmp=n1;
            n1=n3;
            n3=tmp;
        }
        if(n2<n3){
            int tmp=n2;
            n2=n3;
            n3=tmp;
        }
        int b=n1*100+n2*10+n3;
        int c=n3*100+n2*10+n1;
        a=b-c;
        printf("%d:%d-%d=%d\n",n,b,c,a);
        n++;
    }
    return 0;
}