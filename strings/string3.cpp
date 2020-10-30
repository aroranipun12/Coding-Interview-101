#include<bits/stdc++.h>
using namespace std;

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 

	string str;
	cin>>str;

	set<char> dup;
	for(int i=0;i<str.length();i++){
		if(dup.find(str[i]) != dup.end())
			cout<<str[i]<<endl;
		else
			dup.insert(str[i]);
	}
	
	return 0;
}