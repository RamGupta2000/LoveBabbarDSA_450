
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> adj[], vector<int> &vis, vector<int> &dfs, int i)
    {
        vis[i] = 1;
        dfs.push_back(i);
        for (auto it : adj[i])
        {
            if (!vis[it])
                solve(adj, vis, dfs, it);
        }
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[])
    {
        vector<int> dfs;
        vector<int> vis(v, 0);

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
                solve(adj, vis, dfs, i);
        }
        return dfs;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}