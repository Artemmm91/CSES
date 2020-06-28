#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
#define ll long long
#define pll pair<long long, long long>
ll lm = LLONG_MAX;

int k, n;
vector<vector<pll>> g(100000, vector<pll>(0));
vector<vector<ll>> dist(100000, vector<ll>(1, lm));
vector<int> visited(100000, 0);

void deixtra(ll x){
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, x});
    dist[x][0] = 0;
    ll t, b, w, cnt = 0, w_t;
    while(!q.empty()){
        t = q.top().second;
        w_t = q.top().first;
        q.pop();
        if(visited[t] <= k){
            if(t == n - 1){
                cnt++;
                cout << w_t << " ";
                if(cnt == k) return;
            }
            visited[t]++;
            for(auto v: g[t]){
                b = v.first; w = v.second;
                if(visited[b] <= k){
                    q.push({w_t + w, b});
                }
            }
        }
    }
}

int main() {
    int m, a, b, c;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
    }
    deixtra(0);
    return 0;
}
