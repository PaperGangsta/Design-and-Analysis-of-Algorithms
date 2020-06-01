#include<iostream>
using namespace std;

#define MAX 100
int color[MAX];//颜色
int graph[MAX][MAX] = { 0 };//无向联通图
int n, m;//顶点数和颜色数
int cnt = 0;//方案数

bool isDiffColor(int index) {//判断该顶点颜色是否与相邻顶点不同
	for (int i = 0; i < n; i++) {
		if (graph[index][i] == 1 && color[index] == color[i]) {
			return false;
		}
	}
	return true;
}

void backTracking(int index) {

	if (index == n) {//遍历完所有点，打印着色方案
		for (int i = 0; i < n; i++) {
			cout << color[i] << " ";
		}
		cnt++;
		cout << endl;
	}
	else {
		for (int j = 1; j <= m; j++) {//遍历可能颜色
			color[index] = j;
			if (isDiffColor(index)) { //符合条件，下一个点
				backTracking(index + 1);
			}
			color[index] = 0;//否则回溯
		}
	}
}

int main() {
	cout << "请输入顶点数n和颜色数m：" ;
	cin >> n >> m;
	cout << "请输入无向连通图：" << endl;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> graph[i][j];
	cout << "Answer:" << endl;
	backTracking(0);
	if (cnt == 0) {
		cout << "No" << endl;
	}
	else {
		cout << "可能的着色方案有：" << cnt << "种" << endl;
	}
}
