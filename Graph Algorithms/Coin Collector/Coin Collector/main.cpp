#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
#define ll long long

vector<vector<ll>> g(100000), g_T(100000), g_comp(100000);
vector<pair<ll, ll>> edges;
vector<bool> visited(100000, false);
vector<ll> coins(100000), coin_comp(100000, 0), coord(100000, -1), ans(100000);
vector<pair<ll, ll>> time_out(100000);
ll timer = 0, comp = 0, ans_coin;

void dfs_init(ll x){
    visited[x] = true;
    for(ll v: g[x]){
        if(!visited[v]){
            dfs_init(v);
        }
    }
    time_out[x] = {timer++, x};
}

void dfs_T(ll x){
    coord[x] = comp;
    coin_comp[comp] += coins[x];
    for(ll v: g_T[x]){
        if(coord[v] == -1){
            dfs_T(v);
        }
    }
}

int main() {
    ll n, m, a, b;
    cin >> n >> m;
    for(ll i = 0; i < n; i++){
        cin >> coins[i];
    }
    for(ll i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g_T[b].push_back(a);
        edges.push_back({a, b});
    }
    for(ll i = 0; i < n; i++){
        if(!visited[i]){
            dfs_init(i);
        }
    }
    sort(time_out.begin(), time_out.end(), greater<pair<ll, ll>>());
    for(ll i = 0; i < n; i++){
        a = time_out[i].second;
        if(coord[a] == -1){
            dfs_T(a);
            comp++;
        }
    }
    for(auto e: edges){
        tie(a, b) = e;
        if(coord[a] != coord[b]){
            g_comp[coord[b]].push_back(coord[a]);
        }
    }
    ll max_temp;
    for(ll i = 0; i < comp; i++){
        max_temp = coin_comp[i];
        for(ll v: g_comp[i]){
            max_temp = max(max_temp, coin_comp[i] + ans[v]);
        }
        ans[i] = max_temp;
        ans_coin = max(ans_coin, max_temp);
    }
    cout << ans_coin;
    return 0;
}
