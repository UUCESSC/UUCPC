#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;

int const N = 2;

void solve()
{
    ll h[N]{}, d[N]{}, t[N]{};
    for (ll i{}; i < N; ++i)
        cin >> h[i] >> d[i] >> t[i];

    ll curr{};
    h[0] -= d[1], h[1] -= d[0];
    while (h[0] > 0 and h[1] > 0)
    {
        ll l{(curr / t[0]) + 1},
            r{curr / t[1] + 1};

        l *= t[0], r *= t[1];
        curr = min(l, r);
        if (curr == l)
            h[1] -= d[0];
        if (curr == r)
            h[0] -= d[1];
    }

    if (h[0] <= 0 and h[1] <= 0)
        cout << "Draw" << '\n';
    else if (h[1] <= 0)
        cout << "Qmarth" << '\n';
    else
        cout << "Mmd" << '\n';
}

int main()
{
    IO

    ll tc{1ll};
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
