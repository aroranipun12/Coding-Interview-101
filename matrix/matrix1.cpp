#include<bits/stdc++.h>
using namespace std;

void spiral_traversal(int** matrix,int row ,int col)
{
	int start_row = 0;
	int start_col = 0;
	int i;

	while(start_row < row && start_col < col){
		//1st row ->
		for( i=start_col;i<col;++i){
			cout<<matrix[start_row][i]<<" ";
		}
		start_row++;

		//last col
		for( i=start_row;i<row;++i){
			cout<<matrix[i][col-1]<<" ";
		}
		col--;

		//last row <-
		if(start_row < row){
			for(i=col-1;i>=start_col;--i){
				cout<<matrix[row-1][i]<<" ";
			}
			row--;
		}
		//1st col
		if(start_col < col){
			for(i=row-1;i>=start_row;--i){
				cout<<matrix[i][start_col]<<" ";
			}
			start_col++;
		}
	}
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 

	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m>>n;
		//2d matrix
		int** matrix = new int*[m];
		for(int i=0;i<m;i++){
			matrix[i] = new int[n];
			for(int j=0;j<n;j++)
				cin>>matrix[i][j];
		}

		spiral_traversal(matrix,m,n);
		cout<<endl;
	}
	
	return 0;
}