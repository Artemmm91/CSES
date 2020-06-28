#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
#define pll pair<long long, long long>
#define ll long long
ll lm = LLONG_MAX / 2;

vector<vector<pll>> g(100000, vector<pll>(0));
vector<ll> dist(100000, lm), dist_c(100000, lm);
vector<bool> visited(100000, false);

void deixtra(ll x){
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, x});
    dist[x] = 0;
    dist_c[x] = 0;
    ll t, b, w;
    while(!q.empty()){
        t = q.top().second; q.pop();
        if(!visited[t]){
            visited[t] = true;
            for(auto v: g[t]){
                b = v.first; w = v.second;
                dist[b] = min(dist[b], dist[t] + w);
                if(dist_c[b] > min(dist[t] + w / 2, dist_c[t] + w)){
                    dist_c[b] = min(dist[t] + w / 2, dist_c[t] + w);
                    q.push({dist_c[b], b});
                }
            }
        }
    }
}

int main() {
    ll n, m, a, b, c;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
    }
    deixtra(0);
    cout << dist_c[n - 1];
    return 0;
}
