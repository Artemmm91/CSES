#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cnt = 0, k = 0;
vector<vector<int>> g;
vector<bool> visited;

void bfs(int x){
    if(!visited[x]){
        cnt++;
        visited[x] = true;
        queue<int> q;
        q.push(x);
        int t;
        while(q.size() != 0){
            t = q.front();
            q.pop();
            for(auto v : g[t]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int main() {
    char c;
    int n, m;
    vector<vector<int>> v;
    vector<int> v_0;
    cin >> n >> m;
    for(int i = 0; i < n ; i++){
        v_0.clear();
        for(int j = 0; j < m; j++){
            cin >> c;
            if (c == '.'){
                v_0.push_back(k);
                k++;
            }
            else{
                v_0.push_back(-1);
            }
        }
        v.push_back(v_0);
    }
    vector<int> vv;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] != -1){
                vv.clear();
                if(j != 0){
                    if(v[i][j - 1] != -1){
                        vv.push_back(v[i][j - 1]);
                    }
                }
                if(j != m - 1){
                    if(v[i][j + 1] != -1){
                        vv.push_back(v[i][j + 1]);
                    }
                }
                if(i != 0){
                    if(v[i - 1][j] != -1){
                        vv.push_back(v[i - 1][j]);
                    }
                }
                if(i != n - 1){
                    if(v[i + 1][j] != -1){
                        vv.push_back(v[i + 1][j]);
                    }
                }
                g.push_back(vv);
            }
        }
    }
    for(int i = 0; i < k; i++){
        visited.push_back(false);
    }
    for(int i = 0; i < k; i++){
        bfs(i);
    }
    cout << cnt;
    return 0;
}
