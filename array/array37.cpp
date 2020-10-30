//Moore's voting algo to find majority element(occuring more than n/2 times)
//assumes that one majority element if present (given)

#include<bits/stdc++.h>
using namespace std;

int moore(int* arr,int n){
	int element = 0;
	int count = 0;

	for(int i=0;i<n;i++){
		if(count == 0){
			element = arr[i];
		}
		if(element == arr[i])
			count++;
		else
			count--;
	}
return element;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ;
		int n,k;
		cin>>n;
		int* arr = new int[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<moore(arr,n)<<endl;
	
	return 0;
}