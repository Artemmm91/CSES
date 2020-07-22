#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g(100000);
vector<pair<int, int>> degree(100000, {0, 0});
vector<int> euler(0), ans(0);

void dfs_cycle(int x){
    vector<vector<int>> cycles(0);
    int i = 0, p = x, q = x;
    while(!g[x].empty()){
        cycles.push_back({});
        do{
            p = g[q].back();
            g[q].pop_back();
            q = p;
            cycles[i].push_back(p);
        }while(p != x);
        i++;
    }
    for(auto c: cycles){
        for(auto v: c){
            ans.push_back(v);
            dfs_cycle(v);
        }
    }
}

int main() {
    int n, m, a, b, k = -1;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        degree[a].first++;
        degree[b].second++;
    }
    g[n - 1].push_back(0);
    degree[0].second++;
    degree[n - 1].first++;
    for(int i = 0; i < n; i++){
        if(degree[i].first != degree[i].second){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    dfs_cycle(0);
    for(int i = 0; i < n; i++){
        if(!g[i].empty()){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for(int i = 0; i < ans.size() - 1; i++){
        if(ans[i] == n - 1 && ans[i + 1] == 0){
            k = i;
            break;
        }
    }
    for(int i = k + 1; i < ans.size(); i++){
        euler.push_back(ans[i]);
    }
    for(int i = 0; i <= k; i++){
        euler.push_back(ans[i]);
    }
    for(int i = 0; i < euler.size(); i++){
        cout << euler[i] + 1 << " ";
    }
    return 0;
}
