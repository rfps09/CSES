#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(int idx, ll valueA,ll valueB, vector<ll> &values) {
    if(idx < 0) {
        return abs(valueA-valueB);
    }

    ll ans = 0;

    ans = min(
        solve(idx-1,valueA+values[idx], valueB, values),
        solve(idx-1,valueA, valueB+values[idx], values)
    );

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<ll> vetor(n);

    for(int i=0; i<n; i++) {
        cin >> vetor[i];
    }

    cout << solve(n-1,0,0,vetor);

    return 0;
}