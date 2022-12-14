#include<stdio.h>
#include<limits.h>
int main(){
	int n;
	scanf("%d",&n);
	int v[n],t[n];
	for(int i=0;i<n;i++){
		scanf("%d%d",&v[i],&t[i]);
	}
	int m;
	scanf("%d",&m);
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		if(t[i]<0){
			continue;
		}
		int time=4.5/v[i]*3600+t[i];
		if(time<ans){
			ans=time;
		}
	}
	printf("%d",ans);
	return 0;
}
