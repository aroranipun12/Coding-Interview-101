//Brute force way -> first sort , then put 3 pointers i,j,k and call binary search from arr[k+1] to arr[n-1]
//And store quads in a DS then extract only unique quads from the DS

//Better approach -> first sort, then put 2 pointers i and j and then call twosum from arr[j+1] to arr[n-1]
//the trick here is to update the pointer to next distinct element hence duplicate quads will not be generated at all
//so the space complexity here is O(1) and time is O(n^3)  

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        if(n == 0)
            return result;
        sort(nums.begin(),nums.end());
        
        int i,j,left,right;
        
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                left = j+1;
                right = n-1;
                int new_target = target-(nums[i]+nums[j]);
                while(left < right){
                    if(nums[left]+nums[right] < new_target){
                        left++;
                    }
                    else if(nums[left]+nums[right] > new_target){
                        right--;
                    }
                    else{
                        vector<int> quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[left];
                        quad[3]=nums[right];
                        result.push_back(quad);
                    
                    //jump duplicate
                    while(left<right && nums[left] == quad[2])left++;
                    while(left<right && nums[right] == quad[3])right--;
                    }
                }
            //update j (but ek kam kyunki loop m bhi ++ hora h and same for i)
            while(j+1<n && nums[j+1]==nums[j])j++;
            }
        //update i
        while(i+1<n && nums[i+1]==nums[i])i++;

        }
    return result;
    }
};