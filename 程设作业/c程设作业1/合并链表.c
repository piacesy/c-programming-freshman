#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
struct node{
	int val;
	struct node* next;
};
typedef struct node node;
void merge(node* begin1,node* begin2,node* ans){
	if(begin1==NULL){
		while(begin2!=NULL){
			node* temp=begin2;
			begin2=begin2->next;
			temp->next=ans->next;
			ans->next=temp;
		}
		return;
	}else if(begin2==NULL){
		while(begin1!=NULL){
			node* temp=begin1;
			begin1=begin1->next;
			temp->next=ans->next;
			ans->next=temp;
		}
		return;
	}else{
		if(begin1->val>=begin2->val){
			node* next=begin1->next;
			begin1->next=ans->next;
			ans->next=begin1;
			merge(next,begin2,ans);
		}else{
			node* next=begin2->next;
			begin2->next=ans->next;
			ans->next=begin2;
			merge(begin1,next,ans);
		}
	}
}
int main(){
	node* begin1=(node*)malloc(sizeof(node));
	node* begin2=(node*)malloc(sizeof(node));
	begin1->next=begin2->next=NULL;
	printf("请输入第一个链表的数据:\n");
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
			new_node->next=begin1->next;
			begin1->next=new_node;
		}
	}
	printf("请输入第二个链表的数据:\n");
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
			new_node->next=begin2->next;
			begin2->next=new_node;
		}
	}
	node* ans=(node*)malloc(sizeof(node));
	ans->next=NULL;
	merge(begin1->next,begin2->next,ans);
	ans=ans->next;
	while(ans!=NULL){
		if(ans->next==NULL){
			printf("%d",ans->val);
		}else{
			printf("%d,",ans->val);
		}
		ans=ans->next;
	}
	return 0;
}
