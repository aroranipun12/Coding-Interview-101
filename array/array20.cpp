#include<bits/stdc++.h>
using namespace std;

void swap(int i,int j,int* arr){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
return;
}

void rearrange(int* arr,int n){
	bool flip = true;//true means negative honi chahiye and vice-versa
	bool swapped = false;
	int i=0;
	
	for(i=0;i<n;i++){
		if(flip && arr[i] >= 0){
			for(int j=i+1;j<n;j++){
				if(arr[j] < 0){
					swap(arr[i],arr[j]);
					break;
				}
			}	
		}

		else if(!flip && arr[i] < 0){
			for(int j=i+1;j<n;j++){
				if(arr[j] > 0){
					swap(arr[i],arr[j]);
					break;
				}
			}
		}
		flip = !flip;
	}
return;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}	
	rearrange(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}