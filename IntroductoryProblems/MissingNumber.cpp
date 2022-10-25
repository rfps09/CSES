#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll n, number;

    cin >> n;

    ll total = n*(n+1)/2;

    for(int i=1;i<n;i++) {
        cin >> number;
        total -= number;
    }

    cout << total << "\n";
    
    return 0;
}