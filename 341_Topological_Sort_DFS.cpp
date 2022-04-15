
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &ans, vector<int> &vis, vector<int> adj[], int i, stack<int> &s)
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
                solve(ans, vis, adj, it, s);
        }
        s.push(i);
    }
    vector<int> topoSort(int v, vector<int> adj[])
    {
        vector<int> ans;
        vector<int> vis(v, 0);

        stack<int> s;
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
                solve(ans, vis, adj, i, s);
        }
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}