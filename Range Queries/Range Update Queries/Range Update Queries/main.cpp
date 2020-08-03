#include <iostream>
using namespace std;
#define ll long long

ll p[200001], A[200001], n;

ll f(ll x){
    return x - (x & (x - 1));
}

void upd(ll k, ll x){
    while(k <= n){
        A[k] += x;
        k += p[k];
    }
}

ll sum(ll k){
    ll s = 0;
    while(k >= 1){
        s += A[k];
        k -= p[k];
    }
    return s;
}

int main() {
    ll q, a = 0, b, u;
    cin >> n >> q;
    for(ll i = 1; i <= n; i++){
        p[i] = f(i);
    }
    for(ll i = 1; i <= n; i++){
        cin >> b;
        upd(i, b - a);
        a = b;
    }
    while(q--){
        cin >> a;
        if(a == 1){
            cin >> a >> b >> u;
            upd(a, u);
            if(b != n){
                upd(b + 1, -u);
            }
        }
        else{
            cin >> a;
            cout << sum(a) << endl;
        }
    }
    return 0;
}
