#include <bits/stdc++.h>

using namespace std;

class FenwickTreeOneBasedIndexing {
public:
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTreeOneBasedIndexing(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTreeOneBasedIndexing(vector<int> a)
        : FenwickTreeOneBasedIndexing(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

int custom_binary_search(FenwickTreeOneBasedIndexing &space_search, int end) {
    int start = 0;
    int target = space_search.sum(end);
    int ans = end;

    while(start <= end) {
        int mid = (start+end)/2;
        if(space_search.sum(mid) < target) {
            start = mid+1;
        }
        else {
            ans = mid;
            end = mid-1;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n,m;

    cin >> n >> m;

    vector<int> tickets(n);
    FenwickTreeOneBasedIndexing tickets_on_sell(n);

    for(int i=0; i<n; i++) {
        cin >> tickets[i];
        tickets_on_sell.add(i,1);
    }

    vector<int> customers(m);

    for(int i=0; i<n; i++) {
        cin >> customers[i];
    }

    sort(tickets.begin(), tickets.end());

    for(int i=0; i<m; i++) {
        int end = upper_bound(tickets.begin(),tickets.end(),customers[i]) - tickets.begin() - 1;
        if(tickets_on_sell.sum(end) > 0) {
            int idx = custom_binary_search(tickets_on_sell,end);
            cout << tickets[idx] << "\n";
            tickets_on_sell.add(idx,-1);
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}