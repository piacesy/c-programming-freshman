#include<stdio.h>
#include<malloc.h>
int main(){
	int n;
	printf("������С�Ƶĸ���:");
	scanf("%d",&n);
	int* record=(int*)malloc(sizeof(int)*n);
	printf("������ÿֻС�Ƶķ���:");
	for(int i=0;i<n;i++){
		scanf("%d",&record[i]);
	}
	int* left=(int*)malloc(sizeof(int)*n);
	int* right=(int*)malloc(sizeof(int)*n);
	left[0]=1;
	for(int i=1;i<n;i++){
		if(record[i]>record[i-1]){
			left[i]=left[i-1]+1;
		}else{
			left[i]=1;
		}
	}
	right[n-1]=1;
	for(int i=n-2;i>=0;i--){
		if(record[i]>record[i+1]){
			right[i]=right[i+1]+1;
		}else{
			right[i]=1;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(right[i]>=left[i]){
			ans+=right[i];
		}else{
			ans+=left[i];
		}
	}
	printf("����Ҫ�����ٵ��ǹ�����Ϊ��%d\n",ans);
	return 0;
}
