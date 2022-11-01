#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    int t;
    ll x,y;
    
    cin >> t;
    
    while(t){
        cin >> x >> y;
        
        auto getDig = [](ll x) -> ll {
            return 2*(x-1)*x/2 + 1;
        };
        
        ll ans = getDig(max(x,y));
        
        if(x > y) {
            if(x%2) ans-=(x-y);
            else ans+=(x-y);
        }
        if(y > x) {
            if(y%2) ans+=(y-x);
            else ans-=(y-x);
        }
 
		cout << ans << "\n";
        
        t--;
    }
 
    return 0;
}