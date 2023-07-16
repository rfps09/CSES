#include <bits/stdc++.h>
 
using namespace std;
 
void solve(int n, int tStart, int tInter,int tEnd) {
    if(n > 1) {
        solve(n-1,tStart,tEnd,tInter);
        cout << tStart << " " << tEnd << "\n";
        solve(n-1,tInter,tStart,tEnd);
    }
    else cout << tStart << " " << tEnd << "\n";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int n;
    
    cin >> n;
    
    int minMoves = 1;
    
    for(int i=1; i<n; i++) {
        minMoves = minMoves*2+1;
    }
    
    cout << minMoves << "\n";
    
    solve(n,1,2,3);
 
    return 0;
}