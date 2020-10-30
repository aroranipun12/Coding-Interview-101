//keep on merging like mergesort
//optimal solution dhundo(this one took 200ms on leetcode)
class Solution {
public:
    vector<int> merge(vector<int> v1,vector<int> v2){
        int n = v1.size();
        int m = v2.size();
        
        int i=0;
        int j=0;
        
        int k=0;
        
        vector<int> result(m+n);
        while(i<n && j<m){
            if(v1[i] < v2[j])
                result[k++] = v1[i++];
            else
                result[k++] = v2[j++];
        }
        while(i<n)
            result[k++] = v1[i++];
        while(j<m)
            result[k++] = v2[j++];
    return result;
        
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        if(matrix.size() == 1)
            return matrix[0][k-1];
        vector<int> temp = merge(matrix[0],matrix[1]);
        int i=2;
        vector<int> temp1;
       
        while(rows>2){
            temp1 = merge(matrix[i],temp);
            temp = temp1;
            rows--;
            i++;
        }
    return temp[k-1];
    }
};