#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll n=0;
    
    cin >> n;
    
    while(n^1) {
        cout << n << " ";
        if(n%2) n=n*3+1;
        else n/=2;
    } cout << "1\n";
    
    return 0;
}