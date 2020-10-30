class Solution {
public:
    int maxProfit(vector<int>& prices) {
       //kadane's algo
        int max_so_far = 0;
        int curr_max = 0;
        if(prices.size()==0)
            return 0;
        for(int i=1;i<prices.size();i++)
        {
            curr_max = max(0,curr_max+=prices[i]-prices[i-1]);
            max_so_far = max(max_so_far,curr_max);
        }
        return max_so_far;
    }
};