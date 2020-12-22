class Solution {
public:
    bool isValid(int x,int y ,int n,int m){
        return (x>=0 && y>=0 && x<n && y<m);
    }
    //bfs 
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>> q;
        int m = image[0].size();//col
        int n = image.size(); //rows
        vector<vector<int>> visited(n,vector<int> (m,0));
        q.push(make_pair(sr,sc));
        visited[sr][sc] = 1;
        int current_color = image[sr][sc];
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            image[x][y] = newColor;
                for(int k=0;k<4;k++){
                    int X = x + dx[k];
                    int Y = y + dy[k];
                        if(isValid(X,Y,n,m) && image[X][Y] == current_color && !visited[X][Y]){
                            visited[X][Y] = 1;
                            q.push(make_pair(X,Y));
                        }
                }
        }
    return image;
    }
};