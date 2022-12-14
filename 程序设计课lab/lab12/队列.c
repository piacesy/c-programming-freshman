#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node{
	int x;
	struct node* next;
};
typedef struct node node;
node** record;
node** postion;
node* begin;
node* end;
int search(int x,int size){
	for(int i=0;i<size;i++){
		node* begin=record[i]->next;
		while(begin!=NULL){
			if(begin->x==x){
				return i;
			}
			else{
				begin=begin->next;
			}
		}
	}
}
int main(){
	int round=0;
	while(1){
		round++;
		printf("Scenario #%d\n",round);
		int t;
		scanf("%d",&t);
		getchar();
		if(t==0){
			break;
		}
		node* begin=(node*)malloc(sizeof(node));
		begin->next=NULL;
		begin->x=0;
		end=begin;
		node** record=(node**)malloc(sizeof(node*)*t);
		node** position=(node**)malloc(sizeof(node*)*t);
		for(int i=0;i<t;i++){
			record[i]=malloc(sizeof(node));
			record[i]->next=NULL;
			record[i]->x=0;
			position[i]=NULL;
		}
		for(int i=0;i<t;i++){
			int j;
			scanf("%d",&j);
			for(int y=0;y<j;y++){
				int temp_num;
				scanf("%d",&temp_num);
				node* temp=(node*)malloc(sizeof(node));
				temp->x=temp_num;
				temp->next=record[i]->next;
				record[i]->next=temp;
			}
			getchar();
		}
		char command[20];
		int x;
		while(1){
			scanf("%s",command);
			if(strcmp(command,"DEQUEUE")==0){
				getchar();
				for(int i=0;i<t;i++){
					if(begin->next==position[i]){
						position[i]=NULL;
						break;
					}
				}
				if(begin->next==end){
					end=begin;
				}
				printf("%d\n",begin->next->x);
				begin->next=begin->next->next;
			}
			else if(strcmp(command,"ENQUEUE")==0){
				scanf("%d",&x);
				getchar();
				node* new_node=(node*)malloc(sizeof(node));
				new_node->x=x;
				new_node->next=NULL;
				int team=0;
				for(int i=0;i<t;i++){
					node* init=record[i]->next;
					int flag=0;
					while(init!=NULL){
						if(init->x==x){
							team=i;
							flag=1;
							break;
						}
						else{
							init=init->next;
						}
					}
					if(flag==1){
						break;
					}
				}
				if(position[team]==NULL){
					new_node->next=end->next;
					end->next=new_node;
					end=new_node;
					position[team]=new_node;
				}
				else{
					if(position[team]==end){
						new_node->next=end->next;
						end->next=new_node;
						end=new_node;
						position[team]=new_node;
					}
					else{
						new_node->next=position[team]->next;
						position[team]->next=new_node;
						position[team]=new_node;
					}
				}
			}
			else if(strcmp(command,"STOP")==0){
				begin=begin->next;
				while(begin!=NULL){
					node* pre=begin;
					begin=begin->next;
					free(pre);
				}
				free(record);
				free(position);
				free(begin);
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
