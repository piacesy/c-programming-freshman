#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    int num;
    char name[30];
} tree;
int cmpfuc(const tree *a,const tree *b){
    return (*a).num-(*b).num;
}
int main(){
    tree record[10000];
    int num;
    printf("enter \"exit\" to break\n");
    while(1){
        char temp[30];
        gets(temp);
        int mark=strcmp(temp,"exit");
        if(mark==0){
            break;
        }
        int flag=0;
        for(int i=0;i<num;i++){
            if(strcmp(temp,record[i].name)==0){
                record[i].num++;
                flag=1;
                break;
            }
        }
        if(flag==0){
            strcpy(record[num].name,temp); 
            record[num].num=1;
            num++;
        }
    }
    qsort(record,num,sizeof(tree),cmpfuc);
    int total=0;
    for(int i=0;i<num;i++){
        total+=record[i].num;
    }
    for(int i=num-1;i>=0;i--){
        printf("%s    %.4f\n",record[i].name,((float)record[i].num)/total*100);
    }
    return 0;
}
