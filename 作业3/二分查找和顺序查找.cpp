#include<iostream>
#include<cstdio>
using namespace std;

const int lenth = 999;

int binary_search(int a[],int left,int right,int num){
	int mid;
	while(left<=right){
		mid = (left+right)/2;
		if(a[mid]==num){
			return mid;
		}
		else if(a[mid]>num){
			right = mid - 1;
		}
		else{
			left = mid + 1;		
		}
	}
	return -1;
}

int arr_search(int a[],int len,int num){
	for(int i = 0;i<len;i++){
		if (a[i] == num)
		{
			return i;
		}
	}
	return -1;
}

int main(){
	int arr[lenth];
	int num,len,end;
	scanf("%d %d",&len,&num);
	for(int i = 0;i<len;i++){
		scanf("%d",&arr[i]);
	}
//	for(int i = 0;i<len;i++){
//		printf("%d ",arr[i]);
//	}

	end = binary_search(arr,0,len-1,num);
	printf("%d\n",end);
	end = arr_search(arr,len,num);
	printf("%d\n",end);

}
