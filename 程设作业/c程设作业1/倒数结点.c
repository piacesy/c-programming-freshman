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
	printf("���������������:\n");
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
	printf("��������Ҫ����ĵ�����k��������ֵ��\n");
	int k;
	scanf("%d",&k);
	node* n1=begin1->next;
	node* n2=begin1->next;
	for(int i=0;i<k;i++){
		if(n2==NULL){
			printf("��������Χ\n");
			return 0;
		}else{
			n2=n2->next;
		}
	}
	while(n2!=NULL){
		n2=n2->next;
		n1=n1->next;
	}
	printf("%d\n",n1->val);
	return 0;
}
