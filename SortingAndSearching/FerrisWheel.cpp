#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n,x;

    cin >> n >> x;

    vector<int> weights(n);

    for(int i=0; i<n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int ans = 0;
    int start = 0;
    int end = weights.size()-1;

    while(start<=end) {
        if(weights[start] + weights[end] <= x) {
            ans++;
            start++;
            end--;
        }
        else {
            ans++;
            end--;
        }
    }
 
    cout << ans << "\n";

    return 0;
}