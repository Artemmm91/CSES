#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll tree[525000], s;

ll p2(ll x){
    ll k = 1;
    while(k < x){
        k *= 2;
    }
    return k;
}

void upd(ll k, ll x){
    tree[k] += x;
    k /= 2;
    while(k >= 1){
        tree[k] = max(tree[2*k], tree[2*k + 1]);
        k /= 2;
    }
}


ll find(ll x){
    ll k = 1;
    while(k < 2*s){
        if(tree[k] < x) return -1;
        if(k >= s) return k;
        if(tree[2*k] >= x){
            k = 2 * k;
        }
        else{
            k = 2 * k + 1;
        }
    }
    return -1;
}

int main() {
    ll n, m, a, b;
    cin >> n >> m;
    s = p2(n);
    for(ll i = 0; i < n; i++){
        cin >> a;
        upd(i + s, a);
    }
    for(ll i = 0; i < m; i++){
        cin >> a;
        b = find(a);
        if(b == -1){
            cout << 0 << endl;
        }
        else{
            cout << b - s + 1 << endl;
            upd(b, -a);
        }
    }
    return 0;
}
