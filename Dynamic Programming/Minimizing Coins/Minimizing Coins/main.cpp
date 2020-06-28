#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
    vector<ll> v;
    ll n, x, A[100], k, min_k;
    cin >> n >> x;
    for(ll i = 0; i < n; i++){
        cin >> A[i];
    }
    v.push_back(0);
    for(ll i = 1; i <= x; i++){
        min_k = -1;
        for(int j = 0; j < n; j++){
            if(v.size() >= A[j]){
                k = 1 + v[v.size() - A[j]];
                if ((k != 0) && (min_k == -1 || min_k > k)){
                    min_k = k;
                }
            }
        }
        v.push_back(min_k);
    }
    cout << v[x];
    return 0;
}
