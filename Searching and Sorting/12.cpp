#include<bits/stdc++.h>
using namespace std;

int max_loot(int* arr,int n){
    int* dp = new int[n];
    //dp[i] stores max loot till ith house
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1],arr[i] + dp[i-2]);
    }
int ans = dp[n-1];
delete [] dp;
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
        cout<<max_loot(arr,n)<<endl;  
    }
    
    return 0;
}