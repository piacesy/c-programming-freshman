#include<stdio.h>
#include<string.h>
int main(){
    int size;
    printf("Enter size:");
    scanf("%d",&size);
    float matrix1[size][size];
    float matrix2[size][size];
    float ans[size][size];
    memset(ans,0,sizeof(ans));
    printf("Enter matrix1:");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%f",&matrix1[i][j]);
        }
    }
    printf("Enter matrix2:");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%f",&matrix2[i][j]);
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            for(int y=0;y<size;y++){
                ans[i][j]+=matrix1[i][y]*matrix2[y][j];
            }
        }
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%.1f ",matrix1[i][j]);
        }
        if(i==1){
            printf("  *  ");
        }
        else{
            printf("     ");
        }
        for(int j=0;j<size;j++){
            printf("%.1f ",matrix2[i][j]);
        }
        if(i==1){
            printf("  =  ");
        }
        else{
            printf("     ");
        }
        for(int j=0;j<size;j++){
            printf("%.1f ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}