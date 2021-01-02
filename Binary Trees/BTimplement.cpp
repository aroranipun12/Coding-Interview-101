#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;
	int hd;
		node(int d)
		{
			data = d;
			left = NULL;
			right = NULL;
			hd = INT_MAX;
		}
};

int height(node* root)
{
	node* temp = root;
	if(temp == NULL)
		return 0;

	int left_h = height(root->left);
	int right_h = height(root->right);
	int ans = 1 + max(left_h,right_h);
return ans;
}
//least common ancestor
node* lca(node* root,int n1,int n2) // assuming n1 and n2 exists in the tree
{
	if(root == NULL)
		return NULL;
	if(root->data == n1 || root->data == n2)
		return root;

	node* lca1 = lca(root->left,n1,n2);
	node* lca2 = lca(root->right,n1,n2);

	if(lca1 && lca2)//matlab ek left m h ek right m h
		return root;

	return (lca1!=NULL)?lca1:lca2;

}

void levelorder(node* root)
{
	node* temp = root;
	queue<node*> q;
	q.push(temp);
		while(!q.empty())
		{
			temp = q.front();
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
}

void preorder_iterative(node* root)  //using a stack
{
	node* temp = root;
	stack<node*> s;
	//s.push(temp);
	while(1)
	{
		while(temp)
		{
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
}

void inorder_iterative(node* root)
{
	node* temp = root;
	stack<node*> s;
	while(1)
	{
		while(temp)
		{
			s.push(temp);
			temp = temp->left;
		}
		if(s.empty())
			break;

		temp = s.top();
		s.pop();
		cout<<temp->data<<" ";
		temp=temp->right;
	}
}

void preorder(node* root)   //traversals
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node* root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}	
}
vector<int> postorderTraversal(node* root) {
        vector<int> ans;
        stack<node*> s;
        node* prev = NULL;
        do{
            while(root!=NULL)
            {
                s.push(root);
                root=root->left;
            }

            while(root == NULL && !s.empty())
            {
                root = s.top();
                
                //means leaf node or right //tree and left tree   // processd already                                                                                          
                    if(root->right == NULL || root->right == prev)                            
                    {
                        ans.push_back(root->data);
                        s.pop();
                        prev = root;
                        root = NULL;
                    }
                else{
                    root = root->right;
                }
            }

            
        }while(!s.empty());
    return ans;
    }

void bottomView(node* root)//level order traversal using queue while updating map using hd //hd is horizontal distance from root
//hd of root is zero //hd of root->left is -1 and root->right is 1 respectively
//basically left jao toh distance -1 kro right jao toh distance +1 kro
{
	int hd = 0;
	queue<node*> q;
	map<int,int> m;
	root->hd = hd;
	q.push(root);
		
		while(!q.empty())
		{
			node* temp = q.front();
			q.pop();
			hd = temp->hd;
			m[hd] = temp->data;	//update m[hd]

			if(temp->left != NULL)
			{
				temp->left->hd = hd-1;
				q.push(temp->left);
			}
			if(temp->right != NULL)
			{
				temp->right->hd = hd+1;
				q.push(temp->right);
			}
		}
		for (auto i = m.begin(); i != m.end(); ++i) 
        cout << i->second << " "; 

}
void topView(node* root)
{
	int hd = 0;
	queue<node*> q;
	map<int,int> m;
	root->hd = hd;
	q.push(root);
	node* temp = root;

		
		while(!q.empty())
		{
			
			temp = q.front();
			q.pop();
			hd = temp->hd;
			if(m.count(hd)==0)//if hd not processed, only then we put it in the map cos topView
				{
					m[hd] = temp->data;
				}	

			if(temp->left != NULL)
			{
				temp->left->hd = hd-1;
				q.push(temp->left);
			}
			if(temp->right != NULL)
			{
				temp->right->hd = hd+1;
				q.push(temp->right);
			}

			/*q.pop();
			temp = q.front();*/
			
		}
		for (auto i = m.begin(); i != m.end(); ++i) 
        cout << i->second << " "; 

}

void leftViewUtil(node* root,int curr_level,int &max_level)
{
	if(root == NULL)
		return;

	if(curr_level > max_level) //whenever we see a node whose level is greater then max level then that node is leftest of next level 
	{
		cout<<root->data<<" ";
		max_level = curr_level;
	}
	leftViewUtil(root->left,curr_level+1,max_level);
	leftViewUtil(root->right,curr_level+1,max_level);
}
void leftView(node* root)
{
	int max_level = 0;
	leftViewUtil(root,1,max_level);
}



void rightViewUtil(node* root,int curr_level,int &max_level)
{
	if(root == NULL)
		return;

	if(curr_level > max_level) //whenever we see a node whose level is greater then max level then that node is leftest of next level 
	{
		cout<<root->data<<" ";
		max_level = curr_level;
	}
	rightViewUtil(root->right,curr_level+1,max_level);
	rightViewUtil(root->left,curr_level+1,max_level);
}
void rigthView(node* root)
{
	int max_level = 0;
	rightViewUtil(root,1,max_level);
}
int main()
{
	node* root = new node(1);
	
	root->left = new node(2);
	root->right = new node(3);

	root->left->left = new node(4);
	root->left->right = new node(5);	
	root->right->left = new node(6);
	root->right->right = new node(7);

	root->right->left->left = new node(8);
	root->right->left->right = new node(9);



	//preorder(root);
	inorder(root);
	//cout<<endl;
	//preorder_iterative(root);
	//inorder_iterative(root);
	//levelorder(root);
	//node* n = lca(root,6,7);
	//cout<<n->data;
	//cout<< height(root) -1 ;//height of the tree
	/*vector<int> ans = postorderTraversal(root);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";*/
	//bottomView(root);
	//topView(root);
	/*leftView(root);
	cout<<endl;
	rigthView(root);*/
	return 1;
}