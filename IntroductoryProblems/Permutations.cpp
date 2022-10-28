#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n,number=1;

    cin >> n;

    if(n == 1) {
        cout << n << "\n";
        return 0;
    }

    if(n <= 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    int i=2,j=1;
    while(i <= n) {
        cout << i << " ";
        i+=2;
    }
    while(j <= n) {
        cout << j << " ";
        j+=2;
    }

    cout << "\n";
    
    return 0;
}