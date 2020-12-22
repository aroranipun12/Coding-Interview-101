/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* curr,Node* node,vector<Node*> &visited){
        visited[node->val] = node;
        for(auto itr : curr->neighbors){
            if(visited[itr->val] == NULL){
                Node* newnode = new Node(itr->val);
                node->neighbors.push_back(newnode);
                dfs(itr,newnode,visited);
            }
            else{
                node->neighbors.push_back(visited[itr->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        //base case
        if(node == NULL){
            return NULL;
        }
        //assuming 500 se jyada nodes nahi hongi graph ke andar
        vector<Node*> visited(500,NULL);  
        Node* clone = new Node(node->val);
        visited[clone->val] = clone;
        
        for(auto curr : node->neighbors){
            if(visited[curr->val] == NULL){
                Node* newnode = new Node(curr->val);
                clone->neighbors.push_back(newnode);
                dfs(curr,newnode,visited);
            }
            else{
                clone->neighbors.push_back(visited[curr->val]);
            }
        }
    return clone;
    }
};