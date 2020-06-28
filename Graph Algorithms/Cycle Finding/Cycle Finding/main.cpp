#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <tuple>
using namespace std;
#define ll long long
#define pll pair<long long, long long>

ll n, m, lm = LLONG_MAX;
vector<tuple<ll, ll, ll>> edges(0);
vector<ll> dist(2500, 0), p(2500, -1);

void ford(int x){
    dist[x] = 0;
    ll a, b, w, y = -1;
    bool is_loop = false;
    for(int i = 1; i <= n; i++){
        is_loop = false;
        for(auto e: edges){
            tie(a, b, w) = e;
            if(dist[a] != lm){
                if(dist[b] > dist[a] + w){
                    dist[b] = dist[a] + w;
                    p[b] = a;
                    is_loop = true;
                    y = b;
                }
            }
        }
    }
    if(is_loop){
        vector<ll> ans(0);
        for(ll i = 1; i <= n + 2; i++){
            y = p[y];
        }
        ll f = y;
        do{
            ans.push_back(f + 1);
            f = p[f];
        }while(f != y);
        ans.push_back(y + 1);
        cout << "YES" << endl;
        for(int i = ans.size() - 1; i >=0 ;i--){
            cout << ans[i] << " ";
        }
    }
    else{
        cout << "NO";
    }
}

int main() {
    int a, b, c;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--; b--;
        edges.push_back({a, b, c});
    }
    ford(0);
    return 0;
}
