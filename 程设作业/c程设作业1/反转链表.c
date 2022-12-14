#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<ctype.h>
struct node{
	int val;
	struct node* next;
};
typedef struct node node;
void reverse(node* begin,node* pre,node*now){
	if(now==NULL){
		begin->next=pre;
		return;
	}else{
		reverse(begin,now,now->next);
		now->next=pre;
	}
}
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
	reverse(begin1,begin1,begin1->next);
	for(node* i=begin1->next;i!=begin1;i=i->next){
		if(i->next==begin1){
			printf("%d",i->val);
		}else{
			printf("%d,",i->val);
		}
	}
	return 0;
} 
