#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
struct A{
    int s;//��ʼʱ��
    int e;//����ʱ��
}Act[200];
bool cmp(struct A a,struct A b){
    return a.e<b.e;
}
void greedy(struct A* a,int n,int ap[]){
    sort(a+1,a+1+n,cmp);
    ap[1]=1;
    int j=1;//��¼��������ƻ��Ļ�����
    int count=1;//��¼�м��������ƻ�
    for(int i=2;i<=n;i++){
        if(a[i].s>=a[j].e){//����ǰ�������������»���ݣ�������ƻ�
            ap[++count]=i;
            j=i;
        }
    }
    for(int i=1;i<=count;i++){
        printf("%d ",ap[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    Act[1].s=1;Act[1].e=2;
    Act[2].s=2;Act[2].e=3;
    Act[3].s=2;Act[3].e=4;
    Act[4].s=4;Act[4].e=6;
    Act[5].s=8;Act[5].e=12;
    Act[6].s=6;Act[6].e=12;
    int ap[200]={0};
    greedy(Act,6,ap);
    return 0;
}
