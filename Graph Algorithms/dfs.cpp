// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
bool visited[10001];
vector<int> result;
void dfsvisit(vector<int> g[], int src)
{
    result.push_back(src);
    visited[src] = true;
    vector<int> temp = g[src];
    for(int i=0;i<temp.size();i++)
    {
        if(visited[temp[i]]==false)
            dfsvisit(g, temp[i]);
    }
}



vector <int> dfs(vector<int> g[], int N)
{
    result.clear();
    int src = 0;
    for(int i=0;i<N;i++)
        visited[i] = false;
    result.push_back(0);
    visited[0] = true;
    for(int i=0;i<N;i++)
    {
        vector<int> temp = g[i];
        for(int j=0;j<temp.size();j++)
        {
            if(visited[temp[j]]==false)
                dfsvisit(g,temp[j]);
        }
    }
    return result;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends
