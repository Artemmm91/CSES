#include <iostream>
#define ll long long
using namespace std;

int main() {
    ll ps[200001], n, q, a, b;
    cin >> n >> q;
    ps[0] = 0;
    for(ll i = 0; i < n; i++){
        cin >> a;
        ps[i + 1] = a + ps[i];
    }
    for(ll i = 0; i < q; i++){
        cin >> a >> b;
        cout << ps[b] - ps[a - 1] << endl;
    }
    return 0;
}
