#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}
int main(){
    int m,n;
    printf("请输入m:");
    scanf("%d",&m);
    getchar();
    int arr1[m];
    printf("请输入数组m:");
    for(int i=0;i<m;i++){
        scanf("%d",&arr1[i]);
    }
    getchar();
    printf("请输入n:");
    scanf("%d",&n);
    int arr2[n];
    printf("请输入数组n:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr2[i]);
    }
    qsort(arr1,m,sizeof(int),cmpfunc);
    qsort(arr2,n,sizeof(int),cmpfunc);
    int ansarr[m+n];
    for(int i=0,flag1=0,flag2=0;i<m+n;i++){
        if(flag1==m){
            ansarr[i]=arr2[flag2];
            flag2++;
        }
        else if(flag2==n){
            ansarr[i]=arr1[flag1];
            flag1++;
        }
        else if(arr1[flag1]<=arr2[flag2]){
            ansarr[i]=arr1[flag1];
            flag1++;
        }
        else if(arr1[flag1]>arr2[flag2]){
            ansarr[i]=arr2[flag2];
            flag2++;
        }
    }
    for(int i=0;i<n+m;i++){
        printf("%d ",ansarr[i]);
    }
    return 0;
}