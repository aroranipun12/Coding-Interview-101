#include<bits/stdc++.h>
using namespace std;

void multiply(int x,int* res,int &res_size){
	int carry = 0;  // Initialize carry 
  
    // One by one multiply n with individual digits of res[] 
    for (int i=0; i<res_size; i++) 
    { 
        int prod = res[i] * x + carry; 
  
        // Store last digit of 'prod' in res[]   
        res[i] = prod % 10;   
  
        // Put rest in carry 
        carry  = prod/10;     
    } 
  
    // Put carry in res and increase result size 
    while (carry) 
    { 
        res[res_size] = carry%10; 
        carry = carry/10; 
        res_size++; 
    } 
}

void fact(int n){

	int* res = new int[9999999];
	res[0] = 1;//init
	int res_size = 1;//pointer at the end
	for(int x=2;x<=n;x++){
		multiply(x,res,res_size);
	}
	for(int x=res_size-1;x>=0;x--){
		cout<<res[x];
	}
	cout<<endl;
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
		fact(n);
	}
	return 0;
}