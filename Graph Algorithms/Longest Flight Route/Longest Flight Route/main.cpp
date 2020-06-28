#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> g(100000, vector<int>(0)), g_in(100000, vector<int>(0));
vector<pair<int, int>> time_out(100000, {-1, 0});
vector<int> color(100000, 0), coord(100000, -1);
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
    int l, r, c;
    for(int i = 0; i < n; i++){
        coord[time_out[i].second] = i;
    }
    l = coord[0]; r = coord[n - 1];
    if(r < l){
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> ans(n, 0), p(n, -1);
    ans[0] = 0;
    for(int i = l; i <= r; i++){
        for(int v: g_in[time_out[i].second]){
            c = coord[v];
            if(c >= l && c < i){
                if(ans[i] < ans[c] + 1){
                    ans[i] = ans[c] + 1;
                    p[i] = c;
                }
            }
        }
    }
    if(ans[r] == 0){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << ans[r] + 1 << endl;
        int t = r;
        vector<int> way(0);
        while(t >= l){
            way.push_back(t);
            t = p[t];
        }
        for(int i = way.size()-1; i >= 0; i--){
            cout << time_out[way[i]].second + 1 << " ";
        }
    }
    return 0;
}
