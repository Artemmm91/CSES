#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;
#define ll long long

ll n, m;
vector<vector<ll>> g(500, vector<ll>(500, -1));
vector<pair<ll, ll>> e(0);
vector<ll> p(500, -1), coord(500, 0);

bool ff(){
    vector<bool> visited(500, false);
    ll t, x, y, minc = LLONG_MAX;
    visited[0] = true;
    queue<ll> q;
    q.push(0);
    while(!q.empty()){
        t = q.front(); q.pop();
        if(t == n - 1){
            x = p[t];
            y = t;
            while(x != -1){
                minc = min(minc, g[x][y]);
                y = x; x = p[y];
            }
            x = p[t]; y = t;
            while(x != -1){
                g[x][y] -= minc;
                g[y][x] += minc;
                y = x; x = p[y];
            }
            return true;
        }
        for(ll i = 0; i < n; i++){
            if(!visited[i] && g[t][i] > 0){
                visited[i] = true;
                p[i] = t;
                q.push(i);
            }
        }
    }
    return false;
}

void bfs(){
    queue<ll> q;
    q.push(0);
    coord[0] = 1;
    while(!q.empty()){
        ll t = q.front(); q.pop();
        for(ll i = 0; i < n; i++){
            if(!coord[i] && g[t][i] > 0){
                coord[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    ll a, b;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        g[a][b] = 1;
        g[b][a] = 1;
        e.push_back({a, b});
    }
    while(ff()){}
    bfs();
    vector<pair<ll, ll>> ans(0);
    for(auto E: e){
        if(coord[E.first] != coord[E.second]){
            ans.push_back(E);
        }
    }
    cout << ans.size() << endl;
    for(auto E: ans){
        cout << E.first + 1 << " " << E.second + 1 << endl;
    }
    return 0;
}
