#include<bits/stdc++.h>
using namespace std;
//kth max element


void heapify(int* arr,int n,int i){

	int leftChild = 2*i + 1;
	int rightChild = 2*i + 2;
	int largestIndex = i;
	
	if(arr[leftChild]>arr[i] && leftChild<n)
		largestIndex = leftChild;
	if(arr[rightChild]>arr[largestIndex] && rightChild<n)
		largestIndex = rightChild;

	if(largestIndex != i){
		//swap largest and i(root)
		int temp = arr[i];
		arr[i] = arr[largestIndex];
		arr[largestIndex] = temp;
		heapify(arr,n,largestIndex);
	}	
}

void deleteRoot(int* arr,int& n){
	int element = arr[n-1];
	arr[0] = element;
	n=n-1;
	heapify(arr,n,0);
}

void buildMaxHeap(int* arr,int size){
	int startingIndex = (size/2)-1;

	//only heapifying non-leaf elements heapifies the whole array
	for(int i=startingIndex;i>=0;i--){
		heapify(arr,size,i);
	}
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
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int k;
		cin>>k;
		buildMaxHeap(arr,n);
		/*for(int i=0;i<k-1;i++)
			deleteRoot(arr,n);*/
		//cout<<arr[0];
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	return 0;
}