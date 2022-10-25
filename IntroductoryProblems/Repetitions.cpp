#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string DNA;

    cin >> DNA;

    int ans = 1;
    int count = 1;

    for(int i=0; i<DNA.length()-1; i++) {
        if(DNA[i] == DNA[i+1]) {
            count++;
            ans = max(ans,count);
        } else count = 1;
    }

    cout << ans << "\n";
    
    return 0;
}