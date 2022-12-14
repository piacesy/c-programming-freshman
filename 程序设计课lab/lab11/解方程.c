#include<stdio.h>
#include<math.h>
char record[10001];
int main(){
	gets(record);
	int i=0;
	int n1=0,n2=0,n3=0;
	int flag=1;
	while(record[i]!='\0'&&record[i]!='\n'){
		if(record[i]=='='){
			flag=-1;
			i++;
			continue;
		}
		if(record[i+2]=='x'&&record[i+3]=='^'){
			if(record[i]=='+'){
				n1=n1+flag*(record[i+1]-'0');
			}
			else if(record[i]=='-'){
				n1=n1-flag*(record[i+1]-'0');
			}
			i+=5;
		}
		else if(record[i+2]=='x'){
			if(record[i]=='+'){
				n2=n2+flag*(record[i+1]-'0');
			}
			else if(record[i]=='-'){
				n2=n2-flag*(record[i+1]-'0');
			}
			i+=3;
		}
		else{
			if(record[i]=='+'){
				n3=n3+flag*(record[i+1]-'0');
			}
			else if(record[i]=='-'){
				n3=n3-flag*(record[i+1]-'0');
			}
			i+=2;
		}
	}
	if(n2*n2-4*n1*n3==0){
		double x1;
		x1=sqrt(n3/n1);
		printf("%.2f\n",x1);
	}
	else if((n2*n2-4*n1*n3)>0){
		double x1,x2;
		int delta=n2*n2-4*n1*n3;
		x1=(-1*n2+sqrt(delta))/2/n1;
		x2=(-1*n2-sqrt(delta))/2/n1;
		printf("%.2f\n%.2f\n",x1,x2);
	}
	else{
		printf("No Solution\n");
	}
	return 0;
}
