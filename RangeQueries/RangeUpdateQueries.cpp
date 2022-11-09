#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
void build(ll *heap, int *leafs, int l, int r, int node=1) {
    if(l == r) heap[node] = leafs[l-1];
    else {
        heap[node] = 0;
        int mid = (l+r)/2;
        build(heap,leafs,l,mid,node*2);
        build(heap,leafs,mid+1,r,node*2+1);
    }
}
 
ll query(ll *heap, int k, int l, int r, int node=1) {
    if(k == l && k == r) return heap[node];
    if(k>=l && k<=r) {
        int mid = (l+r)/2;
        return heap[node] + query(heap,k,l,mid,node*2) + query(heap,k,mid+1,r,node*2+1);
    }
    return 0;
}
 
void update(ll *heap, int u, int a, int b, int l, int r, int node=1) {
    if(l>b || r<a) return;
    if(l >= a && r <= b) heap[node] += u;
    else {
        int mid = (l+r)/2;
        update(heap,u,a,b,l,mid,node*2);
        update(heap,u,a,b,mid+1,r,node*2+1);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n,q;
    int type;
    int u;
    int a,b;
 
    cin >> n >> q;
 
    int vetor[n];
    for(int i=0; i<n; i++) {
        cin >> vetor[i];
    }
 
    ll heap[4*n];
 
    build(heap,vetor,1,n);
 
    for(int i=0; i<q; i++) {
        cin >> type;
        if(type-1) {
            cin >> a;
            cout << query(heap,a,1,n) << "\n";
        }
        else {
            cin >> a >> b >> u;
            update(heap,u,a,b,1,n);
        }
    }
 
    return 0;
}