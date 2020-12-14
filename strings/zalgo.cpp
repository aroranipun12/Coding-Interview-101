#include<bits/stdc++.h>
using namespace std;

void buildZ(int* Z,string str){
	int l = 0;
	int r = 0;

	int n = str.length();

	for(int i=1;i<n;i++){
		// it does not lie b/w l and r
		// means we don't have ans for it yet , we have to find it
		if(i > r){
			l = i;
			r = i;
				while(r < n && str[r-l]==str[r]){
					r++;
				}
			Z[i] = r-l;
			r--;
		}
		else{
			int k = i-l;
			// it lies b/w l and r
			if(Z[k]+i <= r){
				Z[i] = Z[k];
			}
			//some part of Z is already included , we still have to go further
			else{
				l = i;
				while(r<n && str[r-l]==str[r])
					r++;
				Z[k] = r-l;
				r--;
			}
		}
	}
}

void zSearch(string text,string pattern){
	string str = pattern + "$" + text;
	int n = str.length();
	int* Z = new int[n]();

	buildZ(Z,str);
	
	for(int i=0;i<n;i++){
		if(Z[i] == pattern.length()){
			cout<< i-pattern.length()-1 <<endl;
		}
	}
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	string text = "abcdsafbcdfasbcda";
	string pattern ="bcd";
	//cin>>text;
	//cin>>pattern;
	zSearch(text,pattern);
	return 0;
}