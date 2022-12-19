#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	char data[17];
	scanf("%s",data);
	int fault=0;
	int temp_1=0;
	for(int i=0;i<strlen(data);i++){
		if(data[i]=='1'){
			temp_1++;
		}
	}
	if(temp_1%2==1){
		if(data[0]=='0'){
			data[0]='1';
		}else{
			data[0]='0';
		}
		fault++;
	}
	for(int i=0;i<=3;i++){
		if(fault>2){
			break;
		}
		int temp_2=pow(2,i);
		int temp_3=0;
		for(int j=0;j<strlen(data);j++){
			if((j&temp_2)==temp_2){
				if(data[j]=='1'){
					temp_3++;
				}
			}
		}
		if(temp_3%2==1){
			if(data[temp_2]=='1'){
				data[temp_2]='0';
			}else{
				data[temp_2]='1';
			}
			fault++;
		}
	}
	if(fault==0){
		printf("No Error! Please go on!\n");
	}else if(fault<=2){
		printf("Error! The Recovered Data is %s\n",data);
	}else{
		printf("Irrecoverable Error! Please resend the message!\n");
	}
	return 0;
}
