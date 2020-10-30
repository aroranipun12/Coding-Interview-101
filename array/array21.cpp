#include<bits/stdc++.h>
using namespace std;

bool solve(int* arr,int n){
	unordered_set<int> map;
	int curr_sum=0;
	
	for(int i=0;i<n;i++){
		curr_sum+=arr[i];
		if(curr_sum == 0)
			return true;
		if(map.find(curr_sum)!=map.end())
			return true;
		map.insert(curr_sum);
	}
return false;
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
		for(int i=0;i<n-1;i++)
			cin>>arr[i];
		cout<<solve(arr,n)<<endl;
	}
	return 0;
}