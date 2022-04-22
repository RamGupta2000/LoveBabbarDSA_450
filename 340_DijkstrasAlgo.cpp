
#include <bits/stdc++.h>
using namespace std;

// typedef pair<int, int> pii;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
        p.push({0, S});
        vector<int> dis(V, INT_MAX);
        dis[S] = 0;
        while (!p.empty())
        {
            int node = p.top().second;
            int mindis = p.top().first;
            p.pop();

            for (auto it : adj[node])
            {
                if (dis[it[0]] > mindis + it[1])
                {
                    dis[it[0]] = mindis + it[1];
                    p.push({mindis + it[1], it[0]});
                }
            }
        }
        return dis;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}