class Solution {
public:
    int check_majority(vector<int> &nums,int index)
    {
        int count = 0;
         for(int i=0;i<nums.size();i++)
         {
             if(nums[i]==nums[index])
                 count++;
         }
        if(count > (nums.size()/2))
           return 1;
        return 0;
    }
    //moore's voting algo
    int possible_candidate(vector<int> &nums)//returns index of possible majority
    {
        int maj_index = 0;
        int count = 1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==nums[maj_index])
                count++;
            else
                count--;
            if(count==0)
            {
                maj_index = i;
                count  = 1;//reset
            }
        }
        if(check_majority(nums,maj_index))
            return nums[maj_index];
        else{
            return 0;
        }
        
    }
    
    
    int majorityElement(vector<int>& nums) {
       return possible_candidate(nums);  
    }
};