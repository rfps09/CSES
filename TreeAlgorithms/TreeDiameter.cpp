#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 2*1e5+1;

vector<int>grafinho[MAXN];
int visited[MAXN];
int deep[MAXN];
int n;

void dfs(int x) {
    visited[x] = 1;
    for(int i=0; i<grafinho[x].size(); i++) {
        int y = grafinho[x][i];
        if(!visited[y]) {
            deep[y] = deep[x] + 1;
            dfs(y);
        }
    }
    visited[x] = 0;
}

int get_farthest(int x) {
    int deephest = 0;
    int ans = 0;
    dfs(x);
    for(int i=1; i<=n; i++) {
        if(deephest < deep[i]) {
            ans = i;
            deephest = deep[i];
        }
    }
    
    return ans;
}

int main() {
    int x=0,y=0;
    
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        grafinho[x].push_back(y);
        grafinho[y].push_back(x);
    }
    
    int v = get_farthest(1);
    memset(deep,0,sizeof(deep));
    int d = get_farthest(v);
    
    cout << deep[d] << endl;

    return 0;
}