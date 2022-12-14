#include<stdio.h>
int  check(int matrix[100][100],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<=c-4;j++){
            int flag=1;
            int num=matrix[i][j];
            for(int y=j;y<=j+3;y++){
                if(matrix[i][y]!=num){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                return 1;
            }

        }
    }
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j <= r - 4; j++)
        {
            int flag = 1;
            int num = matrix[j][i];
            for (int y = j; y <= j + 3; y++)
            {
                if (matrix[y][i] != num)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                return 1;
            }
        }
    }
    for(int i=0;i<=r-4;i++){
        for(int j=0;j<c-4;j++){
            int flag=1;
            int num=matrix[i][j];
            int m=i;
            int n=j;
            for(int t=0;t<4;t++){
                if(matrix[m][n]!=num){
                    flag=0;
                    break;
                }
                m++;
                n++;
            }
            if(flag==1){
                return 1;
            }
        }
    }
    for(int i=3;i<r;i++){
        for(int j=0;j<c-4;j++){
            int flag=1;
            int num=matrix[i][j];
            int m=i;
            int n=j;
            for(int t=0;t<4;t++){
                if(matrix[m][n]!=num){
                    flag=0;
                    break;
                }
                m--;
                n++;
            }
            if(flag==1){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int r,c;
    printf("请输入数组的行数:");
    scanf("%d",&r);
    printf("请输入数组的列数:");
    scanf("%d",&c);
    int matrix[100][100];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    if(check(matrix,r,c)==1){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
}