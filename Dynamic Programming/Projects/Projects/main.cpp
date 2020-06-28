#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long

vector<pair<pair<ll, ll>, ll>> v;

ll find_m(ll x){
    ll it = 0;
    return it;
}

int main() {
    ll n, t1, t2, q;
    cin >>n;
    vector<ll> ans;
    pair<pair<ll, ll>, ll> p;
    pair<ll, ll> p_0;
    set<pair<ll, ll>> s;
    set<pair<ll, ll>> :: iterator it;
    for(ll i = 0; i < n; i++){
        cin >> p.first.second >> p.first.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    ans.push_back(v[0].second);
    p_0.first = v[0].first.first;
    p_0.second = 0;
    s.insert(p_0);
    for(ll i = 1; i < n; i++){
        p_0.first = v[i].first.second;
        p_0.second = 0;
        t1 = ans[i - 1];
        it = s.lower_bound(p_0);
        if(it == s.end()){
            q = i - 1;
        }
        else{
            q = (*it).second - 1;
        }
        t2 = -1;
        if(q != -1){
            t2 = ans[q] + v[i].second;
        }
        else{
            t2 = v[i].second;
        }
        p_0.first = v[i].first.first;
        p_0.second = i;
        ans.push_back(max(t1, t2));
        s.insert(p_0);
    }
    cout << ans[n - 1];
    return 0;
}
