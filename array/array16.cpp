#include<bits/stdc++.h>
using namespace std;

//now left half goes from left to mid-1 and right goes from mid to right(due to mid+1 argument)
int merge(int* arr,int mid,int left,int right,int* temp){
	int i,j,k;
	int inv_count = 0;

	 i = left;//start of left sub array
	 j = mid;//start of right sub array
	 k = left;//to mark in temp array

	while(i <= mid-1 && j <= right){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];

			inv_count += (mid-i);//i ke right m sab ke saath pair hoga including ith element
		}
	}

	while(i <= mid-1){
		temp[k++] = arr[i++];
	}

	while(j <= right){
		temp[k++] = arr[j++];
	}

	for(int p = left;p<=right;p++){
		arr[p] = temp[p];
	}
return inv_count;
}

int merge_sort(int* arr,int left,int right,int* temp){
	int mid;
	int inv_count=0;
	if(right > left){
		mid = (left+right)/2;
		inv_count += merge_sort(arr,left,mid,temp);
		inv_count += merge_sort(arr,mid+1,right,temp);

		inv_count += merge(arr,mid+1,left,right,temp);
	}
return inv_count;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int* arr = new int[n];
		int* temp = new int[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<merge_sort(arr,0,n-1,temp);
	}	
	return 0;
}