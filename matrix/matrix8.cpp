class Solution {
public:
    void flip(vector<int>& matrix,int n){
        int left = 0;
        int right = n-1;
        while(left < right){
            int temp = matrix[left];
            matrix[left] = matrix[right];
            matrix[right] = temp;
            left++;right--;
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        //what we need to do here is we need to make 1st row last col and 2nd row 2nd last col
        //and ...... last row first col
        //steps to do it
        //1. make transpose of the matrix([i,j] -> [j,i])
        //2. flip the matrix horizontally (reverse rows) with two pointer approach
        
        int n = matrix.size();
        //transpose(in-place works only for square matrix)
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        //now flip the matrix horizontally
        for(int i=0;i<n;i++){
            flip(matrix[i],n);
        }
        
    }
};