#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, cnt = 0;
vector<vector<int>> g;
vector<bool> visited;
vector<int> ans;

void bfs(int x){
    if(!visited[x]){
        cnt++;
        visited[x] = true;
        ans.push_back(x);
        queue<int> q;
        q.push(x);
        int t;
        while(q.size() != 0){
            t = q.front();
            q.pop();
            for(auto v: g[t]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
}

int main() {
    vector<int> v;
    int a, b;
    v.clear();
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        g.push_back(v);
        visited.push_back(false);
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
    cout << ans.size() - 1 << endl;
    for(int i = 0; i < ans.size() - 1; i++){
        cout << ans[i] + 1 << " " << ans[i + 1] + 1<< endl;
    }
    return 0;
}
