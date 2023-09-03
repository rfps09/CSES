#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int x,n;
    int p;

    cin >> x >> n;

    set<int> lights;
    multiset<int> interval;
    lights.insert(0);
    lights.insert(x);
    interval.insert(x);

    for(int i=0; i<n; i++) {
        cin >> p;
        auto it = lights.upper_bound(p);
        auto next = it;
        auto prev = --it;

        interval.erase(interval.find(*next-*prev));
        interval.insert(p-*prev);
        interval.insert(*next-p);
        lights.insert(p);

        auto ans = interval.end();
        cout << *--ans << " ";
    } cout << "\n";

    return 0;
}