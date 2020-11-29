#include<bits/stdc++.h>
using namespace std;
long long wind1(long long wind[], long long n){
long long temp[n]; 
long long x; 
long long min = INT_MAX;    
for(int i=0;i<n;i++)    
{
    
 x = (wind[i]-i);
 if(x%n==0)    
 {
     temp[i]=x*n+i;
     
     
 }   
 else{
     
     temp[i]=(x+1)*n+i;
     
     
 }   
    
}    
    
for(int j=0;j<n;j++){
 if(temp[j]<min)   
 {
     
     min = j;
     
     
 }  
    
  
    
}    
    
return (min+1);      
    
}
int main()
{
    long long n;
    cin>>n;
    long long wind[n];
    for(int i=0;i<n;i++){
        
        cin>>wind[i];
        
    }
    
    
    long long gh = wind1( wind, n);
	cout<<gh;
    return 0;
}