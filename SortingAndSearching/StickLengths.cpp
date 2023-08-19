#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> numbers(n);

    for(int i=0; i<n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    ll mid = numbers[n/2];
    ll ans = 0;

    for(int i=0; i<n; i++) {
        ans += abs(mid-numbers[i]);
    }

    cout << ans << "\n";

    return 0;
}