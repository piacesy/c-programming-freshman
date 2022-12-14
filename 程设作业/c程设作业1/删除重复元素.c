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
	int pre=INT_MAX;
	node* pre_node=begin1;	
	begin1=begin1->next;
	node* begin=begin1;	
	while(begin1!=NULL){
		if(begin1->val==pre){
			pre_node->next=begin1->next;
			begin1=begin1->next;
		}else{
			pre=begin1->val;
			pre_node=pre_node->next;
			begin1=begin1->next;
		}
	}
	while(begin!=NULL){
		if(begin->next==NULL){
			printf("%d",begin->val);
		}else{
			printf("%d,",begin->val);
		}
		begin=begin->next;
	}
	return 0;
}
