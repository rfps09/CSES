#include <bits/stdc++.h>

using namespace std;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<pii> movies(n);

    for(int i=0; i<n; i++) {
        cin >> movies[i].second >> movies[i].first;
    }

    sort(movies.begin(), movies.end());

    int ans = 1;
    int start = 0, end = 1;

    while(end < n) {
        if(movies[start].first <= movies[end].second) {
            ans++;
            start=end;
        }
        end++;
    }
    
    cout << ans << "\n";

    return 0;
}