#include<bits/stdc++.h>
using namespace std;

int findMinVertex(int* visited,int* distance,int size){
    int minVertex = -1;
    int minDistance = INT_MAX;
    for(int i=0;i<size;i++){
        if(!visited[i]  && (minVertex == -1 || distance[i]<minDistance)){
            minDistance = distance[i];
            minVertex = i;
        }
    }
    return minVertex;
}

int main( int argc , char ** argv )
{
    ios_base::sync_with_stdio(false) ; 
    cin.tie(NULL) ; 

    int n,e;
    cin>>n>>e;

    int** matrix = new int*[n];
    for(int i=0;i<n;i++){
        matrix[i] = new int[n];
        for(int j=0;j<n;j++){
            matrix[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        matrix[v1][v2]=matrix[v2][v1]=w;
    }
    //src is assumed to be 0th vertex
    int* distance = new int[n];
    int* visited = new int[n];
    for(int i=0;i<n;i++){
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    distance[0] = 0;//0 is source vertex

    for(int i=0;i<n;i++){
        //find vertex with min distance[i] and unvisited
        int curr_vertex = findMinVertex(visited,distance,n);
        visited[curr_vertex] = 1;
            for(int j=0;j<n;j++){
                if(matrix[curr_vertex][j] != 0 && !visited[j] ){
                    distance[j] = min(distance[j],distance[curr_vertex] + matrix[curr_vertex][j]);
                } 
            }
    }

    //print output
    for(int i=0;i<n;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }

    return 0;
}