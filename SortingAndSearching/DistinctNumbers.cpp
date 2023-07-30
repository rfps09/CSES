#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> numbers(n);

    for(int i=0; i<n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(),numbers.end());

    int ans = 1;

    for(int i=1; i<n; i++) {
        if(numbers[i] > numbers[i-1]) {
            ans++;
        }
    }
    
    cout << ans << "\n";

    return 0;
}