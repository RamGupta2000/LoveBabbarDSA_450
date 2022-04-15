
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detectCycle(int i, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis)
    {
        vis[i] = 1;
        dfsvis[i] = 1;

        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                if (detectCycle(it, adj, vis, dfsvis))
                    return true;
            }
            else if (dfsvis[it])
                return true;
        }
        dfsvis[i] = 0;

        return false;
    }
    bool isCyclic(int v, vector<int> adj[])
    {
        vector<int> vis(v, 0);
        vector<int> dfsvis(v, 0);

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
                if (detectCycle(i, adj, vis, dfsvis))
                    return true;
        }
        return false;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
