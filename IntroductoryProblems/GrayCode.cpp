#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;

    cin >> n;

    string number;

    for(int i=0; i<n; i++) {
        number += "0";
    }

    int len = number.length()-1;

    vector<string> list;

    list.push_back(number);
    number[len] = '1';
    list.push_back(number);

    for(int i=1; i<n; i++) {
        int size_l = list.size()-1;
        int idx = len-i;
        for(int j=size_l; j>=0; j--) {
            number = list[j];
            number[idx] = '1';
            list.push_back(number);
        }
    }

    for(int i=0; i<list.size(); i++) {
        cout << list[i] << "\n";
    }

    return 0;
}