/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //level order traversal using a bool variable to reverse 
        if(!root)
            return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        int level = 0;//we'll keep toggling it
        
        q.push(root);
        
            while(!q.empty()){
                
                int size = q.size();
                vector<int> each_level(size,0);
                
                for(int i=0;i<size;i++){
                    TreeNode* temp = q.front();
                    q.pop();
                    
                    if(level == 0){
                        each_level[i] = temp->val; 
                    }
                    else{
                        each_level[size-i-1] = temp->val;
                    }
                    
                    if(temp->left) 
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                }
                result.push_back(each_level);
                level = !level;
            }
        return result;
    }
};