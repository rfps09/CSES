#include <iostream>

using namespace std;

void troca(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    int a,b;

    cin >> t;

    while(t) {
        cin >> a >> b;

        if(b > a) troca(a,b);

        int diff = a-b;

        if(b >= diff) {
            a -= diff*2;
            b -= diff;
        }
        
        if(a == b && (!(a%3) && !(b%3)) ) cout << "YES\n";
        else cout << "NO\n";

        t--;
    }

    return 0;
}