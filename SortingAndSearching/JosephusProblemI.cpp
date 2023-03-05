#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;

    cin >> n;

    queue<int> circle;

    for(int i=1; i<=n; i++) {
        circle.push(i);
    }

    while(!circle.empty()) {
        circle.push(circle.front());
        circle.pop();
        if(circle.size() != 1)
            cout << circle.front() << " ";
        else
            cout << circle.front() << "\n";
        circle.pop();
    }

    return 0;
}