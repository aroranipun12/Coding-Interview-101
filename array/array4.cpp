#include<bits/stdc++.h>
using namespace std;

void solve(int* arr,int n){
	int count0=0;
	int count1=0;
	//count
	for(int i=0;i<n;i++){
		if(arr[i]==0)
			count0++;
		if(arr[i]==1)
			count1++;
	}
	int count2 = n-(count0+count1);
	
	for(int i=0;i<n;i++){
		if(count0){
			cout<<0<<" ";
			count0--;
		}
		else if(count1){
			cout<<1<<" ";
			count1--;
		}
		else 
			cout<<2<<" ";

	}
}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ;
	int t;
	cin>>t;
	while(t--){
		//input
		int size;
		cin>>size;
		int* arr = new int[size];
		for(int i=0;i<size;i++){
			cin>>arr[i];
		}
		solve(arr,size);
		cout<<endl;
	}
}