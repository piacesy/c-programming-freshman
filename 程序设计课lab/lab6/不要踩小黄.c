#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    char map[n][n];
    int record1[n][n];
    char record2[n][n];
    getchar();
    memset(record1,0,sizeof(record1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%c",&map[i][j]);
        }
        getchar();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i-1>-1&&j-1>-1&&map[i-1][j-1]=='*'){
                record1[i][j]++;
            }
            if(i-1>-1&&map[i-1][j]=='*'){
                record1[i][j]++;
            }
            if(i-1>-1&&j+1<n&&map[i-1][j+1]=='*'){
                record1[i][j]++;
            }
            if(j-1>-1&&map[i][j-1]=='*'){
                record1[i][j]++;
            }
            if(j+1<n&&map[i][j+1]=='*'){
                record1[i][j]++;
            }
            if(i+1<n&&j-1>-1&&map[i+1][j-1]=='*'){
                record1[i][j]++;
            }
            if(i+1<n&&map[i+1][j]=='*'){
                record1[i][j]++;
            }
            if(i+1<n&&j+1<n&&map[i+1][j+1]=='*'){
                record1[i][j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d",record1[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%c",&record2[i][j]);
        }
        getchar();
    }
    int flag=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(record2[i][j]=='x'&&map[i][j]=='*'){
                flag=1;
                goto next;
            }
        }
    }
    next:
    if(flag==0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(record2[i][j]=='x'){
                    printf("%d",record1[i][j]);
                }
                else{
                    printf(".");
                }
            }
            printf("\n");
        }
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(map[i][j]=='*'){
                    printf("*");
                }
                else if(record2[i][j]=='x'){
                    printf("%d",record1[i][j]);
                }
                else{
                    printf(".");
                }
            }
            printf("\n");
        }
    }
    return 0;
}