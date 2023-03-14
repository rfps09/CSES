#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n,x;
    
    cin >> n >> x;

    int coins[n];
    vector<int> dp(x+1,INF);

    for(int i=0; i<n;i++)
        cin >> coins[i];

    dp[0] = 0;

    for(int i=1; i<=x; i++) {
        for(int j=0; j<n; j++) {
            if(i >= coins[j]) {
                dp[i] = min(dp[i],dp[i-coins[j]] + 1);
            }
        }
    }

    cout << (dp[x] == INF ? -1 : dp[x]) << "\n";

    return 0;
}