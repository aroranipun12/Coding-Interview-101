#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;
		node(int value)
		{
			data = value;
			left = NULL;
			right = NULL;
		}
};

node* min_node(node* root)  // returns address of leftmost node of bst
{
	while(root->left!=NULL)
	{
		root = root->left;
	}

return root;
}

node* max_node(node* root) //returns address of rightmost node of bst
{
	while(root->right!=NULL)
	{
		root = root->right;
	}

return root;
}

void inorderps(node* root ,int key,node* &pred,node* &suc )  //inorder predecessor and successor //assuming key exists //pred and suc are reference so that we don't have to return anything
{
     if(root==NULL)
     	return;
     
     if(key == root->data)
     {
     	node* temp1 = root->left;
     	node* temp2 = root->right;
     	pred=max_node(temp1);
     	suc=min_node(temp2);
     return;
     }

     if(key>root->data)
     	inorderps(root->right,key,pred,suc);
     else
     	inorderps(root->left,key,pred,suc);
return;
}

node* find(node* root,int key)
{
	if(root == NULL)
		return NULL;

	if(root->data == key)
		return root;
	
	else if(key > root->data)
		find(root->right,key);
	
	else
		find(root->left,key);

}

int min_element(node* root)
{
	while(root->left!=NULL)
	{
		root = root->left;
	}

return (root->data);
}


// 			7
//		4		9
//	   2 5     8 10
int main()
{
	node* root = new node(7);  
	node* node4 = new node(4);
	node* node9 = new node(9); 
	node* node2 = new node(2);
	node* node5 = new node(5);
	node* node8 = new node(8);
	node* node10 = new node(10);

	root->left = node4;
	node4->left = node2;
	node4->right = node5;

	root->right = node9;
	node9->left = node8;
	node9 ->right = node10;

	/*node* inorder_predecessor=NULL;
	node* inorder_successor=NULL;
	
	inorderps(root,7,inorder_predecessor,inorder_successor);
	
	cout<<"pred is "<<inorder_predecessor->data<<endl;
	cout<<"succ is "<<inorder_successor->data<<endl;*/

	//cout<<min_element(root)<<endl;

	/*node* ans = find(root,10);  
	if(ans)
		cout<<ans->data<<" " <<&ans<<endl;
	else
		cout<<"not found"<<endl;
	return 1;*/
}