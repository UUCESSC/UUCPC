#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

typedef long long ll;

const ll N{(ll)1e5};

ll salary[N]{};
string name[N]{};

void solve(){
    ll n{}, q{};
    cin >> n >> q;

    for(ll i{}; i < n; ++i) cin >> name[i] >> salary[i];

    while(q--){
        ll curr{};
        cin >> curr;

        ll idx{upper_bound(salary, salary + n, curr) - salary - 1};
        if(~idx) cout << name[idx] << ' ' << salary[idx] << '\n';
        else cout << -1 << '\n';
    }
}

int main(){
    IO

    ll tc{1ll};
    // cin >> tc;
    while(tc--) solve();

    return 0;
}
