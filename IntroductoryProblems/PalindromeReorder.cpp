#include <iostream>
#include <stack>

using namespace std;

int letters[30];

int main() {
    string palin;

    cin >> palin;

    for(int i=0; i<palin.length(); i++) {
        letters[palin[i] - 'A']++;
    }

    int val = palin.length() % 2;
    
    for(int i=0; i<30; i++) {
        if(letters[i] % 2) {
            val--;
            if(val < 0) break;
        }
    }

    if(!val) {
        stack<char> tail;
        char mid = 0;
        for(int i=0; i<30; i++) {
            if(letters[i] % 2) {
                mid = i+'A';
            }

            int qtd = letters[i]/2;

            for(int j=0; j<qtd; j++) {
                cout << (char)(i+'A');
                tail.push(i+'A');
            }
        }

        if(mid) {
            cout << mid;
        }

        while(!tail.empty()) {
            cout << tail.top();
            tail.pop();
        }

        cout << '\n';
    }
    else cout << "NO SOLUTION\n";

    return 0;
}