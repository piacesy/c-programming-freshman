#include<stdio.h>
void qSort(int *arr,int left,int right){
    if(left>=right){
        return;
    }
    int i=left;
    int j=right;
    int init=arr[left];
    while(i<j){
       while(arr[i]<=init&&i<right){
         i++;
       }
       while(arr[j]>init){
        j--;
       }
       if(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
       }
    }
    arr[left]=arr[j];
    arr[j]=init;
    qSort(arr,left,j-1);
    qSort(arr,j+1,right);

}
int main(){
    int n;
    printf("Enter the length of array:");
    scanf("%d",&n);
    getchar();
    int arr[n];
    printf("enter the number:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    getchar();
    qSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}