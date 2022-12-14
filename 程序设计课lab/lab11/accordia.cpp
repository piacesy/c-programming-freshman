#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
typedef struct{
	char num;
	char color;
}card;
int main(){
	card**cards=(card**)malloc(sizeof(card*)*60);
	for(int i=0;i<60;i++){
		cards[i]=(card*)malloc(sizeof(card)*100);
	}
	int left[52];
	int cards_size = 52;
	while(1){		
		for(int i=0;i<52;i++){
			left[i]=0;
		}
		char temp;
		temp=getchar();
		if(temp=='#'){
			break;
		}
		else{
			for(int i=0;i<52;i++){
				if(i==0){
					cards[i][0].num=temp;
					cards[i][0].color=getchar();
					left[i]++;
				}
				else{
					while(1){
						temp=getchar();
						if(temp==' '||temp=='\n'){
							continue;
						}
						else{
							break;
						}
					}
					cards[i][0].num=temp;
					cards[i][0].color=getchar();
					left[i]++;
				}
			}
			while(1){
				int flag=1;
				for(int i=1;i<cards_size;i++){
					if(i>=3){
						if(left[i]>0&&left[i-3]>0){						
							if(cards[i][left[i]-1].num==cards[i-3][left[i-3]-1].num||
								cards[i][left[i]-1].color==cards[i-3][left[i-3]-1].color){
								cards[i-3][left[i-3]]=cards[i][left[i]-1];
								left[i]--;
								if (left[i] == 0) {
									for (int j = i; j < cards_size - 1; j++) {
										cards[j] = cards[j + 1];
										left[j] = left[j + 1];
									}
									cards_size--;
								}
								left[i-3]++;
								flag = 0;
								int index = i-3;
								while (1) {
									int mark = 0;
									if (index >= 3) {
										if (left[index] > 0 && left[index - 3] > 0) {
											if (cards[index][left[index] - 1].num == cards[index - 3][left[index - 3] - 1].num ||
												cards[index][left[index] - 1].color == cards[index - 3][left[index - 3] - 1].color) {
												cards[index - 3][left[index - 3]] = cards[index][left[index] - 1];
												left[index]--;
												if (left[index] == 0) {
													for (int j = index; j < cards_size-1; j++) {
														cards[j] = cards[j + 1];
														left[j] = left[j + 1];
													}
													cards_size--;
												}
												left[index - 3]++;
												index -= 3;
												mark = 1;
												continue;
											}
										}
									}
									if (index >= 1) {
										if (left[index] > 0 && left[index - 1] > 0) {
											if (cards[index][left[index] - 1].num == cards[index - 1][left[index - 1] - 1].num ||
												cards[index][left[index] - 1].color == cards[index][left[index - 1] - 1].color) {
												cards[index - 1][left[index - 1]] = cards[index][left[index] - 1];
												left[index]--;
												if (left[index] == 0) {
													for (int j = index; j < cards_size-1; j++) {
														cards[j] = cards[j + 1];
														left[j] = left[j + 1];
													}
													cards_size--;
												}
												left[index - 1]++;
												index -= 1;
												mark = 1;
											}
										}
									}
									if (mark == 0) {
										break;
									}
								}
								break;
							}	
						}
					}
					if(i>=1){
						if(left[i]>0&&left[i-1]>0){
							if(cards[i][left[i]-1].num==cards[i-1][left[i-1]-1].num||
								cards[i][left[i]-1].color==cards[i-1][left[i-1]-1].color){
								cards[i-1][left[i-1]]=cards[i][left[i]-1];
								left[i]--;
								if (left[i] == 0) {
									for (int j = i; j < cards_size - 1; j++) {
										cards[j] = cards[j + 1];
										left[j] = left[j + 1];
									}
									cards_size--;
								}
								left[i-1]++;
								flag=0;
								int index = i - 1;
								while (1) {
									int mark = 0;
									if (index >= 3) {
										if (left[index] > 0 && left[index - 3] > 0) {
											if (cards[index][left[index] - 1].num == cards[index - 3][left[index - 3] - 1].num ||
												cards[index][left[index] - 1].color == cards[index - 3][left[index - 3] - 1].color) {
												cards[index - 3][left[index - 3]] = cards[index][left[index] - 1];
												left[index]--;
												if (left[index] == 0) {
													for (int j = index; j < cards_size-1; j++) {
														cards[j] = cards[j + 1];
														left[j] = left[j + 1];
													}
													cards_size--;
												}
												left[index - 3]++;
												index -= 3;
												mark = 1;
												continue;
											}
										}
									}
									if (index >= 1) {
										if (left[index] > 0 && left[index - 1] > 0) {
											if (cards[index][left[index] - 1].num == cards[index - 1][left[index - 1] - 1].num ||
												cards[index][left[index] - 1].color == cards[index][left[index - 1] - 1].color) {
												cards[index - 1][left[index - 1]] = cards[index][left[index] - 1];
												left[index]--;
												if (left[index] == 0) {
													for (int j = index; j < cards_size - 1; j++) {
														cards[j] = cards[j + 1];
														left[j] = left[j + 1];
													}
													cards_size--;
												}
												left[index - 1]++;
												index -= 1;
												mark = 1;
												continue;
											}
										}
									}
									if (mark == 0) {
										break;
									}
								}
								break;
							}
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
			printf("\n");
			getchar();
		}
	}
}
