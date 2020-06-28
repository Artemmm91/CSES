#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> g(100000, vector<int>(0));
vector<int> color(100000, 0);
vector<pair<int, int>> time_out(100000, {-1, 0});
int timer = 0;

bool dfs(int x){
    color[x] = 1;
    timer++;
    for(int v: g[x]){
        if(color[v] == 0){
            if(dfs(v)){
                return true;
            }
        }
        else if(color[v] == 1){
            return true;
        }
    }
    time_out[x].first = timer;
    time_out[x].second = x;
    timer++;
    color[x] = 2;
    return false;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    for(int i = 0; i < n; i++){
        time_out[i].second = i;
        if(color[i] == 0){
            if(dfs(i)){
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    sort(time_out.begin(), time_out.end(), greater<pair<int, int>>());
    for(int i = 0; i < n; i++){
        cout << time_out[i].second + 1 << " ";
    }
    return 0;
}
