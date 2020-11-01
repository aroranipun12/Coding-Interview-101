class Solution {
public:
    //this will return the index but that can be starting or ending or anything in the middle
    int search(vector<int>& nums,int target){
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }
    return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size() == 0)
        {
            result.push_back(-1);
            result.push_back(-1);
        return result;
        }
        if(nums.size() == 1 && target == nums[0])
        {
            result.push_back(0);
            result.push_back(0);
        return result;
        }
        
        
        int start;
        int end;
        int index = search(nums,target);
      
        
        if(index == -1){
            result.push_back(-1);
            result.push_back(-1);
        return result;
        }
        
        int i = index;
        //keep going left until we find the starting index for target
        while(i-1>=0 && nums[i-1] == target)
            i--;
        start = i;
        //keep going right
        i = index;
        while(i+1<=nums.size()-1 && nums[i+1] == target)
            i++;
        end = i;
        result.push_back(start);
        result.push_back(end);
        return result;
    }
};