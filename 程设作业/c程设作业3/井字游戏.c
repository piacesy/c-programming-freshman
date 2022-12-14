#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void print_map(int map[][3]){
    printf("-------------\n");
    for(int i=0;i<3;i++){
        printf("|");
        for(int j=0;j<3;j++){
            if(map[i][j]==1){
                printf(" X |");
            }
            else if(map[i][j]==0){
                printf("   |");
            }
            else{
                printf(" O |");
            }
        }
        printf("\n");
        printf("-------------\n");
    }
}
int  check(int map[][3],int n){
    for(int i=0;i<3;i++){
        int flag=1;
        for(int j=0;j<3;j++){
            if(map[i][j]!=n){
                flag=0;
                break;
            }
        }
        if(flag==1){
            return n;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int flag = 1;
        for (int j = 0; j < 3; j++)
        {
            if (map[j][i] != n)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            return n;
        }
    }
    if(map[0][0]==n&&map[1][1]==n&&map[2][2]==n){
        return n;
    }
    if(map[2][0]==n&&map[1][1]==n&&map[0][2]==n){
        return n;
    }
    return 0;
}
int main(){
    int map[3][3];
    memset(map,0,sizeof(map));
    int player =1;
    int cont=0;
    while(cont==0){
        print_map(map);
        if(player==1){
            int x,y;
            printf("Enter a row for player 1:");
            scanf("%d",&x);
            getchar();
            printf("Enter a column for player 1:");
            scanf("%d",&y);
            getchar();
            map[x-1][y-1]=1;
            cont=check(map,1);
            if(cont==1){
                system("cls");
                print_map(map);
                printf("player1 win\n");
                system("pause");
            }
            player=2;
        }
        else{
            int x,y;
            printf("Enter a row for player 2:");
            scanf("%d",&x);
            getchar();
            printf("Enter a column for player 2:");
            scanf("%d",&y);
            getchar();
            map[x-1][y-1]=2;
            cont=check(map,2);
            if(cont==2){
                system("cls");
                print_map(map);
                printf("player2 win\n");
                system("pause");
            }
            player=1;
        }
        system("cls");
    }
    return 0;
}