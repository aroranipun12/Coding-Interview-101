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
void preorder_recursive(node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder_recursive(root->left);
    preorder_recursive(root->right);
return;
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

int main( int argc , char ** argv )
{
    ios_base::sync_with_stdio(false) ; 
    cin.tie(NULL) ;

    string str = "4(2(3)(1))(6(5))";
    node* root_1 = buildTreeFromString(str, 0, str.length() - 1);
    preorder_recursive(root_1);

    return 0;
} 