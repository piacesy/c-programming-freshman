#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct{
    int init;
    int end;
    int num;
}pack;
int* record;
pack* packs;
int* max;
void dfs(int num,int profit,int k,int n);
int totalpeople(int pos,int k);
int cmpfuc(const void* a,const void* b);
int main(){
    int m,n,k;
    for(;;){
        scanf("%d%d%d",&n,&m,&k);
        getchar();
        if(m==0&&n==0&&k==0){
            break;
        }
        max=(int*)malloc(sizeof(int));
        record=(int*)malloc(sizeof(int)*k);
        packs=(pack*)malloc(sizeof(pack)*k);
        for(int i=0;i<k;i++){
            record[i]=0;
        }
        *max=0;
        for(int i=0;i<k;i++){
            scanf("%d%d%d",&packs[i].init,&packs[i].end,&packs[i].num);
            getchar();
        }
        qsort(packs,k,sizeof(pack),cmpfuc);
        dfs(0,0,k,n);
        printf("%d\n",*max);
        free(max);
        free(record);
        free(packs);
    }
    return 0;
    system("pause");
}
int cmpfuc(const void* a,const void* b){
    return (*(pack*)a).init-(*(pack*)b).init;
}
int totalpeople(int pos,int k){
    int contain=0;
    for(int i=0;i<k;i++){
        if(record[i]==1){
            if(packs[i].end>pos){
                contain+=packs[i].num;
            }
        }
    }
    return contain;
}
void dfs(int num,int profit,int k,int n){
    int total;
    int flag=0;
    for(int i=num;i<k;i++){
        total=totalpeople(packs[i].init,k)+packs[i].num;
        if(total>n){
            continue;
        }
        else{
            record[i]=1;
            dfs(i+1,profit+packs[i].num,k,n);
            record[i]=0;
            flag=1;
        }
    }
    if(flag==0){
        if(profit>*max){
            *max=profit;
        }
    }
    return ;
}