#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

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

    pll interval = {0,0};

    for(int i=0; i<n; i++) {
        if(numbers[i] - 1 <= interval.second) {
            interval.second += numbers[i];
        }
        else break;
    }

    cout << interval.second + 1 << "\n";

    return 0;
}