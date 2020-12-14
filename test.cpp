#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& edges,int n,int start,vector<int>& visited,vector<int> &component){
	visited[start] = 1;
	component.push_back(start);

	for(auto itr = edges[start].begin(); itr!=edges[start].end();itr++){
		if(!visited[*itr]){
			dfs(edges,n,*itr,visited,component);
		}
	}
}

vector<vector<int>> getComponents(vector<vector<int>> &edges,int n){

	vector<vector<int>> output;

	vector<int> visited(n,0);
	for(int i=0;i<n;i++){
		if(!visited[i]){
			vector<int> component; 
			dfs(edges,n,i,visited,component);
			output.push_back(component);
		}
	}
	return output;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		//edge list
		vector<vector<int>> edges(n);

		int m;
		cin>>m;

		int* p = new int[n];
		int* q = new int[n];
		for(int i=0;i<n;i++){
			int x;
			cin>> x;
			p[i] = x-1;
		}
		for(int i=0;i<n;i++){
			int x;
			cin>> x;
			q[i] = x-1;
 		}

		for(int i=0;i<m;i++){
			int v1,v2;
			cin>>v1>>v2;
			edges[v1-1].push_back(v2-1);
			edges[v2-1].push_back(v1-1);
		}

		vector<vector<int>> output = getComponents(edges,n);
		/*//print conn components
		for(auto itr = output.begin();itr!=output.end();itr++){
			vector<int> component = *itr;
			for(auto itr1 = component.begin();itr1!=component.end();itr1++){
				cout<<*itr1<<" ";
			}
		cout<<endl;
		}
*/
		int flag = 1;
		for(auto itr1 = output.begin();itr1!=output.end();itr1++){
			vector<int> comp = *itr1;
			//*itr1 points to each component(vector)
			//inseert every component in set and check if they are equal
			set<int> setA;
			set<int> setB;	
				for(auto itr2 = comp.begin();itr2!=comp.end();itr2++){
					//*itr2 points to the index now
					

					setA.insert(p[*itr2]);
					setB.insert(q[*itr2]);
				}
			if(setA!=setB){
				flag = 0;
				cout<<"NO";
				break;
			}
		}
		if(flag)
			cout<<"YES";

	}

	return 0;
}