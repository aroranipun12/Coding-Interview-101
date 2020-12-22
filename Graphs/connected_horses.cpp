//Question -> Connected horses
/*You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7
Input:
First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
SAMPLE OUTPUT
4
2*/


#include <bits/stdc++.h>
using namespace std;

#define p int(1e9+7)
int matrix[1001][1001],n,m,q;
#define ll long long int

bool isValid(int i,int j){
	return (i>=1 && j>=1 && i<=n && j<=m);
}

ll dfs(int i,int j){
	ll ans = 1;
	matrix[i][j] = 2;//to prevent infinite recursion(coming back to this cell) , otherwise use visited array which is just not feasible in this case

	int row[] = {-1,1,2,2,-1,1,-2,-2};
	int col[] = {2,2,-1,1,-2,-2,-1,1};
	//explore 8 directions
	for(int k=0;k<8;k++){
		int X = i+row[k];
		int Y = j+col[k];
		if(isValid(X,Y) && matrix[X][Y]==1)
			ans+=dfs(X,Y);
	}
return ans;
}

ll fact(int num){
	ll ans = 1;

	for(ll i=num; i>=1;i--){
		ans = (ans*i) % p;
	}
return ans;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>q;
		//init matrix
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				matrix[i][j] = 0;
		//input
		for(int i=0;i<q;i++){
			int x,y;
			cin>>x>>y;
			matrix[x][y] = 1;
		}

		ll ans = 1,num_vertices_in_component;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(matrix[i][j]==1){
					num_vertices_in_component = dfs(i,j);
					ans =  (ans * fact(num_vertices_in_component)) % p;
				}
			}
		}
	cout<<ans<<endl;
	}
	return 0;
}