#include<bits/stdc++.h>
using namespace std;
bool visited[1000010];

class Graph{
	int n; // no. of vertices
	list<int> *adj;

public:
	int count = 0;

	void initGraph(int n){
		this->n = n;
		adj = new list<int>[n+1];
	}

	void addEdge(int v, int w){
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	void DFS(int n, bool* visited){
		++count;
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
	int n,e;
	cin>>n>>e;
	Graph obj;
	memset(visited,false,n+1);
	obj.initGraph(n);
	if( n != e+1)
		printf("NO\n");
	else{
		int a,b;
		for(int i=0;i<e;++i){
			scanf("%d %d",&a,&b);
			obj.addEdge(a,b);
		}

		obj.DFS(1,visited);
		if(obj.count == n)
			printf("YES\n");
		else
			printf("NO\n");

	}
}