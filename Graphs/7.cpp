#include<bits/stdc++.h>
using namespace std;
//dfs and bfs are very important
class cell{
public:
    int x;
    int y;
    int distance;//distance from the start position(steps)

    cell(int a,int b,int c){
        x = a;
        y = b;
        distance = c;
    }
};

bool isValid(int x,int y,int n){
    return (x>=1 && y>=1 && x<=n && y<=n);
}
//bfs
int minStepToReachTarget(int knightPos[],int targetPos[],int n){
    queue<cell> q;
    int xStart = knightPos[0];
    int yStart = knightPos[1];
    int xEnd = targetPos[0];
    int yEnd = targetPos[1];

    int visited[n+1][n+1] = {0};
    //memset(visited,0,sizeof(visited));
    q.push(cell(xStart,yStart,0));//starting state ko push krdia queue ke andar
    visited[xStart][yStart] = 1;
    //8 directions
    int dx[] = {-1,1,2,2,-1,1,-2,-2};
    int dy[] = {2,2,1,-1,-2,-2,-1,1};

    //explore all 8 steps

    while(!q.empty()){
        cell t = q.front();
        q.pop();

        if(t.x == xEnd && t.y == yEnd){
            return t.distance;
        }    

        //otherwise explore all 8 directions 
        for(int k=0;k<8;k++){
            int newX = t.x+dx[k];
            int newY = t.y+dy[k];
            if(isValid(newX,newY,n) && !visited[newX][newY]){
                visited[newX][newY] = 1;
                q.push(cell(newX,newY,t.distance + 1));
            }
        }
    }
return -1;
}


//indexing from 1 to n
int main()
{
    int n = 30;//size of the board
    int knightPos[] = { 1, 1 };
    int targetPos[] = { 30, 30 };
    cout << minStepToReachTarget(knightPos, targetPos, n);
    return 0;
}