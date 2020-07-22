#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> g(500, vector<int>(500, -1)), g1(500, vector<int>(500, -1));

bool ff(){
    queue<int> q;
    vector<int> p(500, -1);
    vector<bool> visited(500, false);
    q.push(0);
    bool fl = false;
    visited[0] = true;
    int t, x, y, minc = INT_MAX;
    while(!q.empty()){
        t = q.front(); q.pop();
        if(t == n - 1){
            x = p[t]; y = t;
            while(x != -1){
                minc = min(minc, g[x][y]);
                y = x; x = p[y];
            }
            x = p[t]; y = t;
            while(x != -1){
                g[x][y] -= minc;
                g[y][x] += minc;
                y = x; x = p[y];
            }
                
            fl = true;
        }
        for(int i = 0; i < n; i++){
            if(!visited[i] && g[t][i] > 0){
                visited[i] = true;
                p[i] = t;
                q.push(i);
            }
        }
    }
    return fl;
}

int main() {
    int a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        if(a != n - 1 && b != 0){
            if(g[a][b] == -1){
                g[a][b] = 1;
                g[b][a] = 0;
            }
            else{
                g[a][b] = 1;
            }
            g1[a][b] = 1;
        }
    }
    while(ff()){}
    vector<queue<int>> next(500);
    for(int i = 1; i < n - 1; i++){
        for(int j = 0; j < n; j++){
            if(g[j][i] > 0 && g1[i][j] == 1){
                next[i].push(j);
            }
        }
    }
    int cnt = 0;
    vector<int> ans(0), q(0);
    for(int i = 0; i < n; i++){
        if(g[i][0] > 0){
            cnt += g[i][0];
            ans.push_back(i);
        }
    }
    cout << cnt << endl;
    int f;
    for(int v: ans){
        q.clear();
        q.push_back(1);
        while(v != n - 1){
            q.push_back(v + 1);
            f = v;
            v = next[v].front();
            next[f].pop();
        }
        q.push_back(n);
        cout << q.size() << endl;
        for(int vv: q){
            cout << vv << " ";
        }
        cout << endl;
    }
    return 0;
}
