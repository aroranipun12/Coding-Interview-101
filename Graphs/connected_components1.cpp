#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& edges,int n,int start,vector<int>& visited,vector<int> &component){
	visited[start] = 1;
	component.push_back(start);

	for(auto itr = edges[start].begin(); itr!=edges[start].end();itr++){
		if(!visited[*itr]){
			dfs(edges,n,*itr,visited,component);
		}
	}
}

vector<vector<int>> getComponents(vector<vector<int>> &edges,int n){

	vector<vector<int>> output;

	vector<int> visited(n,0);
	for(int i=0;i<n;i++){
		if(!visited[i]){
			vector<int> component; 
			dfs(edges,n,i,visited,component);
			output.push_back(component);
		}
	}
	return output;
}

int main(){

	int n;
	cin>>n;

	//edge list
	vector<vector<int>> edges(n);

	int m;
	cin>>m;

	for(int i=0;i<m;i++){
		int v1,v2;
		cin>>v1>>v2;
		edges[v1].push_back(v2);
		edges[v2].push_back(v1);
	}

	vector<vector<int>> output = getComponents(edges,n);

	for(auto itr = output.begin();itr!=output.end();itr++){
		vector<int> component = *itr;
		for(auto itr1 = component.begin();itr1!=component.end();itr1++){
			cout<<*itr1<<" ";
		}
	cout<<endl;
	}
	return 0;
}