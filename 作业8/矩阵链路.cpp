#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n;
int* data;
int** m;
int** s;
// init
void getData() {
    n = 5;
    data = new int[n+1]();
    data[0]=30; data[1]=35;data[2]=15;data[3]=5;data[4]=10;data[5]=20;
    m = new int*[n+1];
    s = new int*[n+1];
    printf("n=%d\n",n);
    printf("<");
    for (int i = 0; i <= n; i++) {
        if (i==n) {
            printf("%d>",data[i]);
        }
        else
            printf("%d,",data[i]);
        m[i] = new int[n+1]();
        s[i] = new int[n+1]();
    }
}
// 按照 r 来打印数据
void printR() {
    for (int k = 1; k <= n; k++) {
        printf("r=%d\n",k);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < n+1; j++) {
                if ((j-i+1) == k) {
                    printf("m[%d,%d]=%d\n",i,j,m[i][j]);
                }
            }
        }
    }
    for (int k = 2; k <= n; k++) {
        cout << "r=" << k;
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < n+1; j++) {
                if ((j-i+1) == k) {
                    printf("s[%d,%d]=%d\n",i,j,s[i][j]);
                }
            }
        }
    }
}

void matrixChain(int* data,int n) { //迭代
    int i,j,k,t;
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < n+1; j++) {
            s[i][j] = i;
        }
    }
    printR();
    for(int r = 2; r <= n; r++) {       //r为当前问题规模，进行子问题划分
        for(i = 1; i <= (n-r+1); i++) { //i的起点不断变化，各种r长
            j = i + r -1;               //不同终点
            m[i][j] = m[i+1][j] + data[i-1]*data[i]*data[j];  //划分为Ai(Ai+1....Aj)
            s[i][j] = i;                                      //标记元素 = 坐标 记录分割位置
            for(k = i + 1; k <= j - 1; k++) {                 //不同的划分位置
                t = m[i][k] + m[k+1][j] + data[i-1]*data[k]*data[j]; //前面的+后面的+相乘数据
                if (t < m[i][j]) {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

int recurMatrixChain(int* data,int i, int j) {//递归
    if (i == j) { // 递归到最小单元
        m[i][j] = 0;
        s[i][j] = i;
        return m[i][j];
    }
    m[i][j] = 1 << 30;  //无穷大
    s[i][j] = i;        //在i分割
    for (int k=i; k<=j-1;k++) { // 从i到j-1开始递归，求最小值，然后加上整体数据
        int q = recurMatrixChain(data, i, k) + recurMatrixChain(data, k+1, j) + data[i-1]*data[k]*data[j]; //data[0]*data[k]*data[j]
        if (q < m[i][j]) {
            m[i][j] = q;
            s[i][j] = k;
        }
    }
    return m[i][j];
}
// 打印过程
void printProcess(int start, int end) {
    if (start == end)
        return;
    printProcess(start, s[start][end]);
    printProcess(s[start][end]+1, end);
    printf("(A%d*A%d)",start,end);
    if (start != 1 || end !=n) {
        printf("->");
    }
}
// 打印序列
void printOrder(int start, int end) {
    if (start == end) {
       // printf("A");
        cout << "A"<< end;
        return;
    }
    printf("(");
    printOrder(start, s[start][end]);
    printf("*");
    printOrder(s[start][end]+1, end);
    printf(")");
}
void printResult() {
    cout << endl << "result : " << m[1][n] << endl;
    printOrder(1, n);
    cout << endl;
    printProcess(1, n);
}
int main() {
    getData();
    //matrixChain(data, n);
    recurMatrixChain(data, 1, n);
    printR();
    printResult();
    getchar();
    return 0;
}
