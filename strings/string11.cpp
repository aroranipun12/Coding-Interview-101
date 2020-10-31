#include<bits/stdc++.h>
using namespace std;

void all_permutations(string str,int l,int r){

	if(l==r)
		cout<<str<<" ";

	else{
		for(int i=l;i<=r;i++){
			swap(str[l],str[i]);
			all_permutations(str,l+1,r);
		    swap(str[l],str[i]);
		}
	}

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 

	int t;
	cin>>t;

	while(t--){
		string str;
		cin>>str;
		all_permutations(str,0,str.size()-1);
		cout<<endl;
	}
	
	return 0;
}