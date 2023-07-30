#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    
    cin >> n;

    vector<int> in(n);
    vector<int> out(n);

    for(int i=0; i<n; i++) {
        cin >> in[i] >> out[i];
    }

    sort(in.begin(),in.end());
    sort(out.begin(), out.end());

    int ans = 0;
    int in_idx=0, out_idx=0;
    int n_customers=0;

    while(in_idx < n && out_idx < n) {
        if(in[in_idx] < out[out_idx]) {
            n_customers++;
            in_idx++;
        }
        else if(out[out_idx] < in[in_idx]) {
            n_customers--;
            out_idx++;
        }
        else {
            in_idx++;
            out_idx++;
        }
        ans = max(ans, n_customers);
    }

    cout << ans << "\n";

    return 0;
}