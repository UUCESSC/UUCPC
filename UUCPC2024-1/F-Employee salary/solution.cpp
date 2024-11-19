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

    auto binarySearch = [&](const ll val){
        ll l{}, r{n - 1}, idx{n};
        while(l <= r){
            ll mid{(l + r) / 2};
            if(salary[mid] > val){
                idx = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return idx;
    };

    while(q--){
        ll curr{};
        cin >> curr;

        ll idx{binarySearch(curr) - 1};
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
