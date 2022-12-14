#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int grade;
    char name[20];
}student;
int cmpfuc(const student *a,const student *b){
    int n= (*a).grade-(*b).grade;
    n*=-1;
    int m=strcmp((*a).name,(*b).name);
    m*=-1;
    if(n==0){
        return m;
    }
    else {
        return n;
    }
}
int main(){
    int n;
    printf("请输入学生个数:");
    scanf("%d",&n);
    getchar();
    student record[n];
    for(int i;i<n;i++){
        printf("请输入学生姓名");
        scanf("%s",record[i].name);
        getchar();
        printf("请输入学生成绩");
        scanf("%d",&record[i].grade);
        getchar();
    }
    qsort(record,n,sizeof(student),cmpfuc);
    for(int i=0;i<n;i++){
        printf("%s  %d\n",record[i].name,record[i].grade);
    }
    return 0;
}