#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detectCycle(vector<int> &vis, vector<int> adj[], int i, queue<pair<int, int>> q)
    {
        vis[i] = 1;
        q.push({i, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    q.push({it, node});
                    vis[it] = 1;
                }
                else if (vis[it] && parent != it)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[])
    {
        vector<int> vis(v, 0);
        queue<pair<int, int>> q;
        q.push({0, -1});
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (detectCycle(vis, adj, i, q))
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