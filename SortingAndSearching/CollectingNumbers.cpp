#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    int number;

    cin >> n;

    int ans = 0;
    set<int> numbers;

    for(int i=0; i<n; i++) {
        cin >> number;

        numbers.insert(number);
        if(numbers.find(number-1) == numbers.end()) {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}