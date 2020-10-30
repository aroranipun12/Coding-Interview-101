#include<bits/stdc++.h>
using namespace std;

void swap(int* arr,int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp; 
}
void printArray(int* arr,int size){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//two pointer technique
void solve2(int* arr,int n){
	int left = 0;
	int right = n-1;
	while(left < right){
		//+-
		if(arr[left]>=0 && arr[right]<0){
			swap(arr,left,right);
			left++;
			right--;
		}
		//++
		else if(arr[left]>=0 && arr[right]>=0){
			right--;
		}
		//--
		else if(arr[left]<0 && arr[right]<0){
			left++;
		}
		//-+
		else{
			left++;
			right--;
		}
	}
}

//using the concept of pivot like in quickSort algorithm
//we can use 0 as our pivot
void solve1(int* arr,int n){
	int j=0;
	for(int i=0;i<n;i++){
		if(arr[i] < 0){
			if(i != j)
				swap(arr,i,j);
		j++;
		}
    }
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	//input
	int size;
	cin>>size;
	int* arr = new int[size];
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	cout<<endl;
	
	/*solve1(arr,size);
	printArray(arr,size);
*/

	solve2(arr,size);
	printArray(arr,size);


	return 0;
}