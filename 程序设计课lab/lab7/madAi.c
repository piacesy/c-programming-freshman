#include<stdio.h>
int main(){
    char record[50][51];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",record[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;record[i][j]!='\0';j++){
            if(record[i][j]=='Z'){
                record[i][j]='A';
            }
            else{
                record[i][j]+=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("String # %d\n%s\n",i+1,record[i]);
    }
    return 0;
}