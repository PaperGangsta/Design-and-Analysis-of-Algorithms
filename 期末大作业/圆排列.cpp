#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,a[1010],an[1010];
double r[1010],x[1010],ans=101010100;
double cal(double x,double y)
{
	return sqrt((x+y)*(x+y)-fabs(x-y)*fabs(x-y));
}
int main()
{
	printf("������Բ�ĸ���");
	scanf("%d",&n);
	printf("��ֱ�����Բ�뾶�Ĵ�С"); 
	for(int i=1;i<=n;i++) scanf("%lf",&r[i]);
	for(int i=1;i<=n;i++) a[i]=i;
	do  
    {  
    	for(int i=1;i<=n;i++) x[i]=0;
        for(int i=2;i<=n;i++)
        {
        	for(int j=1;j<i;j++){
        		x[i]=max(x[i],x[i-1]+cal(r[a[i]],r[a[j]]));
			}
		}
		if(x[n]+r[a[1]]+r[a[n]]<ans){
			ans=x[n]+r[a[1]]+r[a[n]];
			for(int i=1;i<=n;i++) an[i]=a[i];
		}
    }while(next_permutation(a+1,a+1+n)); 
	printf("��С���г���:%.3lf\n",ans);
	printf("����Ϊ:\n");
	for(int i=1;i<=n;i++) printf("%d��Բ ",an[i]);
	printf("\n"); 
}
