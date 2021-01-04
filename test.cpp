#include<bits/stdc++.h>
using namespace std;

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

int height(node* root){
    if(root == NULL)
        return 0;
    int leftHeight = 1 + height(root->left);
    int rightHeight = 1 + height(root->right);

return max(leftHeight,rightHeight);
}

//similarly you can write recursively for other traversals
void preorder_recursive(node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder_recursive(root->left);
    preorder_recursive(root->right);
return;
}

void preorder_iterative(node* root){
    node* temp = root;
    stack<node*> s;
    //s.push(root);

    while(true){
            while(temp!=NULL){
                cout<<temp->data<<" ";
                s.push(temp);
                temp = temp->left;
            }
        if(s.empty())
            break;
        temp = s.top();
        s.pop();
        temp = temp->right;
    }
return;
}

void inorder_iterative(node* root){
    node* temp = root;
    stack<node*> s;

    while(true){
        while(temp != NULL){
            s.push(temp);
            temp = temp->left;
        }
        if(s.empty())
            break;
        temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp = temp->right;
    }

}

//bfs
void levelorder(node* root){
    node* temp = root;
    queue<node*> q;
    q.push(temp);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);

    }
}
void postorder_iterative(node* root){
    node* temp = root;
    node* prev = NULL;
    stack<node*> s;

    do{
        while(temp != NULL){
            s.push(temp);
            temp = temp->left;
        }

        while(temp == NULL && !s.empty()){
            temp = s.top();

            //ya to leaf node ho aur ya toh right already processed h tab hum print krege
            if(temp->right == NULL || temp->right == prev){
                cout<<temp->data<<" ";
                s.pop();
                prev = temp;
                temp = NULL;
            }
            //this means ki left process hogya h but right nahi hua h
            else{
                temp = temp->right;
            }
        }
    }while(!s.empty());
}

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
// left and Right view
//basically left aur rightview ko hume level ke according krna h,har level ka pehla node while calling left or right first,recursively
void leftView(node* root,int curr_level,int &max_level_so_far){
    if(root == NULL)
        return;

    //basically we need to print first node of every level while calling left first
    if(curr_level > max_level_so_far){
        cout<<root->data<<endl;
        max_level_so_far = curr_level;
    }

    leftView(root->left,curr_level+1,max_level_so_far);
    leftView(root->right,curr_level+1,max_level_so_far);
}
void rightView(node* root,int curr_level,int &max_level_so_far){
    if(root == NULL)
        return;

    //basically we need to print first node of every level while calling right first
    if(curr_level > max_level_so_far){
        cout<<root->data<<endl;
        max_level_so_far = curr_level;
    }
    rightView(root->right,curr_level+1,max_level_so_far);
    rightView(root->left,curr_level+1,max_level_so_far);
}

//Top and Bottom View

void topView(node* root){
    node* temp = root;
    int hd = 0;
    temp->hd = 0; // root ka hd 0 krdo
    map<int,int> m; // hd ke corresponding temp->data rakhege
    queue<node*> q;
    q.push(temp);

        while(!q.empty()){
            temp = q.front();
            q.pop();
            hd = temp->hd;
            //means ki ye vala hd map m nahi aaya h
            if(m.find(hd) == m.end()){
                m[hd] = temp->data;
            }   
            if(temp->left){
                temp->left->hd = hd-1;
                q.push(temp->left);
            }
            if(temp->right){
                temp->right->hd = hd+1;
                q.push(temp->right);
            }
        }
    //at this point our ans is in the map

    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->second<<" ";
    }

}
void bottomView(node* root){
 node* temp = root;
    int hd = 0;
    temp->hd = 0; // root ka hd 0 krdo
    map<int,int> m; // hd ke corresponding temp->data rakhege
    queue<node*> q;
    q.push(temp);

        while(!q.empty()){
            temp = q.front();
            q.pop();
            hd = temp->hd;
            
            //har baar update krte raho , jo last update hoga vhi bottom view ka part hoga
                m[hd] = temp->data;
            
            if(temp->left){
                temp->left->hd = hd-1;
                q.push(temp->left);
            }
            if(temp->right){
                temp->right->hd = hd+1;
                q.push(temp->right);
            }

        }
    //at this point our ans is in the map

    for(auto i=m.begin();i!=m.end();i++){
        cout<<i->second<<" ";
    }

}

//max distance b/w any two leaf nodes
//max(passing thru root,diameter of leftsubtree,diameter of right subtree)
int diameter(node* root){
    if(root == NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);

    int ld=diameter(root->left);
    int rd=diameter(root->right);

    return max(lh+rh+1,max(ld,rd));
}
//absolute difference of lheight and rheight for every node
bool isheightBalanced(node* root){
    if(root == NULL)
        return true;

    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh) <= 1 && isheightBalanced(root->left) && isheightBalanced(root->right)){
        return true;
    }
return false;
}

void printLevel(node* root,int level){
    if(root == NULL)
        return ;
    
    if(level == 1)
        cout<<root->data;

    else{
        printLevel(root->left,level-1);
        printLevel(root->right,level-1);    
    }
}

void mirrorify(node* root,node** mirror){
    if(root==NULL)
        return;
    *mirror = new node(root->data);

    mirrorify(root->left,&(*mirror)->right);
    mirrorify(root->right,&(*mirror)->left);
}
int findIndex(string str,int si,int ei){
    if(si > ei)
        return -1;
    stack<char> s;

    for(int i=si;i<=ei;i++){
        if(str[i] == '(')
            s.push(str[i]);
        else if(str[i] == ')'){
            if(s.top() == '('){
                s.pop();
            
            //if at any iteration stack i empty then this is the required index
            if(s.empty())
                return i;
            }
        }
    }
return -1;//not found
}
//starting index and ending index
node* buildTreeFromString(string str,int si,int ei){
    if(si>ei)
        return NULL;

    node* root = new node(str[si] - '0');//interger m convert krne ke liye subtract
    int index = -1;
    if(si + 1 <= ei && str[si+1] == '(' ){
         index = findIndex(str,si+1,ei);
    }    
    //now index of starting ( is si+1 and ) is index variable (left subtree)
    //index of starting ( is index+1 and ending ) is ei-1 (right subtree)

    if(index != -1){
        root->left = buildTreeFromString(str,si+2,index-1);
        root->right = buildTreeFromString(str,index+2,ei-1);
    }
return root;
}

void checkHelper(node* root,vector<int> &leaf_level,int level){
    if(!root)
        return;
    if(!root->left && !root->right){
        leaf_level.push_back(level);
        return;
    }
    checkHelper(root->left,leaf_level,level+1);
    checkHelper(root->right,leaf_level,level+1);
}

/*You are required to complete this method*/
bool check(node *root)
{
    //Your code here
    vector<int> leaf_level;
    checkHelper(root,leaf_level,0);
    for(int i=0;i<leaf_level.size();i++)
    {
        /*if(leaf_level[i] != leaf_level[i-1])
            return false;*/
        cout<<leaf_level[i]<<" ";
    }
return true;
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
   /* node* rootMirror = NULL ;
    mirrorify(root,&rootMirror);
    inorder_iterative(root);
    cout<<endl;
    inorder_iterative(rootMirror);*/

    string str = "4(2(3)(1))(6(5)(4))";
    node* root_1 = buildTreeFromString(str, 0, str.length() - 1);
    //preorder_iterative(root_1);
    bool ans = check(root_1);



    return 0;
} 