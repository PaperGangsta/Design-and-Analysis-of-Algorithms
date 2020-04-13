#include<iostream>
#include<vector>
 
using namespace std;
 
int main() {
 
	int m, n;//m元钱，n项投资
	int i, j;//循环辅助变量
	int tmp_m,tmp_F=0;//tem_m代表给第i个项目投入的钱数  0<=tmp<=j;tmp_F代表一次循环中的钱数
	cin >> m >> n;
	vector<vector<int> > f(n, vector<int>(m + 1));//f[i][x], 0<i<=n,0<=x<=m；
	vector<vector<int> > F(n, vector<int>(m + 1));//F[i][x]，将x元钱投入到前i个项目上最大的收益
	
	for (i = 0; i < n; ++i) {
		f[i][0] = 0;//在第(i+1)个项目上投入0元，收益为0，注意i从0开始
	}
	for (i = 0; i < n; ++i) {
		for (j = 1; j < m + 1; ++j) {//j从1开始，也就是从f[0][1]开始
			cin >> f[i][j];
		}
	}
	//给F[0][0-m]赋值
	for (j = 0; j < m + 1; ++j) {
		F[0][j] = f[0][j];//第一个项目上投入0-m元钱的最大收益等于f[0][0-m]
	}
	for (i = 1; i < n; ++i) {//项目循环，从1开始,也就是从前2个项目开始算，因为第一个项目已经赋值
		for (j = 0; j < m + 1; ++j) {//钱数循环 从0开始
			for (tmp_m = 0; tmp_m <= j; ++tmp_m) {
				tmp_F = F[i - 1][j - tmp_m] + f[i][tmp_m];
				if (tmp_F > F[i][j])
					F[i][j] = tmp_F;
			}
		}
	}
	cout << "the max profit is : " << F[n - 1][m] << endl;
}
