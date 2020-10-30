class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
         int count = 0;
        for(int i=0;i<n;i++){
            if(m[k-arr[i]])
                count+= m[k-arr[i]];
            if(k-arr[i] == arr[i])
                count--;
        }
    return count/2;
    }
};
//alternatively you can sort and use 2 pointer(putting one pointer at the end and one at the start)
//or brute force is simply check for every pair