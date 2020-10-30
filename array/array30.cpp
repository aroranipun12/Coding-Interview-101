//sort krke sliding window of k elements(k is number of students)
//use long long for constraints

#include<bits/stdc++.h>
using namespace std;

int min_diff(int* arr,int n,int k){
	sort(arr,arr+n);
	int ans = INT_MAX;
	for(int i=k-1;i<n;i++){
		ans = min(ans,arr[i] - arr[i-(k-1)]);
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
		int k;
		cin>>k;
		cout<<min_diff(arr,n,k)<<endl;
	}
	
	return 0;
}