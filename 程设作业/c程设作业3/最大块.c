#include<stdio.h>
int main(){
    int n;
    printf("Enter the number of rows in the matrix:");
    scanf("%d",&n);
    int matrix[n][n];
    for(int i=0;i<n;i++){            
        getchar();
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    int ansx,ansy,ansSize;
    for(int i=n;i>=1;i--){
        for(int y=0;y<=n-i;y++){
            for(int j=0;j<=n-j;j++){
                int ans=0;
                for(int m=y;m<y+i;m++){
                    for(int n=j;n<j+i;n++){
                        ans+=matrix[m][n];
                    }
                }
                if(ans==i*i){
                    ansx=y;
                    ansy=j;
                    ansSize=i;
                    goto next;
                }
            }
        }
    }
    next:
    printf("The maximum square submatrix is at(%d,%d)with size %d",ansx,ansy,ansSize);
    return 0;
}