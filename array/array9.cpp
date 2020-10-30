#include <bits/stdc++.h>
using namespace std;

void swap(int& a,int& b){
	int temp = a;
	a=b;
	b=temp;
return ;
}

int getMinDiff(int arr[], int n, int k) {
    if(n==1)
        return 0;
    sort(arr,arr+n);
    int minimum = arr[0]+k;
    int maximum = arr[n-1]-k;
    
    if(minimum > maximum){
    	swap(minimum,maximum);
    }
   
    for(int i=1;i<n-1;i++){
    	int curr = arr[i];
    	int curr_diff;
    	int ans1 = INT_MAX;
    	int ans2 = INT_MAX;
    	if(curr-k >= minimum || curr+k <= maximum){
    		continue;
    	}
    	if(curr-k < minimum){
    		curr_diff = maximum - (curr-k);
    		ans1 = curr_diff;
    	}
    	if(curr+k > maximum){
    		curr_diff = curr+k - minimum;
    		ans2 = curr_diff;
    	}
    	if(ans1 < ans2)
    		minimum = curr-k;
    	else
    		maximum = curr+k;
    }

return maximum - minimum;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
		int n;
		cin>>n;
		int* arr = new int[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int k;
		cin>>k;
	
	cout<<getMinDiff(arr,n,k);
	return 0;
}