#include<bits/stdc++.h>
using namespace std;

void getPathdfs_helper(int** edges,int n,int s,int e,bool* visited,vector<int> &path)
{
	if(s==e)
	{
		path.push_back(s);
		return;
	}
	path.push_back(s);

		for(int i=0;i<n;i++)
		{
			if(edges[s][i] && !visited[i])
			{
				visited[i] = true;
				getPathdfs_helper(edges,n,i,e,visited,path);
			}
		}

}

void getPathdfs(int** edges,int n,int s,int e)  //dfs path
{
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
		visited[i] = false;

	vector<int> path;
	visited[s] = 1;
	getPathdfs_helper(edges,n,s,e,visited,path);

	for(int i=0;i<path.size();i++)
	{
		cout<<path[i]<<"-";
	}
	cout<<endl;

return;
}

void hasPath_helper(int** edges,int n,int s,int e,bool* visited)//s and e are starting and ending vertices
{
	if(visited[e])  //jese hi end visited hogya ab hume aur kaam krne ki jarurat nahi h
		return;

	for(int i=0;i<n;i++)
	{
		if(i==s)
			continue;

		if(edges[s][i] && !visited[i])
		{
			visited[i] = true;
			hasPath_helper(edges,n,i,e,visited);
		}
	}
return;
}

bool hasPath(int**edges,int n,int s,int e)
{
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
		visited[i] = false;

	for(int i=0;i<n;i++)
	{
		if(!visited[i])
			hasPath_helper(edges,n,s,e,visited);
	}

return visited[e];
}



void print_bfs(int** edges,int n,int sv)
{
	int* visited = new int[n];
	for(int i=0;i<n;i++)
		visited[i] = 0;

	queue<int> q;
	q.push(sv);
	visited[sv]=1;

		while(!q.empty())
		{
			int curr_vertex = q.front();
			cout<<curr_vertex;
			q.pop();
				for(int i=0;i<n;i++)
				{
					if(curr_vertex == i)
						continue;
					if(edges[curr_vertex][i] && !visited[i])
					{
							q.push(i);
							visited[i] = 1;
					}
				}

		}

}

void print_dfs(int** edges,int n,int sv,int* visited)
{
	cout<<sv;
	visited[sv] = 1;
	for(int i=0;i<n;i++)
	{
		if(sv == i)
			continue;
		if(edges[sv][i])
		{
			if(!visited[i])
				print_dfs(edges,n,i,visited);
		}
	}
}

int main()
{
	int n,e;
	cin>>n>>e;
	int** edges = new int*[n];
		for(int i=0;i<n;i++)
			{
				edges[i] = new int[n];
					for(int j=0;j<n;j++)
						edges[i][j] = 0;
			}
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}	
	//print matrix
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<edges[i][j]<<" ";
		cout<<endl;
	}
	*/

	cout<<endl;
	
	/*int* visited = new int[n];
	for(int i=0;i<n;i++)
		visited[i] = 0;
*/
/*	//print_dfs(edges,n,0,visited);  // 0 is the starting vertex
	print_bfs(edges,n,0);
*/	
	/*cout<<hasPath(edges,n,3,1)<<endl;*/

	getPathdfs(edges,n,0,3);

	return 1;
}