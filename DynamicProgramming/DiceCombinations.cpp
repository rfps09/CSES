#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 1e6+5;
const int MOD = 1e9+7;

//o código simplismente não funfa se o vetor estiver dentro da main.
// não sei a relação com a alocação de memória.
ll dp[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;

    cin >> n;

    dp[0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=min(i,6); j++) {
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }

    cout << dp[n] << "\n";

    return 0;
}