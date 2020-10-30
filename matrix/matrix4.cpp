class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int count = INT_MIN;
	    int row=-1;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(arr[i][j] == 1){
	                if(count < m-j){
	                    count = m-j;
	                    row = i;
	                }
                break;	           
	            }
	        }
	    }
	    return row;
	}

};