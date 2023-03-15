#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n,x;

    cin >> n >> x;

    int coins[n];

    for(int i=0; i<n; i++)
        cin >> coins[i];

    vector<int> dp(x+1,0);

    dp[0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=1; j<=x; j++) {
            if(j >= coins[i]) {
                dp[j] += dp[j-coins[i]];
                dp[j] %= MOD;
            }
        }
    }

    cout << dp[x] << "\n";

    return 0;
}