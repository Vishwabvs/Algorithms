#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	
public:
	vector<int> depth;
	vector<int> breadth;
	Graph(int v)
	{	
		V = v;
		adj = new list<int>[V];
		depth.clear();
		breadth.clear();
	}
	void addEdge(int src,int dest)
	{
		adj[src].push_back(dest);
	}
	void dfs_visit(int src, bool* visited)
	{
		depth.push_back(src);
		visited[src] = true;
		list<int> temp = adj[src];
		//cout<<"hi"<<endl;
		list<int>::iterator i;
		for(i = temp.begin();i!=temp.end();i++)
		{
			if(!visited[*i])
				dfs_visit(*i, visited);
		}
	}

	void dfs(int src)
	{
		bool* visited = new bool[V];
		for(int i=0;i<V;i++)
			visited[i] = false;
		dfs_visit(src, visited);

		//for handling disconnected graphs
		for (int i = 0; i < V; i++) 
        	if (visited[i] == false) 
            	dfs_visit(i, visited);

	}

	void bfs(int src)
	{
		bool *visited = new bool[V];
		for(int i=0;i<V;i++)
			visited[i] = false;
		visited[src] = true;


		list<int> queue;
		queue.push_back(src);

		while(!queue.empty())
		{
			int temp = queue.front();
			breadth.push_back(temp);
			queue.pop_front();

			list<int> vec = adj[temp];

			list<int>::iterator i;
			for(i = vec.begin();i!=vec.end();i++)
			{
				if(!visited[*i])
				{
					visited[*i] = true;
					queue.push_back(*i);
				}
			}
		}
	}
	
};

int main()
{
	Graph g(4);
	g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    g.dfs(2);
    for(int x: g.depth)
    	cout<<x<<" ";
    cout<<endl;	

    g.bfs(2);
    for(int x:g.breadth)
    	cout<<x<<" ";
    cout<<endl;
	return 0;
}