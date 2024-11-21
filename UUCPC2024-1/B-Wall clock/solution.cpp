#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define long long int;

using namespace std;


void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(b < a) swap(a, b);
    if(d < c) swap(c, d);
    
    if ((c <= a and d <= a) or (c >= b and d >= b) or (c <= a and d >= b) or (c >= a and d <= b)) {
        cout << "NO\n";
    } else cout << "YES\n";
}

int main(){
    IO
    

    int tc = 1;
    // cin >> tc;
    while(tc--) solve();

    return 0;
}
