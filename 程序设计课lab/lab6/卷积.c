#include<stdio.h>
#include<string.h>
int main(){
    int size1,size2;
    scanf("%d %d",&size1,&size2);
    int matrix1[size1][size1];
    int matrix2[size2][size2];
    int ans[size1-size2+1][size1-size2+1];
    memset(ans,0,sizeof(ans));
    for(int i=0;i<size1;i++){
        for(int j=0;j<size1;j++){
            scanf("%d",&matrix1[i][j]);
        }

    }
    for(int i=0;i<size2;i++){
        for(int j=0;j<size2;j++){
            scanf("%d",&matrix2[i][j]);
        }
    }
    for(int i=0;i<size1-size2+1;i++){
        for(int j=0;j<size1-size2+1;j++){
            for(int m=0;m<size2;m++){
                for(int n=0;n<size2;n++){
                    ans[i][j]+=matrix1[i+m][j+n]*matrix2[m][n];
                }
            }
        }
    }
    for(int i=0;i<size1-size2+1;i++){
        for(int j=0;j<size1-size2+1;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}