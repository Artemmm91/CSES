#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> g;
vector<int> color;
bool fl = true;

void bfs(int x){
    if(color[x] == -1){
        queue<int> q;
        q.push(x);
        color[x] = 0;
        int t;
        while(q.size() != 0){
            t = q.front();
            q.pop();
            for(int v: g[t]){
                if(color[v] == -1){
                    q.push(v);
                    color[v] = (color[t] + 1) % 2;
                }
                else{
                    if(color[t] == color[v]){
                        fl = false;
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    int n, m, a, b;
    vector<int> v_0(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        g.push_back(v_0);
        color.push_back(-1);
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        bfs(i);
    }
    if(fl == false){
        cout << "IMPOSSIBLE";
    }
    else{
        for(int i = 0; i < n; i++){
            cout << color[i] + 1 << " ";
        }
    }
    return 0;
}
