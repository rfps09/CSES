#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> set_1;
    vector<int> set_2;

    ll set_1_sum = 0;
    ll set_2_sum = 0;

    while(n) {
        if(set_1_sum <= set_2_sum) {
            set_1.push_back(n);
            set_1_sum+=n;
        } else {
            set_2.push_back(n);
            set_2_sum+=n;
        }
        n--;
    }

    if(set_1_sum == set_2_sum) {
        cout << "YES\n";

        int set_1_size = set_1.size()-1;

        cout << set_1_size+1 << "\n";

        for(int i=0; i<set_1_size; i++) {
            cout << set_1[i] << " ";
        }

        cout << set_1[set_1_size] << "\n";

        int set_2_size = set_2.size()-1;

        cout << set_2_size+1 << "\n";

        for(int i=0; i<set_2_size; i++) {
            cout << set_2[i] << " ";
        }

        cout << set_2[set_2_size] << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}