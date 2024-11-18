#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

typedef long long ll;

void solve(){
    ll n{};
    cin >> n;
    cout << (n & 1? "NO": "YES") << '\n';
}

int main(){
    IO

    ll tc{1ll};
    // cin >> tc;
    while(tc--) solve();

    return 0;
}
