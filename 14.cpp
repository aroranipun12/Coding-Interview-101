class Solution {
public:
    void insertion(vector<int>& nums2,int n){
        if(n==1)
            return;
        if(nums2[0]<nums2[1])
            return;
        else{
            int temp = nums2[0];
            int i=1;
            while(i<n && temp>nums2[i]){
                nums2[i-1] = nums2[i];
                i++;
            }
            nums2[i-1] = temp;
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m>=0 && n==0)
            return;
        //do it without using extra space
        int p1 = 0;
        while(p1<m){
            if(nums1[p1]>nums2[0]){
                int temp = nums1[p1];
                nums1[p1] = nums2[0];
                nums2[0] = temp;
                insertion(nums2,n);
            }    
        p1++;
        }
        //now just put nums2 as it is in nums1
        int i=0;
        while(i<n)
        {
            nums1[p1]=nums2[i];
            i++;
            p1++;
        }
    }
};