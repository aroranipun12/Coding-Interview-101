#include<bits/stdc++.h>
using namespace std;

void print_subseq(char* str,string out,int size){
	if(size==0){
		cout<<out<<endl;
		return;
	}
	print_subseq(str+1,out+str[0],size-1);
	print_subseq(str+1,out,size-1);
return;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	int size ;
	cin>>size;
	char str[100];
	cin>>str;
	print_subseq(str,"",size);//agar char array lere h toh size bhi bhejna pdega na
	return 0;
}