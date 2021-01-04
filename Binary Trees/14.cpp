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
     int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int ans1 = height(root->left);
        int ans2 = height(root->right);
        return 1 + max(ans1,ans2);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        bool ans;
        if(abs(lh-rh) > 1)
            ans = false;
        else
            ans = true;
        
        return ans && isBalanced(root->left) && isBalanced(root->right);
        
    }
};