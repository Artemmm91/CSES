#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;
#define ll long long

ll n, m;
vector<vector<ll>> graph(500, vector<ll>(500, -1));

bool bfs(){
    vector<bool> visited(n, false);
    vector<ll> p(n, -1);
    queue<ll> q;
    ll t, x, y, minc = LLONG_MAX;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        t = q.front(); q.pop();
        if(t == n - 1){
            x = p[t];
            y = t;
            while(x != -1){
                minc = min(minc, graph[x][y]);
                y = x; x = p[y];
            }
            x = p[t];
            y = t;
            while(x != -1){
                graph[x][y] -= minc;
                graph[y][x] += minc;
                y = x; x = p[y];
            }
            return true;
        }
        for(ll i = 0; i < n; i++){
            if(!visited[i] && graph[t][i] > 0){
                q.push(i);
                visited[i] = true;
                p[i] = t;
            }
        }
    }
    return false;
}

int main() {
    ll a, b, c;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--; b--;
        if(a != n - 1 && b != 0){
            if(graph[a][b] == -1){
                graph[a][b] = c;
                graph[b][a] = 0;
            }
            else{
                graph[a][b] += c;
            }
        }
    }
    while(bfs()){
        
    }
    c = 0;
    for(ll i = 0; i < n - 1; i++){
        if(graph[n - 1][i] > 0){
            c += graph[n - 1][i];
        }
    }
    cout << c;
    return 0;
}
