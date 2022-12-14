#include<stdio.h>
#include<string.h>
int main(){
	char n1[100];
	char n2[100];
	scanf("%s%s",n1,n2);
	int num1[100];
	int num2[100];
	int ans[100]={0};
	int flag=1;
	int len1;
	int len2;
	if(n1[0]=='-'){
		flag*=-1;
		len1=strlen(n1)-1;
		for(int i=1;i<strlen(n1);i++){
			num1[strlen(n1)-i-1]=n1[i];
		}
	}else{
		len1=strlen(n1);
		for(int i=0;i<strlen(n1);i++){
			num1[strlen(n1)-i-1]=n1[i];
		}
	}
	if(n2[0]=='-'){
		flag*=-1;
		len2=strlen(n2)-1;
		for(int i=0;i<strlen(n2);i++){
			num2[strlen(n2)-i-1]=n2[i];
		}
	}else{
		len2=strlen(n2);
		for(int i=0;i<strlen(n2);i++){
			num2[strlen(n2)-i-1]=n2[i];
		}
	}
	for(int i=0;i<len1;i++){
		for(int j=0;j<len2;j++){
			ans[i+j]+=(num1[i]-'0')*(num2[j]-'0');
			ans[i+j+1]+=ans[i+j]/10;
			ans[i+j]%=10;
		}
	}
	if(flag==-1){
		printf("-");
	}
	for(int i=99,mark=0;i>=0;i--){
		if(mark==1){
			printf("%d",ans[i]);
		}else if(ans[i]!=0){
			mark=1;
			printf("%d",ans[i]);
		}else{
			continue;
		}
	}
	return 0;
}
