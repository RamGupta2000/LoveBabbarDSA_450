#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool safe(int n, vector<vector<int>> &vis, int i, int j, vector<vector<int>> &m)
    {
        if ((i >= 0 && i < n) && (j >= 0 && j < n) && (vis[i][j] == 0) && (m[i][j] == 1))
            return true;
        return false;
    }
    void solve(vector<vector<int>> &m, vector<string> &ans, int x, int y, string path, vector<vector<int>> &vis, int n)
    {
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }
        vis[x][y] = 1;

        int i, j;

        // down
        i = x + 1;
        j = y;

        if (safe(n, vis, i, j, m))
        {
            path.push_back('D');
            solve(m, ans, i, j, path, vis, n);
            path.pop_back();
        }

        // up
        i = x - 1;
        j = y;

        if (safe(n, vis, i, j, m))
        {
            path.push_back('U');
            solve(m, ans, i, j, path, vis, n);
            path.pop_back();
        }

        // Left
        i = x;
        j = y - 1;

        if (safe(n, vis, i, j, m))
        {
            path.push_back('L');
            solve(m, ans, i, j, path, vis, n);
            path.pop_back();
        }

        // Right
        i = x;
        j = y + 1;

        if (safe(n, vis, i, j, m))
        {
            path.push_back('R');
            solve(m, ans, i, j, path, vis, n);
            path.pop_back();
        }
        vis[x][y] = 0;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        if (m[0][0] == 0)
            return ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        solve(m, ans, 0, 0, "", vis, n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}