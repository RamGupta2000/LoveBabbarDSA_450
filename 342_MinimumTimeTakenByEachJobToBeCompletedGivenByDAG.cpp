
#include <bits/stdc++.h>
using namespace std;
#define maxN 100000

vector<int> adj[maxN];
int indegree[maxN];
int job[maxN];

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    indegree[v]++;
}

void printOrder(int n, int m)
{
    // vector<int> job;
    // int timer = 1;

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            job[i] = 1;
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                job[it] = job[node] + 1;
                q.push(it);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << job[i] << " ";
    }
    // 1 1 2 2 2 3 4 5 2 6
}

int main()
{
    int n, m;
    n = 10;
    m = 13;

    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);

    printOrder(n, m);
    return 0;
}
