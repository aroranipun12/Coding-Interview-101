#include<bits/stdc++.h>
using namespace std;

void print_subseq(string str,string out){
	if(str.size() == 0){
		cout<<out<<endl;
		return;
	}
	print_subseq(str.substr(1,str.size()),out+str[0]);
	print_subseq(str.substr(1,str.size()),out);
return;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 

	string str;
	cin>>str;
	print_subseq(str,"");
	return 0;
}