#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int  test(){
    return rand();
}
int main(){
	srand((unsigned)time(NULL));
	test();
	return 0;
}
