#include<bits/stdc++.h>
using namespace std;
bool visited[1000010];

class Graph{
	int n; // no. of vertices
	list<int> *adj;
	bool visited[100];

public:
	void initGraph(int n){
		this->n = n;
		adj = new list<int>[n+1];
	}

	void addEdge(int v, int w){
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	void DFS(int n, bool* visited){
		// cout<<" ->"<<n;
		visited[n] = true;
		list<int>::iterator it;
		for(it = adj[n].begin(); it!= adj[n].end(); ++it){
			if(!visited[*it]){
				DFS(*it, visited);
			}
		}
	}

};

int main(){
	int t;
	cin>>t;
	Graph obj[t];

	while(t--){
		int n,e;
		cin>>n;
		memset(visited, false, n);

		obj[t].initGraph(n);
		cin>>e;
		int a,b;
		for(int i = 0;i<e;++i){
			scanf("%d %d",&a, &b);
			obj[t].addEdge(a,b);
		}
		int count = 0;
		for(int i=0;i<n;++i){
			if(!visited[i]){
				++count;
				obj[t].DFS(i,visited);
			}
		}
		printf("%d\n",count );

	}
}