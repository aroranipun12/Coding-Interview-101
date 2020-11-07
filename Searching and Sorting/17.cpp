#include<bits/stdc++.h>
using namespace std;

int countSetBits(int x){
     int count = 0;
    for(int i=0;i<32;i++){
          if(x & (1<<i))
                count++;
    }
 return count;
 }
bool mycompare(int a,int b){
     int count1 = countSetBits(a);
     int count2 = countSetBits(b);
        
     if(count1 <= count2)
        return false;
    return true;
}

void sortBySetBitCount(int arr[], int n){
    sort(arr,arr+n,mycompare);
}

int main( int argc , char ** argv )
{
    ios_base::sync_with_stdio(false) ; 
    cin.tie(NULL) ; 

   
        int n;
        cin>>n;
        int* arr = new int[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sortBySetBitCount(arr,n);
         for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    return 0;
}