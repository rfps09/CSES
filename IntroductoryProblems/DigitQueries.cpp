#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    ll q,k;

    cin >> q;

    while(q--) {
        cin >> k;

        ll digits = 0;
        ll algs = 0;

        while(k - digits > 0 && algs < 18) {
            k -= digits;
            algs++;
            digits = algs*(pow(10,algs)-pow(10,algs-1));
        }
        
        ll add = (k/algs) - 1;
        ll idx = (k%algs);
        string number = to_string((((ll)pow(10,algs-1)) + add + (idx > 0)));

        if(idx == 0) {
            reverse(number.begin(),number.end());
        } else idx--;

        cout << number[idx] << "\n";
    }

    return 0;
}