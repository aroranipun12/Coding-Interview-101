class Solution {
public:
    int search(vector<int>& nums,int left,int right,int target){
        
        while(left <= right){
            int mid = (left+right)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            else if(nums[mid] > target){
                right = mid-1;    
            }
            else
                left = mid+1;
                
        }
    return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int pivot_start;
        int n = nums.size();
        
        //pivot is guranteed
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                pivot_start = i;
                break;
            }
            else
                continue;
        }
        
        int ans1 = search(nums,0,pivot_start,target);
        if(ans1 != -1)
            return ans1;
        
        int ans2 = search(nums,pivot_start+1,n-1,target);
        
        if(ans2 != -1)
            return ans2;
        return -1;
    }
};