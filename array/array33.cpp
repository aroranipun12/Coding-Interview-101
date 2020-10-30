#include<bits/stdc++.h>
using namespace std;
//pehle count nikala ki kitne total numbers h jo saath m aane chahiye
//then sliding window use krke har count length ke subarray m invalid numbers count kre
//jo bhi min number of invalid count vala subarray hoga vhi ans hoga
int check(int* arr,int left ,int right,int element){
	int invalid_numbers = 0;
	for(int i=left;i<=right;i++){
		if(arr[i]>element)
			invalid_numbers++;
	}
return invalid_numbers;
}

int minSwaps(int* arr,int size ,int element,int count){
	int left = 0;
	int right = count;
	int ans = INT_MAX;
	for(int i=left;i<=size-count;i++){
		int number = check(arr,left,left+count-1,element);
		ans = min(ans,number);
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
		int count=0;
		for(int i=0;i<n;i++){
			if(arr[i]<=k)
				count++;
		}
		cout<<minSwaps(arr,n,k,count)<<endl;
	}
	
	return 0;
}