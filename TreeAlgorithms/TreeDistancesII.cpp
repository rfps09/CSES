#include <iostream>
#include <vector>

using namespace std;
using ll = long long int;

const int MAXN = 2*1e5+1;

vector<int>grafinho[MAXN];
int visited[MAXN];
int subTree[MAXN];
ll ans[MAXN];
int n;

int dfs(int x) {
    visited[x] = 1;
    for(int i=0; i<grafinho[x].size(); i++) {
        int y = grafinho[x][i];
        if(!visited[y]) {
            ans[y] = ans[x]+1;
            subTree[x]+=dfs(y);
        }
    }
    visited[x] = 0;

    return subTree[x]+1;
}

void solve(int x) {
    visited[x] = 1;
    for(int i=0; i<grafinho[x].size(); i++) {
        int y = grafinho[x][i];
        if(!visited[y]) {
            ans[y] = ans[x]+(n-subTree[y]) - subTree[y];
            solve(y);
        }
    }
    visited[x] = 0;
}

int main() {
    int x,y;

    cin >> n;

    for(int i=1; i<n; i++) {
        cin >> x >> y;
        grafinho[x].push_back(y);
        grafinho[y].push_back(x);
    }

    dfs(1);

    for(int i=2; i<=n; i++) {
        ans[1]+=ans[i];
        subTree[i]++;
    }

    solve(1);

    for(int i=1; i<n; i++) {
        cout << ans[i] << " ";
    } cout << ans[n] << endl;

    return 0;
}