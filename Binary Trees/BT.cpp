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
};


void preorder(node* root){
	if(root == NULL)
		return ;

	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
}


void inorder(node* root){
	if(root == NULL)
		return ;

	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}


void postorder(node* root){
	if(root == NULL)
		return ;

	postorder(root->left);
	postorder(root->right);
	cout<<root->data;
}

void preorder_iterative(node* root){
node* temp = root;
stack<node*> s;
	while(true){
		while(temp!=NULL){
			cout<<temp->data;
			s.push(temp);
			temp=temp->left;
		}
		if(s.empty())
			break;
		temp = s.top();
		s.pop();
		temp = temp->right;
	}
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
		cout<<temp->data;
		temp = temp->right;
	}
}

void postorder_iterative(node* root){
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
                        cout<<root->data;
                        s.pop();
                        prev = root;
                        root = NULL;
                    }
                else{
                    root = root->right;
                }
            }

            
        }while(!s.empty());
}

void levelorder(node* root){
	queue<node*> q;
	node* temp = root;
	q.push(temp);
		while(!q.empty()){
			temp = q.front();
			cout<<temp->data;
			
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			
			q.pop();
		}
}

int height(node* root){
	if(root == NULL)
		return 0;
	int lh = height(root->left);
	int rh = height(root->right);
	return max(lh,rh) + 1; 
}

//assuming key1 and key2 exists in tree
node* lca(node* root, int key1,int key2){

	if(root==NULL){
		return NULL;
	}

	if(root->data == key1 || root->data == key2){
		return root;
	}
	//go left
	node* lca1 = lca(root->left,key1,key2);
	//go right
	node* lca2 = lca(root->right,key1,key2);

	//ek left m ek right m
	if(lca1 != NULL  && lca2!=NULL){
		return root;
	}

	return (lca1==NULL)?lca2:lca1;
}
//int max_level_so_far = 0;//can also take as reference in the arugument of function
void leftView(node* root,int curr_level,int &max_level_so_far){
	if(root == NULL)
		return ;

	if(curr_level>max_level_so_far){
		cout<<root->data;
		max_level_so_far = curr_level;
	}
	leftView(root->left,curr_level+1,max_level_so_far);
	leftView(root->right,curr_level+1,max_level_so_far);
}

void rightView(node* root,int curr_level,int &max_level_so_far){
	if(root == NULL)
		return ;
	if(curr_level>max_level_so_far){
		cout<<root->data;
		max_level_so_far = curr_level;
	}
	rightView(root->right,curr_level+1,max_level_so_far);
	rightView(root->left,curr_level+1,max_level_so_far);
}

void topView(node* root){
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


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	//create tree
/*				1  					level1
		2		         3  		level2
	4       5       6	       7  	level3
	             8    9      		level4
*/	
	node* root = new node(1);

	root->left = new node(2);
	root->right = new node(3);

	root->left->left = new node(4);
	root->left->right = new node(5);	
	root->right->left = new node(6);
	root->right->right = new node(7);
	


	root->right->left->left = new node(8);
	root->right->left->right = new node(9);
	

//traverse recursively
	/*preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;*/
//traverse iteratively
	/*preorder_iterative(root);
	cout<<endl;
	inorder_iterative(root);
	cout<<endl;
	postorder_iterative(root);
	cout<<endl;
	levelorder(root);
	cout<<endl; */

//lca
	//cout<<lca(root,key1,key2)->data;

//height
	//cout<<height(root);
//diameter
	//cout<<diameter(root);

//Views(top bottom left right)
	//int max_level_so_far = 0;// common to leftView and rightView right now
	//leftView(root,1,max_level_so_far);//1 is current level and 0 is max level so far
	//rightView(root,1,max_level_so_far);//just change curr_level in recursion and keep track of max_level_so_far externally
	
	//topView(root);
	//bottomView(root);

//extras
	//bool ans = isheightBalanced(root);
	//cout<<ans;
	//bool ans = isIdentical(root1,root2);
	//cout<<symmetrical(root,root); // mirror image of itself or not
	printLevel(root,4);//2nd arg is level to print
	return 0;
}