#include<stdio.h>
#include<string.h>
int main(){
	char s[100];
	scanf("%s",s);
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		int index;
		scanf("%d",&index);
		getchar();
		char target[50];
		char source[50];
		scanf("%s%s",source,target);
		if(strncmp(source,&(s[index]),strlen(source))==0){
			char temp[50];
			strcpy(temp,&(s[index+strlen(source)]));
			strcpy(&(s[index]),target);
			strcat(s,temp);
		}
	}
	printf("%s\n",s);
	return 0;
}
