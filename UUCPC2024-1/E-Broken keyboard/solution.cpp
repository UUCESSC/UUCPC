#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define shuf(a) shuffle(a.begin(), a.end(), default_random_engine(0));
#define long long int
#define endl "\n"

using namespace std;

const int _MOD{(int)1e9 + 7};
int mod(const int n, const int m=_MOD){ return ((n % m) + m) % m; }

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    stack<int> lo{}, up{};
    lo.push(-1);
    up.push(-1);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') {
            if (lo.top() != -1) lo.pop();
        } else if (s[i] == 'B') {
            if (up.top() != -1) up.pop();
        } else if (s[i] >= 'a' and s[i] <= 'z') {
            lo.push(i);
        } else {
            up.push(i);
        }
    }

    stack<char> ans{};

    while (lo.top() != -1 or up.top() != -1) {
        int idx = max(lo.top(), up.top());
        if (lo.top() == idx) lo.pop();
        if (up.top() == idx) up.pop();
        ans.push(s[idx]);
    }

    while (not ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
    

}


int main() {
    fastio
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}