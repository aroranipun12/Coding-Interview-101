void mirrorify(node* root,node** mirror){
    if(root==NULL)
        return;
    *mirror = new node(root->data);

    mirrorify(root->left,&(*mirror)->right);
    mirrorify(root->right,&(*mirror)->left);
}

int main( int argc , char ** argv )
{
    ios_base::sync_with_stdio(false) ; 
    cin.tie(NULL) ;

    /*        1
        2       3
       4  5    6  7
      8 9
       10
    */
    //make tree
    node* root = new node(1);
    
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->left->right->left = new node(10);
     
    //preorder_recursive(root);
    /*cout<<endl;
    preorder_iterative(root);
    cout<<endl;
    inorder_iterative(root);
    cout<<endl;
    postorder_iterative(root);
    cout<<endl;
    levelorder(root);
    cout<<endl;
    cout<<height(root);
    cout<<endl;
    node* ans = lca(root,5,3);
    if(ans != NULL)
        cout<<ans->data;
    cout<<endl;*/
    /*int max_level_so_far_1 = 0;
    leftView(root,1,max_level_so_far_1);*/
    /*int max_level_so_far_2 = 0;
    rightView(root,1,max_level_so_far_2);*/

    // topView(root);
    // cout<<endl;
    // bottomView(root);
    node* rootMirror = NULL ;
    mirrorify(root,&rootMirror);
    inorder_iterative(root);
    cout<<endl;
    inorder_iterative(rootMirror);
    return 0;
} 