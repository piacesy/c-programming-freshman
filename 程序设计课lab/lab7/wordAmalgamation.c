#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int unorcmp(char *s1,char *s2){
    int book1[26]={0};
    int book2[26]={0};
    for(int i=0;s1[i]!='\0';i++){
        book1[s1[i]-'a']++;
    }
    for(int i=0;s2[i]!='\0';i++){
        book2[s2[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(book1[i]!=book2[i]){
            return 0;
        }
    }
    return 1;

}
int cmpfunc(const void *a,const void *b){
    return strcmp(a,b);
}
int main(){
    char dic[100][20];
    char target[100][20];
    char ans[100][20];
    int len1;
    int len2;
    for(len1=0;;len1++){
        if(len1!=0&&strcmp(dic[len1-1],"XXXXXX")==0){
            break;
        }
        scanf("%s",dic[len1]);
        getchar();
    }
    for(len2=0;;len2++){
        if(len2!=0&&strcmp(target[len2-1],"XXXXXX")==0){
                break;
        }
        scanf("%s",target[len2]);
        getchar();
    }
    for(int i=0;i<len2;i++){
        int num=0;
        for(int j=0;j<len1;j++){
            if(unorcmp(target[i],dic[j])==1){
                strcpy(ans[num],dic[j]);
                num++;
            }
        }
        if(num==1){
            printf("%s\n",ans[0]);
        }
        else if(num==0){
            printf("Not A VALID WORK\n");
        }
        else{
            qsort(ans,num,sizeof(char)*20,cmpfunc);
            for(int j=0;j<num;j++){
                if(j==0||(strcmp(ans[j],ans[j-1])!=0))
                printf("%s\n",ans[j]);
            }
        }
        printf("******\n");
    }
    return 0;
}