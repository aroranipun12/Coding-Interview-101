#include<bits/stdc++.h>
using namespace std;
//use long long instead of int
int maxProduct( int *arr, int n) {
	 int max_ending_here = 1;
	 int min_ending_here = 1;
	 int max_so_far = 1;

	int flag = 0;

	for(int i=0;i<n;i++){
		if(arr[i] > 0){
			max_ending_here = max_ending_here * arr[i];
			min_ending_here = min(1,min_ending_here*arr[i]);
			flag = 1;
		}
		else if(arr[i] == 0){
			max_ending_here = 1;
			min_ending_here = 1;
		}

		else{
			 int temp = max_ending_here;
			max_ending_here = max(min_ending_here * arr[i],1);//ye ab positive ban jayega
			min_ending_here = temp * arr[i]; 
		}

		if(max_ending_here > max_so_far)
			max_so_far = max_ending_here;
	}

return max_so_far;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	int n;
	cin>>n;
	 int * arr = new  int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}	
	cout<<maxProduct(arr,n);
	return 0;
}