#include<bits/stdc++.h>
using namespace std;

//steps in this algo
//take input in edgelist both normal and transpose
//call dfs and fill up finished stack
//pop from stack and call dfs on it wrt edgesT (remember to take new visited array or reset the old one) 

void dfs_1(vector<vector<int>> &edges,int n,vector<int> &visited_1,int sv,stack<int> &finishedVertices){
	visited_1[sv] = 1;

	for(auto itr = edges[sv].begin();itr!=edges[sv].end();itr++){
		if(!visited_1[*itr]){
			dfs_1(edges,n,visited_1,*itr,finishedVertices);
		}
	}
	finishedVertices.push(sv);
return;
}

void dfs_2(vector<vector<int>> &edgesT,vector<int> &visited_2,int sv,vector<int> &component){
	visited_2[sv] = 1;
	component.push_back(sv);
	for(auto itr = edgesT[sv].begin();itr!=edgesT[sv].end();itr++){
		if(!visited_2[*itr]){
			dfs_2(edgesT,visited_2,*itr,component);
		}
	}
return ;
}
vector<vector<int>> getSCC(vector<vector<int>> &edges,vector<vector<int>> &edgesT,int n){
	stack<int> finishedVertices;
	vector<int> visited_1(n,0);
	vector<vector<int>> output;
	//now call dfs
	for(int i=0;i<n;i++){
		if(!visited_1[i]){
			dfs_1(edges,n,visited_1,i,finishedVertices);
		}
	}
	//when dfs_1 finishes we'll have our stack filled up
	vector<int> visited_2(n,0);

	while(!finishedVertices.empty()){
		int curr_vertex = finishedVertices.top();
		finishedVertices.pop();
		if(!visited_2[curr_vertex]){
			vector<int> component;
			dfs_2(edgesT,visited_2,curr_vertex,component);
			output.push_back(component);
		}
	}
return output;
}

int main(int argc, char const *argv[])
{
	//take input edge and edgeT(transpose) in form of edgelist

	int n;//vertices (input from 1 to n ,but we'll store from 0 to n-1 and in ans we'll print +1)
	cin>>n;
	int e;//edges
	cin>>e;

	//edge lists(directed graph)
	vector<vector<int>> edges(n);
	vector<vector<int>> edgesT(n);

	//take input
	for(int i=0;i<e;i++){
		int v1,v2;//directed graph v1->v2
		cin>>v1>>v2;
		edges[v1-1].push_back(v2-1);
		edgesT[v2-1].push_back(v1-1);
	}

	vector<vector<int>> scc = getSCC(edges,edgesT,n);

	//print scc
	cout<<endl;
	for(auto itr1 = scc.begin();itr1!=scc.end();itr1++){
		vector<int> component = *itr1;
			for(auto itr2 = component.begin();itr2!=component.end();itr2++){
				cout<<*itr2 + 1<<" ";
			}
		cout<<endl;
	}

	return 0;
}