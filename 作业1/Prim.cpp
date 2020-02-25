#include<cstdio>
#include<iostream>

#define INFINITY 0x3f3f3f3f

using namespace std;

struct MGraph{
	int arc[100][100];
	int numVertexes;
}G;

void MiniSpanTree_Prim(MGraph G){
	printf("Prim算法的建树过程为:\n");
	int min,i,j,k;
	int adjvex[G.numVertexes];
	int lowcost[G.numVertexes];
	lowcost[0] = 0;
	adjvex[0] = 0;
	for(i = 1;i<G.numVertexes;i++){
		lowcost[i] = G.arc[0][i];
		adjvex[i] = 0;
	}
	for(i = 1;i<G.numVertexes;i++){
		min = INFINITY;
		j = 1;k = 0;
		while(j<G.numVertexes){
			if(lowcost[j]!=0&&lowcost[j]<min){
				min = lowcost[j];
				k = j;
			}
			j++;
		}
		printf("(%d,%d)\n",adjvex[k]+1,k+1);
		lowcost[k] = 0;
		for(j = 1;j<G.numVertexes;j++){
			if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j]){
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}

void init(MGraph *G,int vertex,int side){
	int i ,j,temp;
	int vertex1,vertex2,distance;
	i = j = 0;
	G->numVertexes = vertex;
	for(i = 0;i<G->numVertexes;i++){
		for(j = 0;j<G->numVertexes;j++){
			if(i==j){
				G->arc[i][j] = 0;
			}
			else{
				G->arc[j][i] = INFINITY;
			}
		}
	}
	printf("请输入顶点a到顶点b以及距离c 如: 1 2 3 \n");
	printf("表示 顶点 1 到 顶点 2 有一条距离为 3 的边\n");
	for(i = 0;i<side;i++){
		scanf("%d %d %d",&vertex1,&vertex2,&distance);
		G->arc[vertex1-1][vertex2-1] = G->arc[vertex2-1][vertex1-1] = distance;
	}
	
	printf("\n您输入的矩阵为:\n");
	for(i = 0;i<G->numVertexes;i++){
		for(j = 0;j<G->numVertexes;j++){
			if(G->arc[i][j]==INFINITY){
				printf("∞ ");
			}
			else{
				printf("%d ",G->arc[i][j]);
			}
		}
		printf("\t\n");
	}
	printf("\n");
}
int main(){
	int vertex,side;
	printf("请分别输入您定义的顶点数M与边数N\n");
	scanf("%d %d",&vertex,&side);
	MGraph map;
	MGraph *m = &map;
	init(m,vertex,side);

	MiniSpanTree_Prim(map);
}
