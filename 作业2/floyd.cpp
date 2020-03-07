#include <iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int INF = 0xffffff;//不可达的距离
const int MAXV = 200;//最大顶点数

int n,m;//n为顶点数,m为边数

int dis[MAXV][MAXV];//dis[i][j]表示顶点i到j的距离

void Floyd(){
	for(int k = 0;k<n;k++){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j] = dis[i][k]+dis[k][j];
				}
			}
		}
	}
}

int main(){

	int x,y,len;
	fill(dis[0],dis[0]+MAXV*MAXV,INF);
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; i++){
		dis[i][i] = 0;
	}
	for(int i = 0;i<m;i++){
		scanf("%d %d %d",&x,&y,&len);
		dis[x][y] = len;
	}
	Floyd();
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			printf("%d ",dis[i][j]);
		}
		printf("\n");
	}
	return 0;
}
