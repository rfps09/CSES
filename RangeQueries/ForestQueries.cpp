#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n,q;
 
    cin >> n >> q;
 
    char matriz[n+1][n+1];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> matriz[i][j];
        }
    }
 
    int prefixSum[n+1][n+1];
    memset(prefixSum,0,sizeof(prefixSum));
 
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            prefixSum[i][j] = prefixSum[i][j-1] + prefixSum[i-1][j] - prefixSum[i-1][j-1];
            if(matriz[i][j] == '*') prefixSum[i][j]++;
        }
    }
 
    int x1,y1,x2,y2;
 
    for(int i=0; i<q; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefixSum[x2][y2] - prefixSum[x2][y1-1] - prefixSum[x1-1][y2] + prefixSum[x1-1][y1-1] << "\n";
    }
 
    return 0;
}