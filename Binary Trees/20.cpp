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
    TreeNode* buildTreeHelper(vector<int> &pre,vector<int> &in,int preS,int preE,int inS,int inE){
        //size is 0,base case
        if(preS > preE)
            return NULL;
        //current root would be the first element of preorder (DLR)
        TreeNode* root = new TreeNode(pre[preS]);
        int root_index_inorder = -1;
        for(int i=inS;i<=inE;i++){
            if(in[i] == pre[preS]){
                root_index_inorder = i;
                break;
            }
        }
        //left and right corresponds to left and right subtree        
        int inS_left = inS;
        int inE_left = root_index_inorder - 1;
        int preS_left = preS + 1;
        int preE_left = inE_left - inS_left + preS_left;
        int inS_right = root_index_inorder + 1;
        int inE_right = inE;
        int preS_right = preE_left + 1;
        int preE_right = preE;

        
        root->left = buildTreeHelper(pre,in,preS_left,preE_left,inS_left,inE_left);  
        root->right = buildTreeHelper(pre,in,preS_right,preE_right,inS_right,inE_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        //args -> preorderStart,preE,inS,inE
        TreeNode* root = buildTreeHelper(preorder,inorder,0,size-1,0,size-1);     
    return root;
    }
};