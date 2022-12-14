#include<stdio.h>
int main(){
	const double pi=3.14;
	int m,n,t,c;
	scanf("%d%d%d%d",&m,&n,&t,&c);
	int ans1,ans2,ans3,ans4;
	float area =t*t*m*n;
	ans1=(m+n)*(t-c)*c+c*c+(t-c)*(t-c)*m*n;
	ans2=(m-1+n-1)*c*c+((m-1)*n+(n-1)*m)*(t-c)*c;
	ans3=(m-1)*(n-1)*(c*c-pi*(c*c>>2));
	ans4=(m-1)*(n-1)*pi*(c*c>>2);
	printf("Probability of covering 1 block=%.4f%%\n",ans1/area*100);
	printf("Probability of covering 2 block=%.4f%%\n",ans2/area*100);
	printf("Probability of covering 3 block=%.4f%%\n",ans3/area*100);
	printf("Probability of covering 4 block=%.4f%%\n",ans4/area*100);
	return 0;
}
