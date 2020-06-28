#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#define pll pair<long long, long long>
#define ll long long
using namespace std;
ll mod = 1000000007, lm = LLONG_MAX;

struct data{
    ll dist, cnt, min_l, max_l;
    data(ll dist, ll cnt, ll min_l, ll max_l){
        this->dist = dist;
        this->cnt = cnt;
        this->min_l = min_l;
        this->max_l = max_l;
    }
};

vector<vector<pll>> g(100000, vector<pll>(0));
vector<bool> visited(100000, false);
vector<data> ans(100000, data(lm, 0, -1, -1));

void deixtra(ll x){
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0, x});
    data d(0, 1, 0, 0);
    ans[x] = d;
    ll t, b, w;
    while(!q.empty()){
        t = q.top().second; q.pop();
        if(!visited[t]){
            visited[t] = true;
            for(auto v: g[t]){
                b = v.first; w = v.second;
                if(ans[t].dist != lm){
                    if(ans[b].dist > ans[t].dist + w){
                        ans[b].dist = ans[t].dist + w;
                        ans[b].cnt = ans[t].cnt;
                        ans[b].min_l = ans[t].min_l + 1;
                        ans[b].max_l = ans[t].max_l + 1;
                        q.push({ans[b].dist, b});
                    }
                    else if(ans[b].dist == ans[t].dist + w){
                        ans[b].cnt = (ans[b].cnt + ans[t].cnt) % mod;
                        ans[b].min_l = min(ans[b].min_l, ans[t].min_l + 1);
                        ans[b].max_l = max(ans[b].max_l, ans[t].max_l + 1);
                    }
                }
            }
        }
    }
}

int main() {
    ll n, m, a, b, c;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b, c});
    }
    deixtra(0);
    cout << ans[n - 1].dist << " " << ans[n - 1].cnt << " " << ans[n - 1].min_l << " " << ans[n - 1].max_l;
    return 0;
}
