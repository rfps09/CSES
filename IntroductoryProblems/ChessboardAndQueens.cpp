#include <bits/stdc++.h>

using namespace std;

const int n = 8;
char matriz[n][n];
int col[n][n];
int diagPrin[n][n];
int diagSec[n][n];
int col_fill[n];
int diagPrin_fill[2*n];
int diagSec_fill[2*n];

int backtracking(int x) {
    if(x == 0) {
        return 1;
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        int dp = diagPrin[x-1][i];
        int ds = diagSec[x-1][i];
        if(matriz[x-1][i] == '.' && !col_fill[i] && !diagPrin_fill[dp] && !diagSec_fill[ds]) {
            col_fill[i] = 1;
            diagPrin_fill[dp] = 1;
            diagSec_fill[ds] = 1;

            ans += backtracking(x-1);

            col_fill[i] = 0;
            diagPrin_fill[dp] = 0;
            diagSec_fill[ds] = 0;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int count = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> matriz[i][j];
            col[i][j] = j;
        }
    }

    count = 0;
    for(int i=n-1; i>=0; i--) {
        diagPrin[i][0] = count;
        count++; 
    }
    count--;
    for(int i=0; i<n; i++) {
        diagPrin[0][i] = count;
        count++; 
    }
    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            diagPrin[i][j] = diagPrin[i-1][j-1];
        }
    }

    count = 0;
    for(int i=n-1; i>=0; i--) {
        diagSec[i][n-1] = count;
        count++;
    }
    count--;
    for(int i=n-1; i>=0; i--) {
        diagSec[0][i] = count;
        count++;
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<n-1; j++) {
            diagSec[i][j] = diagSec[i-1][j+1];
        }
    }

    memset(col_fill,0,sizeof(col_fill));
    memset(diagPrin_fill,0,sizeof(diagPrin_fill));
    memset(diagSec_fill,0,sizeof(diagSec_fill));

    cout << backtracking(n) << endl;

    return 0;
}