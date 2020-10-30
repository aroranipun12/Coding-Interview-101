#include<bits/stdc++.h>
using namespace std;
//To solve this in O(n) use two arrays left and right whose ith element will store height of leftmax and rightmax respectively 
//and precompute these arrays before solving
/*Create two array left and right of size n. create a variable max_ = INT_MIN.
Run one loop from start to end. In each iteration update max_ as max_ = max(max_, arr[i]) and also assign left[i] = max_
Update max_ = INT_MIN.
Run another loop from end to start. In each iteration update max_ as max_ = max(max_, arr[i]) and also assign right[i] = max_*/

int maxi(int* arr,int left,int right,int element){
	int max_element = -1;
	for(int k=left;k<=right;k++){
		if(arr[k] > element){
			max_element = arr[k];
			element = arr[k];
		}
	}
return max_element;
}

int water(int* arr,int n){
	int ans = 0;
	for(int i=1;i<n-1;i++){
		int leftMax = maxi(arr,0,i-1,arr[i]);
		int rightMax = maxi(arr,i+1,n-1,arr[i]);
		
		if(leftMax == -1 || rightMax== -1)
			continue;
		ans += min(leftMax,rightMax) - arr[i];
	}
return ans;
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
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<water(arr,n)<<endl;
	}
	
	return 0;
}