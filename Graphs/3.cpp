#include <bits/stdc++.h>
using namespace std;

void bfs(int** edges,int n,int sv,int* visited){
    if(n==0)
        return;
    queue<int> q;
    q.push(sv);
    visited[sv] = 1;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        
        	for(int i=0;i<n;i++){
                if(edges[node][i] && !visited[i]){
                    q.push(i);
                    visited[i] =1 ;
                }
            }
    }
}

//recursive function
void dfs(int** edges,int n,int sv,int* visited){
	cout<<sv;
	visited[sv] = 1;

	for(int i=0;i<n;i++){
		if(edges[sv][i] && !visited[i]){
			dfs(edges,n,i,visited);
		}
	}
}

int main() {
    int n, e;
    cin >> n >> e;
    
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++)
            edges[i][j] = 0;
    }
    
    int* visited = new int[n];
    for(int i=0;i<n;i++)
        visited[i] = 0;
    
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = edges[s][f] =1;
    }
    for(int i=0;i<n;i++)
    	if(!visited[i])
        	bfs(edges,n,i,visited);

    /*for(int i=0;i<n;i++)
    	if(!visited[i])
        	dfs(edges,n,i,visited);*/

  return 0;
}
