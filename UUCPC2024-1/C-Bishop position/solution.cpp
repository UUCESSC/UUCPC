#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
typedef long long ll;

const ll N{8};

void solve()
{
    bool table[N][N]{};
    for (ll i{}; i < N; ++i)
    {
        for (ll j{}; j < N; ++j)
        {
            char curr{};
            cin >> curr;
            table[i][j] = curr == '*';
        }
    }

    pair<ll, ll> f{-1, -1}, s{-1, -1};

    auto check = [&](const ll i, const ll j)
    {
        bool valid{true};
        if (i and j and not table[i - 1][j - 1])
            valid = false;
        else if (i and j != N - 1 and not table[i - 1][j + 1])
            valid = false;
        else if (i != N - 1 and j and not table[i + 1][j - 1])
            valid = false;
        else if (i != N - 1 and j != N - 1 and not table[i + 1][j + 1])
            valid = false;

        return valid;
    };

    for (ll i{}; i < N; ++i)
    {
        for (ll j{}; j < N; ++j)
        {
            if (not table[i][j])
                continue;

            if ((i == 0 or i == N - 1) and (j == 0 or j == N - 1))
            {
                if (s.first == -1)
                    s = {i + 1, j + 1};
            }
            else if (check(i, j))
                f = {i + 1, j + 1};
        }
    }

    if (~f.first)
        cout << f.first << ' ' << f.second << '\n';
    else
        cout << s.first << ' ' << s.second << '\n';
}

int main()
{
    IO

    ll tc{1ll};
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}
