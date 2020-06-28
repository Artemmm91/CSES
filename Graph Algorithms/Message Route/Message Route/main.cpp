#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> g;
vector<int> past, dist;
vector<bool> visited;

void bfs(int x){
    if(!visited[x]){
        queue<int> q;
        q.push(x);
        visited[x] = true;
        dist[x] = 0;
        int t;
        while(q.size() != 0){
            t = q.front();
            q.pop();
            for(int v: g[t]){
                if(!visited[v]){
                    visited[v] = true;
                    past[v] = t;
                    dist[v] = dist[t] + 1;
                    q.push(v);
                }
            }
        }
    }
}

void print_arr(int x){
    if(past[x] == -1){
        cout << x + 1 << " ";
        return;
    }
    print_arr(past[x]);
    cout << x + 1 << " ";
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    vector<int> v_0(0);
    for(int i = 0; i < n; i++){
        g.push_back(v_0);
        visited.push_back(false);
        past.push_back(-1);
        dist.push_back(-1);
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(0);
    if(visited[n - 1] == false){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << dist[n - 1] + 1 << endl;
        print_arr(n - 1);
    }
    return 0;
}
