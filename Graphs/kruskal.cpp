//graph should be undirected and connected
//it finds mst of an undirected graph
//mst has all n vertices and n-1 edges
//used union found algo for detecting cycles
#include<bits/stdc++.h>
using namespace std;

class edge{
public:
	int weight;
	int src;
	int dest;
};

int findParent(int* parent,int vertice){
	while(parent[vertice] != vertice)
		vertice = parent[vertice];

	return vertice;
}

bool mycompare(edge e1,edge e2){
	return e1.weight < e2.weight;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 

	vector<edge> edges;//vector of edges(of size e)
	int n,e;//no of vertices,no of edges
	cin>>n>>e;

	//input edges with weights
	for(int i=0;i<e;i++){
		int v1,v2,w;
		cin>>v1>>v2>>w;
		edge e;
		e.weight = w;
		e.src = v1;
		e.dest = v2;
		edges.push_back(e);
	}

	//sort according to the weights in ascending order
	sort(edges.begin(),edges.end(),mycompare);

	//parent matrix + initialization(it doesn't store the parents, to be precise, but we can reach the parent using this array)
	int* parent = new int[n];
	for(int i=0;i<n;i++)
		parent[i] = i;

	//for storing output(or we could just keep printing it)
	vector<edge> result;
	//select n-1 edges
	int i=0;//iterator
	int count = 0;
	while(count < n-1 && i<edges.size()){
		edge e = edges[i];
		int v1,v2;
		v1 = e.src;
		v2 = e.dest;
		int parent1 = findParent(parent,v1);
		int parent2 = findParent(parent,v2);

		//both vertices belong to separate components,then we can take this edge in our output otherwise cycle form hogi
		if(parent1 != parent2)
		{
			result.push_back(e);
			parent[parent1] = parent2;
			count++;
		}

		i++;
	}

	cout<<endl;
	//print result 
	for(auto i=result.begin();i!=result.end();i++){
		if(i->src>i->dest){
			cout<<i->dest<<" "<<i->src<<" "<<i->weight<<endl;
		}
		else{
		cout<<i->src<<" "<<i->dest<<" "<<i->weight<<endl;
		}
	}
	return 0;
}