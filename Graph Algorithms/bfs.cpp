// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) 
{
    vector<int> result;
    bool *visited = new bool[N];
    
    for(int i=0;i<N;i++)
        visited[i] = false;
    
    /*for(int i=0;i<N;i++)
    {
        for(int x:g[i])
            cout<<x<<" ";
        cout<<endl;
    }*/
    
    
    
    
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int temp = q.front();
        result.push_back(temp);
        q.pop();
        for(auto i = g[temp].begin();i!=g[temp].end();i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
    
    
    return result;
}