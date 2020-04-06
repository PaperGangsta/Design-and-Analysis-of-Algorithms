#include<iostream>
#include<algorithm>
using namespace std;

int r = 5;
int k = 6;//第六小 


int select(int arr[],int num,int left,int right,int k){

        int group = num/5;

        int M[group];

        for (int i = 0; i < group; i++) {
          	sort(arr, left + right * i, (left + right * i + (num > right * i + right ? right : num - i * right)));
            M[i] = arr[low + right * i + (num > right * i + right ? right : num - i * right) / 2];
        }
    
        int mid = M.length <= 2 ? M[0] : select(M, 0, M.length - 1, M.length / 2);
        int S1[num] ;//小于mid的数
        int S2[num] ;//大于mid的数
        int numS1, numS2, numS3;
        numS1 = numS2 = numS3 = 0;
        //对数进行分组
        for (int i = left; i <= high; i++) {
            if (arr[i] < mid) {
                S1[numS1++] = arr[i];
            } else if (arr[i] == mid) {
                numS3++;
            } else {
                S2[numS2++] = arr[i];
            }
        }
        if (numS1 >= k) {
            //小于mid的数的数量对大于等于k
            return select(S1, 0, numS1 - 1, k);
        } else if (numS1 + numS3 >= k) {
            return mid;
        } else {
            //小于等于mid的数的数量小于k
            return select(S2, 0, numS2 - 1, k - numS1 - numS3);
        }

}

int main(){
	int arr[15] = {8,2,3,5,7,6,11,14,1,9,13,10,4,12,15};
	printf("%d",select(arr,15,0,14,6))
}


