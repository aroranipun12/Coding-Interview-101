/*106. Construct Binary Tree from Inorder and Postorder Traversal*/

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
    TreeNode* buildTreeHelper(vector<int> &in,vector<int> &post,int inS,int inE,int postS,int postE){
        if(inS > inE)
            return NULL;
        
        TreeNode* root = new TreeNode(post[postE]);
        int root_index_inorder = -1;
        for(int i=inS ; i<=inE;i++){
            if(in[i] == post[postE]){
                root_index_inorder = i;
                break;
            }
        }
        //now we have root index in inorder
        //we need these 8 indexes in left and right subtree respectively
        int inS_left = inS;
        int inE_left = root_index_inorder - 1;
        int postS_left = postS;
        int postE_left = inE_left - inS_left + postS_left;
        int inS_right = root_index_inorder + 1;
        int inE_right = inE;
        int postS_right = postE_left + 1;
        int postE_right = postE - 1;
        root->left = buildTreeHelper(in,post,inS_left,inE_left,postS_left,postE_left);
        root->right = buildTreeHelper(in,post,inS_right,inE_right,postS_right,postE_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        TreeNode* root = buildTreeHelper(inorder,postorder,0,size-1,0,size-1);
        return root;
    }
};