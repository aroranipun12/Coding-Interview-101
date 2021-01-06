class node{ //data structure for binary tree
public:
    int data;
    int hd;//horizontal distance i.e., distance from root 
    node* left;
    node* right;
        node(int value){
            //constructor
            data = value;
            left = NULL;
            right = NULL;
            hd = INT_MAX;
        }
        node(){
            data = INT_MAX;
            hd = INT_MAX;
            left = NULL;
            right = NULL;
        }
};

//assuming k1 and k2 exists in the tree
node* lca(node* root,int k1,int k2){

    if(root == NULL)
        return NULL;
    //agar aisa h then root hi lca hua
    if(root->data == k1 || root->data == k2)
        return root;
    //otherwise left pe call kro and right pe call kro

    node* lca_left = lca(root->left,k1,k2);
    node* lca_right = lca(root->right,k1,k2);

    //means ek left m h and ek right m h
    if(lca_left!=NULL && lca_right!=NULL){
        return root;
    }

    return (lca_left==NULL)?lca_right:lca_left;

}