#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(vector<vector<int>> &image, vector<vector<int>> &vis, int x, int y, int n, int m, int src)
    {
        if (x < 0 || x >= n || y < 0 || y >= m || image[x][y] != src || vis[x][y] == 1)
            return false;
        return true;
    }
    void solve(vector<vector<int>> &image, vector<vector<int>> &vis, int x, int y, int newColor, int n, int m, int src)
    {
        if (x == n && y == m)
            return;

        vis[x][y] = 1;
        image[x][y] = newColor;

        // UP
        int newx = x - 1;
        int newy = y;
        if (isSafe(image, vis, newx, newy, n, m, src))
            solve(image, vis, newx, newy, newColor, n, m, src);

        // down
        newx = x + 1;
        newy = y;
        if (isSafe(image, vis, newx, newy, n, m, src))
            solve(image, vis, newx, newy, newColor, n, m, src);

        // left
        newx = x;
        newy = y - 1;
        if (isSafe(image, vis, newx, newy, n, m, src))
            solve(image, vis, newx, newy, newColor, n, m, src);

        // right
        newx = x;
        newy = y + 1;
        if (isSafe(image, vis, newx, newy, n, m, src))
            solve(image, vis, newx, newy, newColor, n, m, src);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));

        int src = image[sr][sc];
        image[sr][sc] = newColor;
        solve(image, vis, sr, sc, newColor, n, m, src);
        return image;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
