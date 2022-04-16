
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        int sx = KnightPos[0];
        int sy = KnightPos[1];
        int tx = TargetPos[0];
        int ty = TargetPos[1];

        if (sx == tx && sy == ty)
            return 0;

        int pos[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};

        vector<vector<int>> vis(N + 1, vector<int>(N + 1, 0));
        queue<pair<int, int>> q;
        q.push({sx, sy});
        vis[sx][sy] = 1;

        int ans = 0;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (x == tx && y == ty)
                    return ans;
                for (int i = 0; i < 8; i++)
                {
                    int a = x + pos[i][0];
                    int b = y + pos[i][1];
                    if ((a >= 1 && a <= N) && (b >= 1 && b <= N) && (vis[a][b] == 0))
                    {
                        q.push({a, b});
                        vis[a][b] = 1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}