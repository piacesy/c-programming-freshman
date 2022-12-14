#include<stdio.h>
int map[8][8];
int *max;
int flag1,flag2;
int record[8];
void dfs(int pos,int grade){
    if(pos==8){
        if(*max<grade){
            *max=grade;
            return ;
        }
    }
    for(int i=0;i<8;i++){
        if(record[i]==1){
        	if(pos==i){
        		if(flag1==0)
        			continue;
        		else{
        			flag1=0;
        			record[i]=0;
        			dfs(pos+1,grade+map[pos][i]);
        			flag1=1;
        			record[i]=1;
				}
			}
			else if(pos+i==7){
				if(flag2==0){
					continue;
				}
				else{
					flag2=0;
					record[i]=0;
					dfs(pos+1,grade+map[pos][i]);
					flag2=1;
					record[i]=1;
				}
			}
			else{
				record[i]=0;
	            dfs(pos+1,grade+map[pos][i]);
	            record[i]=1;
			}

        }
    }
}
int main(){
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        for(int j=0;j<8;j++){
            for(int y=0;y<8;y++){
                scanf("%d",&map[j][y]);
            }
        }
        for(int j=0;j<8;j++){
            record[8]=1;
        }
        flag1=flag2=1;
        dfs(0,0);
        printf("%d",*max);
    }
}
