#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int mod = 1000000007;

vector<vector<int>> g(100000, vector<int>(0)), g_in(100000, vector<int>(0));
vector<int> color(100000, 0), coord(100000, -1);
vector<pair<int, int>> time_out(100000, {-1, 0});
int timer = 0;

void dfs(int x){
    color[x] = 1;
    timer++;
    for(int v: g[x]){
        if(color[v] == 0){
            dfs(v);
        }
    }
    time_out[x] = {timer, x};
    timer++;
    color[x] = 2;
}


int main() {
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g_in[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(color[i] == 0){
            dfs(i);
        }
    }
    sort(time_out.begin(), time_out.end(), greater<pair<int, int>>());
    for(int i = 0; i < n; i++){
        coord[time_out[i].second] = i;
    }
    int l = coord[0], r = coord[n - 1], c;
    if(l > r){
        cout << 0;
        return 0;
    }
    vector<int> ans(100000, 0);
    ans[l] = 1;
    for(int i = l + 1; i <= r; i++){
        for(int v: g_in[time_out[i].second]){
            c = coord[v];
            if(c >= l && c < i){
                ans[i] = ans[i] + ans[c];
                ans[i] = ans[i] % mod;
            }
        }
    }
    cout << ans[r];
    return 0;
}
