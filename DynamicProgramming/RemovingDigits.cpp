#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> dp(n+1,INF);

    dp[0] = 0;

    for(int i=1; i<=n; i++) {
        string digits = to_string(i);

        for(int j=0; j<digits.length(); j++) {
            dp[i] = min(dp[i], dp[i-(digits[j]-48)] + 1);
        }
    }

    cout << dp[n] << "\n";

    return 0;
}