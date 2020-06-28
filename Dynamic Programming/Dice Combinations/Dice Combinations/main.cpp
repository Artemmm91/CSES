#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll mod = 1000000007;

int main() {
    vector<ll> v{1, 2, 4, 8, 16, 32};
    ll n, k;
    cin >> n;
    while(v.size() < n){
        k = v.size();
        k = v[k - 1] + v[k - 2] + v[k - 3] + v[k - 4] + v[k - 5] + v[k - 6];
        k = k % mod;
        v.push_back(k);
    }
    cout << v[n - 1];
    return 0;
}
