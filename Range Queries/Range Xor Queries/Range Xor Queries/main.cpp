#include <iostream>
#include <vector>
using namespace std;
#define ll long

vector<ll> A(525000, 0);

ll p2(ll x){
    ll s = 1;
    while(s < x){
        s *= 2;
    }
    return s;
}

void upd(ll k, ll x){
    A[k] = x;
    k /= 2;
    while(k >= 1){
        A[k] = A[2 * k] ^ A[2 * k + 1];
        k /= 2;
    }
}

ll xor_sum(ll a, ll b){
    ll s = 0;
    vector<ll> l(0), r(0);
    while(a <= b){
        if(a % 2 == 1){
            l.push_back(A[a]);
            a++;
        }
        if(b % 2 == 0){
            r.push_back(A[b]);
            b--;
        }
        a /= 2;
        b /= 2;
    }
    for(ll v: l){
        s = s ^ v;
    }
    for(ll i = r.size() - 1; i >= 0; i--){
        s = s ^ r[i];
    }
    return s;
}

int main() {
    ll n, s, q, a, b;
    cin >> n >> q;
    s = p2(n);
    for(ll i = 0; i < 2*s; i++){
        if(i >= s && i < s + n){
            cin >> a;
            upd(i, a);
        }
    }
    while(q--){
        cin >> a >> b;
        cout << xor_sum(a + s - 1, b + s - 1) << endl;
    }
    return 0;
}
