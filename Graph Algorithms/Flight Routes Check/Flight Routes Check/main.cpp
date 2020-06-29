#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph(100000, vector<int>(0)), graph_T(100000, vector<int>(0));
vector<bool> vis(100000, false), vis_T(100000, false);

void dfs(int x){
    vis[x] = true;
    for(int v: graph[x]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void dfs_T(int x){
    vis_T[x] = true;
    for(int v: graph_T[x]){
        if(!vis_T[v]){
            dfs_T(v);
        }
    }
}


int main(){
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m ;i++){
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph_T[b].push_back(a);
    }
    dfs(0);
    dfs_T(0);
    for(int i = 1; i < n; i++){
        if(!vis[i]){
            cout << "NO" << endl << 1 << " " << i + 1;
            return 0;
        }
        if(!vis_T[i]){
            cout << "NO" << endl << i + 1 << " " << 1;
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
