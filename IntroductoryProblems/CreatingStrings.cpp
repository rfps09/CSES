#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    string S;
    
    cin >> S;
    
    sort(S.begin(), S.end());
    
    int letters[26];
    int fat[9];
    fat[0] = 1;
    
    for(int i=1; i<=8; i++) {
        fat[i] = i*fat[i-1];
    }
    
    int ans = fat[S.length()];
    
    memset(letters,0,sizeof(letters));
    
    for(int i=0; i<S.length(); i++) {
        letters[S[i]-'a']++;
    }
    
    for(int i=0; i<26; i++) {
        ans/=fat[letters[i]];
    }
    
    cout << ans << "\n";
    
    cout << S << "\n";
    
    while(next_permutation(S.begin(), S.end())) {
        cout << S << "\n";
    }
 
    return 0;
}