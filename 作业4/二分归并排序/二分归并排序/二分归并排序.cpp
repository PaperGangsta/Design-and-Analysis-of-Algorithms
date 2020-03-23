#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

const int n = 10;
const int maxn = 100;

void merge(int a[], int l1, int r1, int l2, int r2) {
	int i = l1, j = l2;
	int temp[maxn], index = 0;
	while (i <= r1 && j <=r2) {
		if (a[i] <= a[j]) {
			temp[index++] = a[i++];
		}
		else {
			temp[index++] = a[j++];
		}
	}
	while (i<=r1){
		temp[index++] = a[i++];
	}
	while (j<=r2){
		temp[index++] = a[j++];
	}
	for (i = 0; i < index; i++) {
		a[l1 + i] = temp[i];
	}
}

void mergeSort(int a[]) {
	for (int step = 2; step / 2 <= n; step *= 2) {
		for (int i = 1; i <= n; i += step) {
			int mid = i + step / 2 - 1;
			if (mid + 1 <= n){
				merge(a, i, mid, mid + 1, min(i + step - 1, n));
			}
		}
	}
}

int main() {
	int a[n] = { 1,2,3,4,5,6,7,8,9,10};
	//mergeSort(a);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}