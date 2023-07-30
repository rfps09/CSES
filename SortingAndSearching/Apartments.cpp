#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n,m,k;
    int applicant,apartment;

    cin >> n >> m >> k;

    priority_queue<int> applicants;

    for(int i=0; i<n; i++) {
        cin >> applicant;
        applicants.push(applicant);
    }

    priority_queue<int> apartments;

    for(int i=0; i<m; i++) {
        cin >> apartment;
        apartments.push(apartment);
    }

    int ans = 0;

    while(!apartments.empty() && !applicants.empty()) {
        if(apartments.top() > applicants.top()+k) {
            apartments.pop();
        }
        else if (apartments.top() < applicants.top()-k) {
            applicants.pop();
        }
        else {
            ans++;
            apartments.pop();
            applicants.pop();
        }
    }

    cout << ans << "\n";

    return 0;
}