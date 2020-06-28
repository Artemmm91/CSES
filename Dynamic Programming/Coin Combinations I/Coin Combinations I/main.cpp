#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
ll mod = 1000000007;

int main() {
    vector<ll> v;
    ll n, x, A[100];
    cin >> n >> x;
    for(ll i = 0; i < n; i++){
        cin >> A[i];
    }
    v.push_back(0);
    for(ll i = 1; i <= x; i++){
        v.push_back(0);
        for(ll j = 0; j < n; j++){
            if(v.size() >= A[j] + 1){
                if(v[v.size() - A[j] - 1] != -1){
                    v[i] += v[v.size() - A[j] - 1];
                }
            }
            if(i == A[j]){
                v[i] += 1;
            }
        }
        v[i] = v[i] % mod;
    }
    cout << v[x];
    return 0;
}
