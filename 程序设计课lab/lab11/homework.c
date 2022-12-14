#include<stdio.h>
#include<malloc.h>
int main(){
	int m,h,ans,max=-1,min=1;
	int *homework;
	int k;
	scanf("%d%d",&m,&h);
	getchar();
	homework=(int*)malloc(sizeof(int)*m);
	for(int i=0;i<m;i++){
		scanf("%d",&homework[i]);
		if(max<homework[i]){
			max=homework[i];
		}
	}
	while(min<max){
		int mid=min+(max-min)/2;
		int total_time=0;
		for(int i=0;i<m;i++){
			if(homework[i]%mid==0){
				total_time+=homework[i]/mid;
			}
			else{
				total_time+=homework[i]/mid+1;
			}
		}
		if(total_time>h){
			min=mid+1;
		}
		else if(total_time<=h){
			ans=mid;
			max=mid;
		}
	}
	printf("%d",ans);
	return 0;
}
