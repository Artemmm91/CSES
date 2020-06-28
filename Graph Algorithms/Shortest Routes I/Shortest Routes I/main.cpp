#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;
#define ll long long
#define pll pair<long long, long long>

vector<vector<pll>> g(100000, vector<pair<ll, ll>>(0));
vector<ll> cost(100000, LLONG_MAX);
vector<bool> visited(100000, false);

void deixtra(ll x){
    priority_queue<pll, vector<pll>, greater<pll>> q;
    cost[x] = 0;
    q.push({0, x});
    ll t;
    while(!q.empty()){
        t = q.top().second; q.pop();
        if(!visited[t]){
            visited[t] = true;
            for(auto v: g[t]){
                if(cost[v.first] > cost[t] + v.second){
                    cost[v.first] = cost[t] + v.second;
                    q.push({cost[v.first], v.first});
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
        a--;b--;
        g[a].push_back({b, c});
    }
    deixtra(0);
    for(ll i = 0; i < n; i++){
        cout << cost[i] << " ";
    }
    return 0;
}
