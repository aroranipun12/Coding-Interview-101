/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
int sum(Node* root){
    if(!root)
        return 0;
    
    return root->data + sum(root->left) + sum(root->right);
}
bool isSumTree(Node* root)
{
    if(!root)
        return true;
    if(root->left == NULL && root->right == NULL)
        return true;
    else if(root->data == sum(root->left) + sum(root->right) && isSumTree(root->left) && isSumTree(root->right))
        return true;
    
    else
        return false;
}