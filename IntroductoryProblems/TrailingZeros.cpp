#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    int ans = 0;

    cin >> n;

    while(n > 1) {
        n/=5;
        ans += n;
    }
    
    cout << ans << '\n';

    return 0;
}