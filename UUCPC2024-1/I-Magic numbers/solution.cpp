#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr), cout.tie(nullptr);
#define all(n) n.begin(), n.end()
#define LSOne(n) (n & (-n))

using namespace std;

typedef long long ll;

const ll N{18}, BASE{10}, M{BASE / 2 - 1};

ll n{};
string _l{},
       _r{};

ll memo[N + 1][2][2][2][3][5][7][9][1 << M]{};
ll dp(const ll i, const bool cZ, const bool l, const bool h, const vector<ll>& mod, const ll mask){
    // Base case:
    if(i == n){
        ll now{mask};
        while(now){
            if(mod[__builtin_ctzll(now)] == 0) return 0;

            now ^= LSOne(now);
        }

        return 1;
    }
    
    // Recursive case:
    ll& ans{memo[i][cZ][l][h]
            [mod[0]][mod[1]][mod[2]][mod[3]][mask]};
    if(~ans) return ans;

    ans = 0;
    ll low{l? _l[i] - '0': 0},
       up{h? _r[i] - '0': 9};
    for(ll d{low}; d <= up; ++d){
        if(cZ and d == 0){
            ans += dp(i + 1,
                    true,
                    l and (d == low),
                    h and (d == up),
                    mod,
                    mask);
        }
        else if(d != 1 and d & 1){
            vector<ll> nMod = mod;
            for(ll m{3}; m < BASE; m += 2){
                ll idx{m / 2 - 1};
                nMod[idx] = (BASE * nMod[idx] + d) % m;
            }

            ans += dp(i + 1,
                    false,
                    l and (d == low),
                    h and (d == up),
                    nMod,
                    mask | (1 << (d / 2 - 1)));
        }
    }

    return ans;
}

ll _ans{};
ll trace(const ll i, const bool cZ, const bool l, const bool h, const vector<ll>& mod, const ll mask, ll k){
    // Base case:
    if(i == n) return _ans;
    
    // Recursive case:
    ll low{l? _l[i] - '0': 0},
       up{h? _r[i] - '0': 9};
    for(ll d{low}; d <= up; ++d){
        if(cZ and d == 0){
            ll cnt{dp(i + 1,
                    true,
                    l and (d == low),
                    h and (d == up),
                    mod,
                    mask)};

            if(k > cnt) k -= cnt;
            else return trace(i + 1,
                            true,
                            l and (d == low),
                            h and (d == up),
                            mod,
                            mask,
                            k);
        }
        else if(d != 1 and d & 1){
            vector<ll> nMod = mod;
            for(ll m{3}; m < BASE; m += 2){
                ll idx{m / 2 - 1};
                nMod[idx] = (BASE * nMod[idx] + d) % m;
            }

            ll cnt{dp(i + 1,
                    false,
                    l and (d == low),
                    h and (d == up),
                    nMod,
                    mask | (1 << (d / 2 - 1)))};

            if(k > cnt) k -= cnt;
            else{
                _ans = BASE * _ans + d;
                return trace(i + 1,
                            false,
                            l and (d == low),
                            h and (d == up),
                            nMod,
                            mask | (1 << (d / 2 - 1)),
                            k);
            }
        }
    }

    return _ans = -1;
}

ll dp(const ll l, const ll r, const ll k){
    _l = to_string(l);
    _r = to_string(r);
    n = (ll)_r.size();

    reverse(all(_l));
    while(_l.size() < _r.size()) _l += '0';
    reverse(all(_l));

    memset(memo, -1, sizeof memo);
    dp(0, true, true, true, vector<ll>(M, 0), 0);

    _ans = 0;
    return trace(0, true, true, true, vector<ll>(M, 0), 0, k);
}

void solve(){
    ll l{}, r{}, k{};
    cin >> l >> r >> k;

    cout << dp(l, r, k) << '\n';
}

int main(){
    IO

    ll tc{1ll};
    cin >> tc;
    while(tc--) solve();

    return 0;
}
