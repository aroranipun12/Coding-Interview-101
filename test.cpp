#include<bits/stdc++.h>
using namespace std;
//counts trailing 0s in n!
int countTralingZeroes(int n){
    int count = 0;
    for(int i=5;n/i>=1;i*=5){
        count += floor(n/i);
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
        cout<<countTralingZeroes(n)<<endl;
    }   
    return 0;
}