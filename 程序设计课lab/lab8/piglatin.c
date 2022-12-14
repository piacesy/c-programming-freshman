#include<stdio.h>
#include<string.h>
int isab(char c){
    if((c>=65&&c<=90)||(c>=97&&c<=122)){
        return 1;
    }
    else{
        return 0;
    }
    return 0;
}
int isvowef(char c){
    if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U'){
        return 1;
    }
    else{
        return 0;
    }
    return 0;
}
int main(){
    char word[100][100][15];
    char judge;
    for(int i=0;;i++){
        char tmp[500];
        gets(tmp);
        int wordNum=0;
        int wordLen=0;
        for(int j=0;j<strlen(tmp);j++){
            if(isab(tmp[j])){
                word[i][wordNum][wordLen]=tmp[j];
                wordLen++;
            }
            else{
                wordNum++;
                wordLen=0;
                while(j+1<strlen(tmp)&&isab(tmp[j+1])==0){
                    j++;
                }
            }
        }
        printf("do you what to input again:(y/n):");
        scanf("%c",&judge); 
        getchar();
        if(judge=='y'){
            continue;
        }
        else{
            break;
        }

    }
    for(int i=0;word[i][0][0]!='\0';i++){
        for(int j=0;word[i][j][0]!='\0';j++){
            if(isvowef(word[i][j][0])){
                int len=strlen(word[i][j]);
                word[i][j][len]='a';
                word[i][j][len+1]='y';
                word[i][j][len+2]='\0';
            }
            else{
                int len =strlen(word[i][j]);
                char c=word[i][j][0];
                for(int y=0;y<len-1;y++){
                    word[i][j][y]=word[i][j][y+1];
                }
                word[i][j][len-1]=c;
                word[i][j][len]='a';
                word[i][j][len+1]='y';
                word[i][j][len+2]='\0';
            }
        }
        for(int j=0;word[i][j][0]!='\0';j++){
            printf("%s ",word[i][j]);
        }
        printf("\n");
    }
    return 0;
}