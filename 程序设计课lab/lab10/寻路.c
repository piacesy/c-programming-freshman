#include<stdio.h>
#include<malloc.h>
int** record;
int* max;
void dfs(int* max, int len, int pos, int n);
int main() {
	int m, n;
	max = (int*)malloc(sizeof(int));
	for(;;){
		scanf("%d%d", &n, &m);
		getchar();
		if(n==0&&m==0){
			break;
		}
		record = (int**)malloc(n * sizeof(int*));
		for (int i = 0; i < n; i++) {
			record[i] = (int*)malloc(n * sizeof(int));
		}
		*max=0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				record[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i++) {
			int temp1;
			int temp2;
			scanf("%d%d", &temp1, &temp2);
			getchar();
			record[temp1][temp2] = record[temp2][temp1] = 1;
		}
		dfs(max, 0, 0, n);
		printf("%d", *max);
	}
	return 0;
}
void dfs(int* max, int len, int pos, int n) {
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (record[pos][i] == 1) {
			flag = 1;
			record[pos][i] = record[i][pos] = 0;
			dfs(max, len + 1, i, n);
			record[pos][i] = record[i][pos] = 1;
		}
	}
	if (flag == 0) {
		if (len > *max) {
			*max = len;
		}
	}
}
