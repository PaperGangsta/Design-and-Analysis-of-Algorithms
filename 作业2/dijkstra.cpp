#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int INF = 0xffffff;
const int MAXV = 1000;

int m,s,n,G[MAXV][MAXV];//n为顶点数，G为图,m为边数,s为起点
int d[MAXV];//起点到各个点的最短路径长度
bool vis[MAXV] = {false};//初始化访问数组

void Dijkstra(int s){
	fill(d,d+MAXV,INF);//初始化d数组为INF
	d[s] = 0;
	for(int i=0;i<n;i++){
		int u = -1,MIN = INF;
		for(int j = 0;j<n;j++){
			if(vis[j] == false&&d[j]<MIN){
				u = j;
				MIN = d[j];
			}
		}
		//如果没找到说明顶点和起点s不连通
		if(u==-1){
			return ;
		}
		vis[u] = true;
		for (int v = 0;v<n;v++){
			/*如果点可达并且改点没有被访问过并且uv点距离+起点到u点距离<起点到v点距离,更新长度*/
			if(vis[v] == false && G[u][v]!=INF && d[u] + G[u][v] < d[v]){
				d[v] = d[u] + G[u][v];
			}
		}
	}
}


int main(){
	int x,y,len;
	scanf("%d %d %d",&n,&m,&s);
	fill(G[0],G[0]+MAXV*MAXV,INF);
	for(int i = 0;i<m;i++){
		scanf("%d %d %d",&x,&y,&len);
		G[x][y] = len;
	}
	Dijkstra(s);
	for(int i = 0;i<n;i++){
		printf("%d ",d[i]);
	}
	return 0;
}
