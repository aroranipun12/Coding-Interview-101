class Solution{
public:
	//arr2 is sorted from 1st index
	void insesrtion(int* arr2,m){
		int key = arr2[0];
		int i;
		for( i=1;i<m;i++){
			if(key > arr[i])
				arr[i-1] = arr[i];
			if(key < arr[i])
				break;
		}
		arr[i-1] = key;
	}
	void merge(int arr1[], int arr2[], int n, int m) {
		int i=0;
		while(i<n){
			if(arr1[i] > arr2[0]){
				//swap these two
				int temp = arr1[i];
				arr1[i] = arr2[0];
				arr2[0] = temp;
				//increment i
				i++;
				//call insertion on arr2
				insertion(arr2,m);
			}
			else{
				i++;
			}
		}	
	}
};