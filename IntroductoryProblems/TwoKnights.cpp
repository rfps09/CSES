#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;

    cin >> n;

    ll ans = 0;

    for(ll i=1; i<=n; i++) {
        ans += ((i-1)*(i-1)) * (2*i-1) + (2*i-1) * (2*i-2) / 2;
        for(ll j=i-1; j > 0; j--) {
            if(i-1 > 0 && j-2 > 0) {
                ans -= 1;
            }
            if(i-2 > 0 && j-1 > 0) {
                ans -= 1;
            }
            if(i-2 > 0 && j+1 <= i) {
                ans -= 1;
            }
            if(i-1 > 0 && j+2 <= i) {
                ans -= 1;
            }



            if(j-2 > 0 && i-1 > 0) {
                ans -=1;
            }

            if(j-1 > 0 && i-2 > 0) {
                ans -=1;
            }

            if(j+1 <= i && i-2 > 0) {
                ans -=1;
            }

            if(j+2 <= i && i-1 > 0) {
                ans -=1;
            }
        }

        if(i - 2 > 0) {
            ans -= 2;
        }

        if(i >= 3) ans +=2;

        cout << ans << endl;
    }

    return 0;
}