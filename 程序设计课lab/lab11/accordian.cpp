#include<stdio.h>
#include<malloc.h>
typedef struct{
	char num;
	char color;
}card;
int main(){
	card**cards=(card**)malloc(sizeof(card*)*100);
	int cards_size=0;
	while(1){
		char temp;
		temp=getchar();
		if(temp=='#'){
			break;
		}
		else{
			cards[cards_size]=(card*)malloc(sizeof(card)*100);
			cards_size++;
		}
		for(int i=0;i<26;i++){
			if(i==0){
				cards[cards_size-1][i].num=temp;
				cards[cards_size-1][i].color=getchar();
			}
			else{
				while((temp=getchar())==' ');
				cards[cards_size-1][i].num=temp;
				cards[cards_size-1][i].color=getchar();
			}
			getchar();
		}
	}
	int* left=(int*)malloc(sizeof(int)*cards_size);
	for(int i=0;i<cards_size;i++){
		left[i]=26;
	}
	while(1){
		int flag=1;
		for(int i=1;i<cards_size;i++){
			if(i>=3){
				if(left[i]>0&&left[i-3]>0&&
				(cards[i][left[i]-1].num==cards[i-3][left[i-3]-1].num||
				cards[i][left[i]-1].color==cards[i-3][left[i-3]-1].color)){
					cards[i-3][left[i-3]]=cards[i][left[i]-1];
					left[i]--;
					left[i-3]++;
					flag=0;
					break;
				}
			}
			if(i>=1){
				if(left[i]>0&&left[i-1]>0&&
				(cards[i][left[i]-1].num==cards[i-1][left[i-1]-1].num||
				cards[i][left[i]-1].color==cards[i-1][left[i-1]-1].color)){
					cards[i-1][left[i-1]]=cards[i][left[i]-1];
					left[i]--;
					left[i-1]++;
					flag=0;
					break;
				}
			}
			
		}
		if(flag==1){
			break;
		}
	}
	int left_pile=0;
	for(int i=0;i<cards_size;i++){
		if(left[i]>0){
			left_pile++;
		}
	}
	printf("%d piles remaining:",left_pile);
	for(int i=0;i<cards_size;i++){
		if(left[i]>0){
			printf("%d ",left[i]);
		}
	}
	return 0;
}
