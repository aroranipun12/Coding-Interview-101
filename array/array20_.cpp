#include <iostream> 
#include <assert.h> 
using namespace std; 

void rightrotate(int arr[], int n, int outofplace, int cur) 
{ 
	char tmp = arr[cur]; 
	for (int i = cur; i > outofplace; i--) 
		arr[i] = arr[i-1]; 
	arr[outofplace] = tmp; 
} 

void rearrange(int arr[], int n) 
{ 
	int outofplace = -1; 

	for (int index = 0; index < n; index ++) 
	{ 
		if (outofplace >= 0) 
		{ 
			if (((arr[index] >= 0) && (arr[outofplace] < 0)) 
				|| ((arr[index] < 0) && (arr[outofplace] >= 0))) 
			{ 
				rightrotate(arr, n, outofplace, index); 

				if (index - outofplace >= 2) 
					outofplace = outofplace + 2; 
				else
					outofplace = -1; 
			} 
		} 


		if (outofplace == -1) 
		{ 
			if (((arr[index] >= 0) && (!(index & 0x01))) 
				|| ((arr[index] < 0) && (index & 0x01))) 
			{ 
				outofplace = index; 
			} 
		} 
	} 
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
