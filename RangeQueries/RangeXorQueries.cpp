#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
ll build(ll *heap, int *leafs, int l, int r, int node=1) {
    if(l == r) return heap[node]=leafs[l-1];
    int mid = (l+r)/2;
    return heap[node] = build(heap,leafs,l,mid,node*2) ^ build(heap,leafs,mid+1,r,node*2+1);
}
 
ll query(ll *heap, int a, int b, int l, int r, int node=1) {
    if(l >= a && r <= b) return heap[node];
    if(a > r || b < l) return 0;
    int mid = (l+r)/2;
    return query(heap,a,b,l,mid,node*2) ^ query(heap,a,b,mid+1,r,node*2+1);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n,q;
    int a,b;
 
    cin >> n >> q;
 
    int vetor[n];
    for(int i=0; i<n; i++) {
        cin >> vetor[i];
    }
 
    ll heap[4*n];
 
    build(heap,vetor,1,n);
 
    for(int i=0; i<q; i++) {
        cin >> a >> b;
        cout << query(heap,a,b,1,n) << "\n";
    }
 
    return 0;
}