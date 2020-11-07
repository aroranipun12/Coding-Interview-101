#include <bits/stdc++.h>
using namespace std;

void pathDFS(int** edges, int n, int sv, int ev, bool* visited, vector<int>& v) {
   
    
    //returns the vector as soon as the ev is found in a path
    if(sv == ev){
        v.push_back(ev);
        visited[ev]=1;
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
            cout << v[i] << " ";
    return;
    }
    
    visited[sv] = true;
    v.push_back(sv);
    
    for(int i = 0; i < n; i++) {
        if(i == sv)
            continue;
        if(edges[sv ][i] == 1 && !visited[i]){
            pathDFS(edges, n, i, ev, visited, v); 
        }
    }
return;
}

void DFS(int** edges, int n, int sv, int ev) {
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++)
        visited[i] = false;
    
    vector<int> v;
    pathDFS(edges, n, sv, ev, visited, v);
   /* if(v[v.size()-1] != ev)
        return;
   */ 
   /* for(int i=0;i<v.size();i++)
        cout << v[i] << " ";
    cout << "\n";*/
    
    delete[] visited;
}

int main() {
    int V, E, a, b, sv, ev;
    cin >> V >> E;
    
    int** edges = new int*[V];
    for(int i = 0; i < V; i++) {
        edges[i] = new int[V];
        for(int j = 0; j < V; j++) {
            edges[i][j] = 0;
        }
    }
    
    for(int i = 0; i < E; i++) {
        cin >> a >> b;
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    cin >> sv >> ev;
    
    DFS(edges, V, sv, ev);
    
    for(int i = 0; i < V; i++)
        delete[] edges[i];
    delete[] edges;
    return 0;
}