#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;
#define ll long long

vector<ll> A(525000, LLONG_MAX);

ll p2(ll x){
    ll s = 1;
    while(s < x){
        s *= 2;
    }
    return s;
}

void upd(ll x, ll k){
    A[k] = x;
    k /= 2;
    while(k >= 1){
        A[k] = min(A[2 * k], A[2 * k + 1]);
        k /= 2;
    }
}

ll min_d(ll a, ll b){
    ll m = LLONG_MAX;
    while(a <= b){
        if(a % 2 == 1){
            m = min(m, A[a]);
            a++;
        }
        if(b % 2 == 0){
            m = min(m, A[b]);
            b--;
        }
        a /= 2;
        b /= 2;
    }
    return m;
}

int main() {
    ll n, s, q, a, b, c;
    cin >> n >> q;
    s = p2(n);
    for(ll i = s; i < s + n; i++){
        cin >> a;
        upd(a, i);
    }
    while(q--){
        cin >> a >> b >> c;
        if(a == 1){
            upd(c, b + s - 1);
        }
        else{
            cout << min_d(b + s - 1, c + s - 1) << endl;
        }
    }
    return 0;
}
