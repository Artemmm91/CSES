#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

int s;
vector<vector<int>> g(1010, vector<int>(1010, -1));

bool ff(){
    queue<int> q;
    vector<bool> visited(1010, false);
    vector<int> p(1010, -1);
    visited[0] = true;
    q.push(0);
    int t, x, y, minc = INT_MAX;
    while(!q.empty()){
        t = q.front(); q.pop();
        if(t == s){
            x = p[t];
            y = t;
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
            return true;
        }
        for(int i = 0; i <= s; i++){
            if(!visited[i] && g[t][i] > 0){
                visited[i] = true;
                q.push(i);
                p[i] = t;
            }
        }
    }
    return false;
}

int main() {
    int n, m, k, a, b;
    cin >> n >> m >> k;
    s = n + m + 1;
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        g[a][n + b] = 1;
        g[n + b][a] = 0;
    }
    for(int i = 1; i <= n; i++){
        g[0][i] = 1;
        g[i][0] = 0;
    }
    for(int i = 1; i <= m; i++){
        g[s][n + i] = 0;
        g[n + i][s] = 1;
    }
    while(ff()){}
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(g[i][0] > 0){
            cnt += g[i][0];
        }
    }
    cout << cnt << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(g[i][j + n] == 0){
                cout << i << " " << j << endl;
                break;
            }
        }
    }
    return 0;
}
