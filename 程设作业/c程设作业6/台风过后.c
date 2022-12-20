#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int* fa;
typedef struct{
	int x;
	int y;
	int t;
}node;
int cmp(const void* a,const void* b){
	int n1=(*(node*)a).t;
	int n2=(*(node*)b).t;
	if(n1>n2){
		return 1;
	}else{
		return -1;
	}
}
int check(int n){
	int mark=0;
	for(int i=0;i<n;i++){
		if(fa[i]==i){
			mark++;
		}
		if(mark>1){
			return 0;
		}
	}
	return 1;
}
int find(int i){
	if(fa[i]==i){
		return i;
	}else{
		return fa[i]=find(fa[i]);
	}
	return 0;
}
void merge(int i,int j){
	int fa_i=find(i);
	int fa_j=find(j);
	fa[fa_i]=fa_j;
}
int main(){
	int n,m;
	int ans=0;
	scanf("%d%d",&n,&m);
	getchar();
	fa=(int*)malloc(sizeof(int)*n);
	node* record=(node*)malloc(sizeof(node)*m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&record[i].x,&record[i].y,&record[i].t);
		getchar();
	}
	qsort(record,m,sizeof(node),cmp);
	printf("test1\n");
	for(int i=0;i<n;i++){
		fa[i]=i;
	}
	printf("test2\n");
	for(int i=0;i<m;i++){
		merge(record[i].x,record[i].y);
		ans+=record[i].t;
		if(check(n)==1){
			printf("%d\n",ans);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
