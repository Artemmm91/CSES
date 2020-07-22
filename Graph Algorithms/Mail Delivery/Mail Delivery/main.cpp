#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<set<int>> g(100000);
vector<bool> visited(100000, false);

void dfs(int x){
    vector<vector<int>> cycles;
    int p, q, i = 0;
    while(g[x].size() != 0){
        cycles.push_back({});
        q = x;
        do{
            p = *(g[q].begin());
            g[q].erase(g[q].find(p));
            g[p].erase(g[p].find(q));
            q = p;
            cycles[i].push_back(q);
        }while(q != x);
    }
    for(auto c: cycles){
        for(auto v: c){
            cout << v + 1 << " ";
            dfs(v);
        }
    }
}

void dfs_init(int x){
    visited[x] = true;
    for(auto v: g[x]){
        if(!visited[v]){
            dfs_init(v);
        }
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    dfs_init(0);
    for(int i = 0; i < n; i++){
        if(g[i].size() % 2 != 0 || (!visited[i] && g[i].size() != 0)){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << 1 << " ";
    dfs(0);
    return 0;
}
