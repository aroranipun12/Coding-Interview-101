/*112. Path Sum
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.*/
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        
        if(root->val == sum && !root->left && !root->right)
            return true;
        
        return hasPathSum(root->left,sum - root->val) || hasPathSum(root->right , sum-root->val);
    }
};

class Solution {
public:
    void pathSumHelper(TreeNode* root,vector<int> &sums,int sum){
        //if leaf node
    
        if(!root->left && !root->right){
            sums.push_back(root->val + sum);
            return;
        }
        
        sum += root->val;
        if(root->left)
            pathSumHelper(root->left,sums,sum);
        if(root->right)
            pathSumHelper(root->right,sums,sum);
    return;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        vector<int> sums;
        pathSumHelper(root,sums,0);
        for(auto itr = sums.begin();itr!=sums.end();itr++){
            if(sum == *itr)
                return true;
        }
    return false;
    }
};