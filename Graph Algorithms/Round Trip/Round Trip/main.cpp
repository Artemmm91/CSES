#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

vector<vector<int>> g;
vector<int> p, dist;
vector<bool> visited;
int a_1 = -1, a_2 = -1, min_l = INT_MAX;

void bfs(int x){
    if(!visited[x]){
        queue<int> q;
        q.push(x);
        visited[x] = true;
        dist[x] = 0;
        int t;
        while(!q.empty()){
            t = q.front(); q.pop();
            for(int v: g[t]){
                if(!visited[v]){
                    visited[v] = true;
                    dist[v] = dist[t] + 1;
                    p[v] = t;
                    q.push(v);
                }
                else{
                    if(v != p[t]){
                        if(dist[t] + dist[v] + 1 < min_l){
                            a_1 = v; a_2 = t;
                            min_l = dist[t] + dist[v] + 1;
                            return;
                        }
                    }
                }
            }
        }
    }
}

void print_l(){
    int t = a_1;
    vector<int> v1, v2;
    while(t != -1){
        v1.push_back(t);
        t = p[t];
    }
    t = a_2;
    while(t != -1){
        v2.push_back(t);
        t = p[t];
    }
    
    int i = v1.size() - 1, j = v2.size() - 1;
    while(i > 0 && j > 0){
        if(v1[i] == v2[j] && v1[i - 1] == v2[j - 1]){
            v1.pop_back();
            v2.pop_back();
            i--; j--;
            min_l -= 2;
        }
        else{
            break;
        }
    }
    cout << min_l + 1 << endl;
    
    for(int i = v1.size() - 1; i >= 0; i--){
        cout << v1[i] + 1 << " ";
    }
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] + 1 << " ";
    }
}

int main() {
    int n, m, a, b;
    vector<int> v_0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        g.push_back(v_0);
        p.push_back(-1);
        dist.push_back(-1);
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
        if(min_l != INT_MAX){
            break;
        }
    }
    if(min_l == INT_MAX){
        cout << "IMPOSSIBLE";
    }
    else{
        print_l();
    }
    return 0;
}
