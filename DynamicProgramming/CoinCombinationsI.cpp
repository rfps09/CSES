#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll modInverse(ll A, ll M) {
    if (M == 1) return 0;
    ll m0 = M;
    ll y = 0, x = 1;

    while (A > 1) {
        ll q = A / M;
        ll t = M;
        M = A % M;
        A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
 
    return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n,x;

    cin >> n >> x;

    int coins[n];

    for(int i=0; i<n; i++) 
        cin >> coins[i];

    vector<ll> dp(x+1,0);

    dp[0] = 1;
    ll twoInvMod = modInverse(2,MOD);

    for(int i=1; i<=x; i++) {
        for(int j=0; j<n; j++) {
            if(i >= coins[j]) {
                dp[i] += dp[i-coins[j]];
                dp[i] *= twoInvMod;
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[x] << "\n";

    return 0;
}