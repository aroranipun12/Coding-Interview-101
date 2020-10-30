#include<bits/stdc++.h>
using namespace std;

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ;

	int size;
	cin>>size;
	int* arr = new int[size];
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	int min=INT_MAX;
	int max=INT_MIN;

	for(int i=0;i<size;i++){
		if(arr[i]>max){
			max = arr[i];
		}
		if(arr[i]<min){
			min=arr[i];
		}
	}

	cout<<"min: "<<min<<endl;
	cout<<"max: "<<max<<endl;

	return 0;
}