#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> g(100000, vector<int>(0)), g_T(100000, vector<int>(0));
vector<bool> visited(100000, false);
vector<int> component(100000, -1);
vector<pair<int, int>> time_out(100000);
int comp = 0, timer = 0;

void dfs(int x){
    visited[x] = true;
    for(int v: g[x]){
        if(!visited[v]){
            dfs(v);
        }
    }
    time_out[x] = {timer++, x};
}

void dfs_T(int x){
    component[x] = comp;
    for(int v: g_T[x]){
        if(component[v] == -1){
            dfs_T(v);
        }
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g_T[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    sort(time_out.begin(), time_out.end(), greater<pair<int, int>>());
    for(int i = 0; i < n; i++){
        if(component[time_out[i].second] == -1){
            dfs_T(time_out[i].second);
            comp++;
        }
    }
    cout << comp << endl;
    for(int i = 0; i < n; i++){
        cout << component[i] + 1 << " ";
    }
    return 0;
}
