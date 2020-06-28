#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <tuple>
using namespace std;
#define ll long long
ll lm = LLONG_MAX;

vector<tuple<ll, ll, ll>> edges(0);
vector<ll> dist(2500, lm);
ll ans;

bool ford_check(ll x, ll n, ll last){
    ll a, b, w;
    for(ll i = 1; i <= n; i++){
        for(auto e: edges){
            tie(a, b, w) = e;
            if(dist[a] != lm && dist[b] > dist[a] + w){
                dist[b] = -lm + 1;
            }
        }
        ans = dist[n - 1];
    }
    if(ans != last){
        return true;
    }
    return false;
}


void ford(ll x, ll n){
    dist[x] = 0;
    ll a, b, w, last_ans = 1;
    bool is_changed;
    for(ll i = 1; i <= n; i++){
        is_changed = false;
        for(auto e: edges){
            tie(a, b, w) = e;
            if(dist[a] != lm && dist[b] > dist[a] + w){
                dist[b] = dist[a] + w;
                is_changed = true;
            }
        }
        ans = dist[n - 1];
        if(i == n - 1){
            last_ans = ans;
        }
        if(!is_changed){
            return;
        }
        if(i == n && is_changed){
            if(ford_check(x, n, last_ans)){
                ans = 1;
            }
        }
    }
}

int main() {
    ll n, m, a, b, c;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--; b--; c = 0 - c;
        edges.push_back({a, b, c});
    }
    ford(0, n);
    cout << -ans;
    return 0;
}
