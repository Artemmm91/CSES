#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
    ll n, A[5000], t1, t2;
    cin >> n;
    for(ll i = 0; i< n; i++){
        cin >> A[i];
    }
    vector<vector<pair<ll, ll>>> v;
    vector<pair<ll, ll>> v_0;
    pair<ll, ll> p;
    for(ll ii = 0; ii < n; ii++){
        ll i = n - 1 - ii;
        v_0.clear();
        for(ll j = 0; j < n; j++){
            if(i > j){
                p.first = 0;
                p.second = 0;
            }
            else{
                if(i == j){
                    p.first = A[i];
                    p.second = 0;
                }
                else{
                    t1 = v_0[j - 1].second + A[j];
                    t2 = v[ii - 1][j].second + A[i];
                    if(t1 > t2){
                        p.first = t1;
                        p.second = v_0[j - 1].first;
                    }
                    else{
                        p.first = t2;
                        p.second = v[ii - 1][j].first;
                    }
                }
            }
            v_0.push_back(p);
        }
        v.push_back(v_0);
    }
    cout << v[n - 1][n - 1].first;
    return 0;
}
