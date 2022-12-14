#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main(){
    char res[10][20]={"coast","beach","central","scenic","queen","conditioner","communicate",
    "cupboard","customer","chemical"};
    int flag=1;
    while(flag){
        srand((unsigned)time(NULL));
        int n=rand()%10;
        char tmp1[15];
        char tmp2[15];
        int count=0;
        strcpy(tmp1,res[n]);
        strcpy(tmp2,res[n]);
        while(1){
            int mark=0;
            for(int i=0;i<strlen(tmp1);i++){
                if(tmp1[i]!='*'){
                    mark=1;
                    break;
                }
            }
            if(mark==0){
                break;
            }
            printf("Enter a letter in word   ");
            for(int i=0;i<strlen(tmp1);i++){
                if(tmp1[i]=='*'){
                    printf("%c",tmp2[i]);
                }
                else{
                    printf("*");
                }
            }
            printf(">>");
            char c;
            scanf("%c",&c);
            getchar();
            int mark1=0;
            for(int i=0;i<strlen(tmp1);i++){
                if(tmp1[i]==c){
                    tmp1[i]='*';
                    mark1=1;
                }
                else if(tmp2[i]==c){
                    mark1=2;
                }
            }
            if(mark1==0){
                printf("%c is not in the word\n",c);
                count++;
            }
            else if(mark1==2){
                printf("%c is already in the word\n",c);
            }
        }
        printf("the word is %s,you missd %d time\n",tmp2,count);
        printf("do you want to continue:(enter yes or no)");
        char des[4];
        scanf("%s",des);
        getchar();
        if(strcmp(des,"yes")==0){
            ;
        }
        else{
            flag=0;
        }
        system("cls");
    }
}