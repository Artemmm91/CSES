#include <iostream>
using namespace std;
#define ll long long

ll A[200010], p[200010], tree[200010], n;

ll f(ll k){
    return k - (k&(k - 1));
}

ll sum(ll k){
    ll s = 0;
    while(k > 0){
        s = s + tree[k];
        k = k - p[k];
    }
    return s;
}

void upd(ll k, ll x){
    ll delta = x - A[k];
    while(k <= n){
        tree[k] = tree[k] + delta;
        k = k + p[k];
    }
}

int main() {
    ll q, a, b, c;
    cin >> n >> q;
    for(ll i = 1; i <= n; i++){
        cin >> A[i];
        p[i] = f(i);
        for(ll j = i; j >= i - p[i] + 1; j--){
            tree[i] = tree[i] + A[j];
        }
    }
    while(q--){
        cin >> a >> b >> c;
        if(a == 1){
            upd(b, c);
            A[b] = c;
        }
        else{
            if(b == 1){
                cout << sum(c) << endl;
            }
            else{
                ll x;
                x = sum(c) - sum(b - 1);
                cout << x << endl;
            }
        }
    }
    return 0;
}
