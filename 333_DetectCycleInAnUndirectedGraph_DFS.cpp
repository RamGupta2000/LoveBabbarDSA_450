#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detectCycle(vector<int> &vis, vector<int> adj[], int i, int parent)
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                if (detectCycle(vis, adj, it, i))
                    return true;
            }
            else if (parent != it)
                return true;
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[])
    {
        vector<int> vis(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (detectCycle(vis, adj, i, -1))
                    return true;
            }
        }
        return false;
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
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}