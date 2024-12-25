#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

const int N = 2e5;
 
vector<int> gr[N]{};


int g[N]{};
void dfs_g(const int curr, const int par){
    for(const auto& x: gr[curr]){
        if(x != par){
            dfs_g(x, curr);
 
            g[curr] = max(g[curr], g[x] + 1);
        }
    }
}
 
int memo[N]{};
void dfs_f(const int curr, const int  par, const int p){
    int max_1 = -1, max_2 = p;
    for(const auto& x: gr[curr]){
        if(x != par){
            if(max_2 <= g[x]) max_1 = max_2, max_2 = g[x];
            else if(max_1 < g[x]) max_1 = g[x];
        }
    }
 
    for(const auto& x: gr[curr]){
        if(x != par){
            int mx = (g[x] != max_2? max_2: max_1);
            dfs_f(x, curr, mx + 1);
        }
    }
 
    memo[curr] = max_1 + max_2 + 2;
}
 
void solve(){
    int n;
    cin >> n;
 
    for(int i = 0; i < n - 1; i++){
        int v1, v2;
        cin >> v1 >> v2;
 
        gr[--v1].push_back(--v2);
        gr[v2].push_back(v1);
    }
 
    dfs_g(0, -1);
    dfs_f(0, -1, -1);

    int ans = -1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, memo[i]);
    }
 
    cout << ans << '\n';
}
 
int main(){
    IO

    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
 
    return 0;
}