#include<stdio.h>
#include<string.h>
int main(){
    int totalTime[8][8];
    int timeRank[8];
    int n;
    printf("请输入员工数量：");
    scanf("%d",&n);
    getchar();
    memset(totalTime,0,sizeof(totalTime));
    for(int i=0;i<n;i++){
        timeRank[i]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<7;j++){
          scanf("%d",&totalTime[i][j]);
        }      
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<7;j++){
    		totalTime[i][7]+=totalTime[i][j];
		}
	}
    for(int i=0;i<n;i++){
        for(int j=0;j<7;j++){
            if(totalTime[timeRank[j]][7]>totalTime[timeRank[j+1]][7]){
                int tmp=timeRank[j];
                timeRank[j]=timeRank[i];
                timeRank[i]=tmp;
            }
        }
    }
    system("cls");
    for(int i=0;i<n;i++){
        printf("employee%d ",i);
        for(int j=0;j<7;j++){
            printf("%d ",totalTime[timeRank[n-1-i]][j]);
        }
        printf("\n");
    }
    return 0;
}
