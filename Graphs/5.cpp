#include<bits/stdc++.h>
using namespace std;

bool cycleUtil(vector<vector<int>>& edges,int n,vector<int>& visited,int sv,int pv) {
    visited[sv] = 1;
    //check adjacent to sv
    for(auto itr = edges[sv].begin();itr != edges[sv].end();itr++){
        if(!visited[*itr]){ 
            if(cycleUtil(edges,n,visited,*itr,sv))
                return true;
        }
        //if adjacent is already visited but not equal to parent or prev vertex then there must be a cycle
        else if(*itr != pv)
            return true;
    }    
return false;
}

//directed graph
bool cycle( vector<vector<int>>& edges,int n){
    vector<int> visited(n,0);

    //assuming the graph is connected
    //0 is the starting vertex,-1 is the prev vertex
    return cycleUtil(edges,n,visited,0,-1);

}

int main(int argc, char const *argv[])
{
    int n,e;
    cin>>n>>e;

    //vertices from 0 to n-1
    //adjacency list(undirected graph)
    vector<vector<int>> edges(n);

    //input adjacency list
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }

    cout<<cycle(edges,n);

    return 0;
}