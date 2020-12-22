#include<bits/stdc++.h>
using namespace std;

bool cycleUtil(vector<vector<int>>& edges,int n,vector<int>& visited,vector<int>& stack,int sv){
    visited[sv] = 1;
    stack[sv] = 1;

    //check adjacent to sv
    for(auto itr = edges[sv].begin();itr != edges[sv].end();itr++){
        if(!visited[*itr] && cycleUtil(edges,n,visited,stack,*itr))
            return true;
        // meaning *itr already aa chuka h then cycle must exist
        if(stack[*itr])
            return true;
    }
    stack[sv] = false;
return false;
}

//directed graph
bool cycle( vector<vector<int>>& edges,int n){
    vector<int> visited(n,0);
    vector<int> stack(n,0);

    //assuming the graph is connected
    //0 is the starting vertex
    return cycleUtil(edges,n,visited,stack,0);

}

int main(int argc, char const *argv[])
{
    int n,e;
    cin>>n>>e;

    //vertices from 0 to n-1
    //adjacency list(directed graph)
    vector<vector<int>> edges(n);

    //input adjacency list
    for(int i=0;i<e;i++){
        int v1,v2;
        cin>>v1>>v2;
        edges[v1].push_back(v2);
    }

    if(cycle(edges,n)){
        cout<<"cycle present"<<endl;
    }
    else
        cout<<"cycle not present"<<endl;

    return 0;
}