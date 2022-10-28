#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll n,num1,num2;

    cin >> n;

    cin >> num1;

    ll ans = 0;

    for(int i=1; i<n; i++) {
        cin >> num2;
        ll diff = num2-num1;
        ans += diff < 0 ? abs(diff) : 0;
        if(diff>0)num1 = num2;
    }

    cout << ans << "\n";
    
    return 0;
}