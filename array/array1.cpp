// time complexity -> O(n)
#include<bits/stdc++.h>
using namespace std;

void reverse(int* arr,int n){
	int left = 0;
	int right = n-1;
	//keep swapping till left == right

	while(left!=right){
		//swap
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}

}

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
	reverse(arr,size);
	cout<<endl;
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" " ;
	}
	cout<<endl;
	
	return 0;
}