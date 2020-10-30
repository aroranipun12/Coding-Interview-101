class Solution {
public:
    bool search(vector<int> &nums,int left,int right,int target)
    {
        int mid;
            while(left <= right)
            {
                mid = left + (right-left)/2;
                if(nums[mid] == target)
                    return true;
                else if(nums[mid] > target)
                {
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }

            }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0)
            return false;
        int col = matrix[0].size();
        if(col == 0)
            return false;
        for(int i=0;i<row;i++)
        {
            if(target > matrix[i][col-1])//move to next row 
            {
                continue;
            }
            else{ //must be present in this row
                return search(matrix[i],0,col-1,target);
            }
        }
        return false;
    }
};