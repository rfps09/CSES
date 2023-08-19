#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<ll> numbers(n);

    for(int i=0; i<n; i++) {
        cin >> numbers[i];
    }

    ll ans = -2e9;
    ll sum = -2e9;

    for(int i=0; i<n; i++) {
        if(sum + numbers[i] < numbers[i]) {
            sum = numbers[i];
        }
        else {
            sum += numbers[i];
        }
        ans = max(ans,sum);
    }

    cout << ans << "\n";

    return 0;
}