#include<stdio.h>
int main(){
    int n;
    int bool=1;
    printf("Enter number n:");
    scanf("%d",&n);
    getchar();
    printf("Enter %d rows of letters",n);
    char matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%c",&matrix[i][j]);
        }
        getchar();
        for(int j=0;j<n;j++){
            if(matrix[i][j]-'A'>=n){
                printf("Wrong input:the letters must be from A to %c\n",'A'+n-1);
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        int flag[26]={0};
        for(int j=0;j<n;j++){
            flag[matrix[i][j]-'A']++;
        }
        for(int j=0;j<n;j++){
            if(flag[j]!=1){
                bool=0;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        int flag[26]={0};
        for(int j=0;j<n;j++){
            flag[matrix[j][i]-'A']++;
        }
        for(int j=0;j<n;j++){
            if(flag[j]!=1){
                bool=0;
                break;
            }
        }
    }
    if(bool){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
    return 0;
}
