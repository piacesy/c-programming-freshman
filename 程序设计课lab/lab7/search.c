#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<math.h>
typedef struct{
    int x;
    int y;
}index;
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    char record[500];
    char page[10][200][10];
    for(int i=0;i<n;i++){
        gets(record);
        int num1=0;
        int num2=0;
        for(int j=0;j<strlen(record);j++){
            if(isalpha(record[j])!=0){
                page[i][num1][num2]=record[j];
                num2++;
            }
            else{
                while(j+1<strlen(record)&&isalpha(record[j+1])==0){
                    j++;
                }
                num1++;
                num2=0;
            }
        }
    }
    printf("请输入要查找的词个数：");
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        char s1[10];
        char s2[10];
        index ans1[50];
        index ans2[50];
        int ansnum1=0;
        int ansnum2=0;
        int min=INT_MAX;
        int minpage;
        scanf("%s",s1);
        getchar();
        scanf("%s",s2);
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=0;page[i][j][0]!='\0';j++){
                if(strcmp(s1,page[i][j])==0){
                    ans1[ansnum1].x=i+1;
                    ans1[ansnum1].y=j+1;
                    ansnum1++;
                    flag++;
                }
                if(strcmp(s2,page[i][j])==0){
                    ans2[ansnum2].x=i+1;
                    ans2[ansnum2].y=j+1;
                    ansnum2++;
                    flag++;
                }
                if(flag>=2){
                    if(min>abs(ans2[ansnum2-1].y-ans1[ansnum1-1].y)){
                        minpage=i+1;
                    }
                }
            }
        }
        if(ansnum1==0){
            printf("NULL");
        }
        else{
            printf("%s:",s1);
            for(int j=0;j<ansnum1;j++){
                printf("%d-%d  ",ans1[j].x,ans1[j].y);
            }
            printf("\n");
        }
        if(ansnum2==0){
            printf("NULL");
        }
        else{
            printf("%s:",s2);
            for(int j=0;j<ansnum2;j++){
                printf("%d-%d ",ans2[j].x,ans2[j].y);
            }
            printf("\n");
        }
        if(min==INT_MAX){
            printf("NULL");
        }
        else{
            printf("%d\n",minpage);
        }
    }
    return 0;
}