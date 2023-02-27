#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class FenwickTree {
public:
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        if(l > r) {
            return  sum(this->n-1) - sum(l-1) + sum(r);
        }
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll n,k;
    bool vivos[200001];

    cin >> n >> k;

    FenwickTree circle(n+1);

    for(int i=1; i<=n; i++) {
        circle.add(i,1);
        vivos[i] = true;
    }

    int fix=1, l=1,r=1;

    for(int i=0; i<n; i++) {
        int jump = (k%(n-i))+1;

        int sum = -1;
        l = fix;
        r = fix + n;

        while(sum != jump) { 
            int mid = (l+r)/2;
            sum = circle.sum(fix,mid > n ? mid%n : mid);

            if(sum > jump) r = mid;
            else if(sum < jump) l = mid;
            else if(sum == jump && !vivos[mid > n ? mid%n : mid]) {
                sum = -1;
                r = mid;
            }
            else {
                fix = mid > n ? mid%n : mid;
                break;
            }
        }

        if(i < n-1) cout << fix << " ";
        else cout << fix << "\n";
        circle.add(fix,-1);
        vivos[fix] = false;
    }

    return 0;
}