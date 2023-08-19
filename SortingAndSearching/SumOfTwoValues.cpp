#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n,x;

    cin >> n >> x;

    vector<pii> numbers(n);

    for(int i=0; i<n; i++) {
        cin >> numbers[i].first;
        numbers[i].second = i+1;
    }

    sort(numbers.begin(), numbers.end());

    int start=0, end=n-1;

    while(start<end) {
        int sum = numbers[start].first + numbers[end].first;
        if(sum < x) {
            start++;
        }
        else if(sum > x) {
            end--;
        }
        else {
            cout << numbers[start].second << " " << numbers[end].second << "\n";
            return 0;
        }
    }
    
    cout << "IMPOSSIBLE\n";

    return 0;
}