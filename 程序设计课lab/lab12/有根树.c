#include<stdio.h>
int father[1000];
int flag[1000];
int LCA(int u,int v){
	if(u==v){
		return u;
	}
	flag[u]=1;
	while(father[u]!=u){
		u=father[u];
		flag[u]=1;
	}
	if(flag[v]==1){
		return v;
	}
	while(father[v]!=v){
		v=father[v];
		if(flag[v]==1){
			return v;
		}
	}
	return 0;
}
int main(){
	int T;
	scanf("%d",&T);
	getchar();
	for(int i=0;i<T;i++){
		int n,u,v;
		scanf("%d",&n);
		getchar();
		for(int j=0;j<n-1;j++){
			scanf("%d%d",&u,&v);
			father[v]=u;
		}
		scanf("%d%d",&u,&v);
		getchar();
		printf("%d\n",LCA(u,v));
	}
	return 0;
}
