#include<bits/stdc++.h>
using namespace std;

int countSubArrays(int* arr,int n){
    unordered_map<int,vector<int>> umap;//stores sum -> vector of indexes
    int curr_sum = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        curr_sum+=arr[i];
        
        //subarray from 0 to i
        if(curr_sum == 0){
            count++;
        }
        //subarray from all elements already in the vector (umap[curr_sum]+1) to i
        if(umap.find(curr_sum) != umap.end()){
            count += umap[curr_sum].size(); 
        }
        //insert
        umap[curr_sum].push_back(i); 
    }
return count;
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
    cout<<countSubArrays(arr,n)<<endl;
    }
    
    return 0;
}