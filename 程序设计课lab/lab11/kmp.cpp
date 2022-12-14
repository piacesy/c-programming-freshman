#include<stdio.h>
#include<string.h>
void get_next(int *next,char* s);
int kmp(char* p,char* s,int* next);
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		char p[10001];
		char s[10001];
		int  next[10001];
		scanf("%s",p);
		getchar();
		scanf("%s",s);
		get_next(next,p);
		int ans=kmp(p,s,next);
		printf("%d\n",ans);
	}
	return 0;
}
void get_next(int *next,char* s){
	int s_len=strlen(s);
	int pre=-1;
	int post=0;
	next[0]=-1;
	while(post<s_len){
		if(pre==-1||s[pre]==s[post]){
			pre++;
			post++;
			if(s[pre]!=s[post]){
				next[post]=pre;
			}
			else{
				next[post]=next[pre];
			}
		}
		else{
			pre=next[pre];
		}
	}
}
int kmp(char* p,char* s,int *next){
	int s_len=strlen(s);
	int p_len=strlen(p);
	int ans=0;
	int i=0;
	int j=0;
	while(i<s_len){
		if(j==-1||s[i]==p[j]){
			i++;
			j++;
			if(j==p_len){
				ans++;
				j=next[j];
			}
		}
		else{
			j=next[j];
		}
	}
	return ans;
}
