#include<bits/stdc++.h>
using namespace std;
//using sorting 
//O(nlogn)
int lcs(int* arr,int n){
	sort(arr,arr+n);
	int count = 1;
	int ans = 1;
	for(int i=1;i<n;i++){
		if(arr[i] == arr[i-1])
			continue;
		if(arr[i] == arr[i-1] + 1)
			count++;
		else
			count = 1;
		ans = max(ans,count);
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
		cout<<lcs(arr,n)<<endl;
	}

	
	return 0;
}