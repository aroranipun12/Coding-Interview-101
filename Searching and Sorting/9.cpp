#include<bits/stdc++.h>
using namespace std;

//this is when k = 1(difference b/w adj elements is 1)
int index_of(int* arr,int n,int target){
	int i=0;
	while(i<n){
		if(arr[i] == target)
			return i;
		else
			i += max(1,abs(arr[i] - target)); 
	}
return -1;//not found
}

//we can move to diff/k
int index_of_k(int* arr,int n,int k,int target){
int i=0;
	while(i<n){
		if(arr[i] == target)
			return i;
		else
			i += max(1,abs(arr[i] - target)/k);//diff/k 
	}
return -1;//not found
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 


	int n,x,k;
	cin>>n>>x>>k;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<endl;
	cout<<index_of_k(arr,n,k,x);
	
	return 0;
}