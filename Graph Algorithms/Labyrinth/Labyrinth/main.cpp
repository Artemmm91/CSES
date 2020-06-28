#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int k = 0, cnt = 1;
vector<vector<int>> g;
vector<bool> visited;
vector<int> past, ans;

void bfs(int x){
    if(!visited[x]){
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
                    past[v] = t;
                    q.push(v);
                }
            }
        }
    }
}

void find_way(int b){
    if(past[b] != -1){
        find_way(past[b]);
        ans.push_back(past[b]);
    }
}

void count_way(int b){
    if(past[b] != -1){
        count_way(past[b]);
        cnt++;
    }
}

int main() {
    char c;
    int n, m, a = 0, b = 0;
    vector<vector<int>> v;
    vector<int> v_0;
    vector<pair<int, int>> coord;
    pair<int, int> p;
    cin >> n >> m;
    for(int i = 0; i < n ; i++){
        v_0.clear();
        for(int j = 0; j < m; j++){
            cin >> c;
            if (c == '.' || c == 'A' || c == 'B'){
                if(c == 'A'){
                    a = k;
                }
                if(c == 'B'){
                    b = k;
                }
                p.first = i;
                p.second = j;
                coord.push_back(p);
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
        past.push_back(-1);
    }
    bfs(a);
    if(visited[b] == false){
        cout << "NO";
    }
    else{
        cout << "YES" << endl;
        count_way(b);
        cout << cnt - 1 << endl;
        find_way(b);
        ans.push_back(b);
        for(int i = 1; i < cnt; i++){
            if(coord[ans[i - 1]].first == coord[ans[i]].first + 1){
                cout << "U";
            }
            if(coord[ans[i - 1]].first == coord[ans[i]].first - 1){
                cout << "D";
            }
            if(coord[ans[i - 1]].second == coord[ans[i]].second + 1){
                cout << "L";
            }
            if(coord[ans[i - 1]].second == coord[ans[i]].second - 1){
                cout << "R";
            }
        }
    }
    return 0;
}
