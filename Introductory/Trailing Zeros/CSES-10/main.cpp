#include <iostream>
using namespace std;
#define ll long long

ll func(ll k, ll q){
    ll s = 0, l = 1, d = q;
    while (l != 0){
        l = k / d;
        s += l;
        d = d * q;
    }
    return s;
}

int main() {
    ll n;
    cin >> n;
    cout << min(func(n, 2), func(n, 5));
    return 0;
}
