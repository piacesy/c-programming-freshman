#include<stdio.h>
#include<malloc.h>
struct word{
	char c;
	word* next;
};
typedef struct word word;
int main(){
	word* begin=NULL;
	word* end=NULL;
	word* now=NULL;
	char temp;
	char record[3];
	while(1){
		int flag=0;
		while((temp=getchar())!='\n'){
			if(flag==0&&(temp=='['||temp==']')){
				continue;
			}
			if(flag<3){
				record[flag]=temp;
				flag++;
				if(flag==1){
					word* new_word=(word*)malloc(sizeof(word));
					(*new_word).c=temp;
					(*new_word).next=NULL;
					begin=end=now=new_word;
					continue;
				}
				else if(flag==3){
				if(record[0]=='E'&&record[1]=='O'&&record[2]=='F'){
					goto mark;
					}
				}
			}

			if(temp=='['){
				now=NULL;
			}
			else if(temp==']'){
				now=end;
			}
			else{
				if(now==end){
					word* new_word=(word*)malloc(sizeof(word));
					(*new_word).c=temp;
					(*new_word).next=NULL;
					(*end).next=new_word;
					end=now=new_word;
				}
				else if(now==NULL){
					word* new_word=(word*)malloc(sizeof(word));
					(*new_word).c=temp;
					(*new_word).next=begin;
					now=new_word;
					begin=new_word;				
				}
				else{
					word* new_word=(word*)malloc(sizeof(word));
					(*new_word).c=temp;
					(*new_word).next=(*now).next;
					(*now).next=new_word;
				}
			}
		}
		while(begin!=NULL){
			printf("%c",(*begin).c);
			begin=(*begin).next;
		}
		printf("\n");
		begin=end=now=NULL;
	}
	mark:
	return 0;
}
