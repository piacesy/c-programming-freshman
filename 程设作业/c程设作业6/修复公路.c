#include<stdio.h>
#include<stdlib.h>
int fa[1000],n,m;
struct node{
	int x;
	int y;
	int t;
}record[1000];
typedef struct node node;
int cmpfuc(const void* a,const void* b){
	int t1=(*(node*)a).t;
	int t2=(*(node*)b).t;
	if(t1>t2){
		return 1;
	}else{
		return -1;
	}
}
int find(int x){
	if(fa[x]==x){
		return x;
	}else{
		return fa[x]=find(fa[x]);
	}
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	fa[fx]=fy;
}
int check(){
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
int main(){
	int ans=0;
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=0;i<n;i++){
		fa[i]=i;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&record[i].x,&record[i].y,&record[i].t);
	}
	qsort(record,m,sizeof(struct node),cmpfuc);
	for(int i=0;i<m;i++){
		merge(record[i].x,record[i].y);
		if(check()){
			printf("%d",record[i].t);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
