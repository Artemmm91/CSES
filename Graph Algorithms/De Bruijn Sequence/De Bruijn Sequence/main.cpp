#include <iostream>
#include <vector>
using namespace std;

int n, k2 = 1, m;

vector<vector<int>> g(100000);
vector<int> ans(0);

pair<int, int> d_f(int a){
    if(a >= k2){
        a = a - k2;
    }
    a = a << 1;
    return{a, a + 1};
}

void dfs_cycle(int x){
    vector<vector<int>> cycles(0);
    int p = x, q = x, c = 0;
    while(!g[x].empty()){
        cycles.push_back({});
        do{
            p = g[q].back();
            g[q].pop_back();
            cycles[c].push_back(p);
            q = p;
        }while(p != x);
        c++;
    }
    for(auto cyc: cycles){
        for(int v: cyc){
            ans.push_back(v);
            dfs_cycle(v);
        }
    }
}

int main() {
    cin >> n;
    if(n == 1){
        cout << "01";
        return 0;
    }
    for(int i = 0; i < n - 2; i++){
        k2 *= 2;
    }
    m = k2 * 2;
    pair<int, int> p;
    for(int i = 0; i < m; i++){
        p = d_f(i);
        g[i].push_back(p.first);
        g[i].push_back(p.second);
    }
    ans.push_back(0);
    dfs_cycle(0);
    for(int i = 0; i < n; i++){
        cout << 0;
    }
    for(int i = 1; i < ans.size() - 1; i++){
        cout << ans[i] % 2;
    }
    return 0;
}
