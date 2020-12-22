#include<bits/stdc++.h>
using namespace std;
int row[] = {0,0,-1,1};
int col[] = {-1,1,0,0};
string dir[] = {"L","R","U","D"};
bool isValid(int x,int y,int n){
    return(x>=0 && y>=0 && x<n && y<n);
}
void printPathUtil(vector<vector<int>> &maze,int n,vector<string> &output,int x,int y,vector<vector<int>> &visited,string str){
    if(x == n-1 && y == n-1){
        output.push_back(str);
        return;
    }

    visited[x][y] = 1;

    //explore 4 directions
    for(int k=0;k<4;k++){
        int X = x + row[k];
        int Y = y + col[k];
            if(isValid(X,Y,n) && maze[X][Y] && !visited[X][Y]){
                str += dir[k];
                printPathUtil(maze,n,output,X,Y,visited,str);
                str.pop_back();//backtracking(important to understand this step)(for other paths)(dry run)
                visited[X][Y] = 0;//backtracking(important to understand this step)(for other paths)
            }
    }
return ;
}

vector<string> printPath(vector<vector<int>>& maze,int n){
    vector<string> output;
    vector<vector<int>> visited(n,vector<int> (n,0));
    printPathUtil(maze,n,output,0,0,visited,"");
return output;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> maze(n,vector<int> (n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>maze[i][j];
    }

    vector<string> ans = printPath(maze,n);

    for(auto itr = ans.begin();itr != ans.end();itr++){
        cout<<*itr<<endl;
    }

    return 0;
}