#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=n-i){
                printf("  ");
            }
            else{
                printf("%d ",n-j+1);
            }
        }
        for(int j=2;j<=n;j++){
            if(j<=i){
                printf("%d ",j);
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}
