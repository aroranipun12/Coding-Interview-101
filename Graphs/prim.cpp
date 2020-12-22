#include<bits/stdc++.h>
using namespace std;

int findMinVertex(int* weight,int* visited,int size){
    int minWeight = INT_MAX;
    int minVertex = -1;
    for(int i=0;i<size;i++){
        //unvisited and min weight vertex
        if(visited[i]==0 && (minVertex == -1 || weight[i] < minWeight)){
            minWeight = weight[i];
            minVertex = i;
        }
    }
    return minVertex;
}

int main( int argc , char ** argv )
{
    ios_base::sync_with_stdio(false) ; 
    cin.tie(NULL) ; 

    int n,e;//number of vertices,edges
    cin>>n>>e;

    //n*n adjacency matrix for input
    int** matrix = new int*[n];
    for(int i=0;i<n;i++){
        matrix[i] = new int[n];
        for(int j=0;j<n;j++){
            matrix[i][j] = 0;//all cells initialized with zero
        }
    }

    //take input(e is number of edges)
    for(int i=0;i<e;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        matrix[v1][v2]=matrix[v2][v1]=w;
    }

    int* parent = new int[n];//isme output hoga starting from index 1 to n-1
    int* weight = new int[n];//weights of output edges
    int* visited = new int[n];
    for(int i=0;i<n;i++){
        weight[i] = INT_MAX;
        visited[i] = 0;
    }
    parent[0] = -1;
    weight[0] = 0;

    //main kaam
    for(int i=0;i<n;i++){
        //find unvisited  vertex with min weight
            int curr_vertex = findMinVertex(weight,visited,n); 
            visited[curr_vertex] = 1;
            //check for adjacent unvisited vertices and weight and parent matrix accordingly
            for(int j=0;j<n;j++){
                //finding adjacent vertices which are not visited
                if(matrix[curr_vertex][j]>0 && visited[j]==0){
                    //if current weight is bigger then update both weight and parent
                    if(weight[j] > matrix[curr_vertex][j]){
                        weight[j] = matrix[curr_vertex][j];
                        parent[j] = curr_vertex;
                    }
                }
            }
    }

  //  cout<<endl;
    //output
    for(int i = 1; i < n; i++){
        int ei = i;
        int ej = parent[i];
        int w = weight[i];
        if(ei < ej) cout << ei << " " << ej << " " << w << endl;
        else cout << ej << " " << ei << " " << w << endl;
    }
    return 0;
}