#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
#include<limits.h>
struct node{
	int val;
	struct node* next;
};
typedef struct node node;
int main(){
	node* begin1=(node*)malloc(sizeof(node));
	node* end=begin1;
	begin1->next=NULL;
	printf("请输入链表的数据:\n");
	char input[200];
	gets(input);
	for(int i=0;i<strlen(input);i++){
		if(isdigit(input[i])){
			int val=0;
			node* new_node=(node*)malloc(sizeof(node));
			while(isdigit(input[i])){
				val=val*10+input[i]-'0';
				i++;
			}
			new_node->val=val;
			new_node->next=NULL;
			end->next=new_node;
			end=new_node;
		}
	}
	int len=0;
	node* temp1=begin1->next;
	while(temp1!=NULL){
		len++;
		temp1=temp1->next;
	}
	node* temp2=begin1;
	int ans=len/2+1;
	for(int i=0;i<ans;i++){
		temp2=temp2->next;
	}
	printf("%d\n",temp2->val);
	return 0;
}
