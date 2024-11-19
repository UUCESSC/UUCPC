#include <bits/stdc++.h>
using namespace std;

int const N = 1e3 + 5;
bool vis[N][N];
string arr[N];
int n;

int pos[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

void dfs(int x, int y)
{
    vis[x][y] = true;

    for (auto nei : pos)
    {
        int xx = x + nei[0], yy = y + nei[1];

        if (0 <= xx && xx < n && 0 <= yy && yy < n && arr[xx][yy] == '#' && !vis[xx][yy])
            dfs(xx, yy);
    }
}

void solve()
{
    int count{};
    memset(vis, false, sizeof vis);
    cin >> n;

    for (int i{}; i < n; ++i)
        cin >> arr[i];

    for (int i{}; i < n; ++i)
    {
        for (int j{}; j < n; ++j)
        {
            if (arr[i][j] == '#' && !vis[i][j])
            {
                count++;
                dfs(i, j);
            }
        }
    }

    cout << count;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
}