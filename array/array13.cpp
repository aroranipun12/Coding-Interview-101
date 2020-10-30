#include<bits/stdc++.h>
using namespace std;

int kadane(int* arr,int n){
	int max_ending_here=0;
	int max_so_far=INT_MIN;

	for(int i=0;i<n;i++){
		max_ending_here += arr[i];
		if(max_so_far < max_ending_here)
			max_so_far=max_ending_here;
		if(max_ending_here < 0)
			max_ending_here = 0;
	}
return max_so_far;
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
		cout<<kadane(arr,n)<<endl;
	}
	return 0;
}