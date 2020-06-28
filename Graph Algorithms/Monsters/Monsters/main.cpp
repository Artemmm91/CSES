#include <vector>
#include <iostream>
#include <queue>
#include <limits.h>
#include <string>
using namespace std;
#define f first
#define s second
#define vec vector
#define pii pair<int, int>

int n, m;
vec<vec<int>> v(1000, vec<int>(1000, INT_MAX));
vec<vec<vec<int>>> dist(2, vec<vec<int>>(1000, vec<int>(1000, INT_MAX)));
vec<vec<vec<bool>>> visited(2, vec<vec<bool>>(1000, vec<bool>(1000, false)));
vec<vec<string>> path(1000, vec<string>(1000, ""));
vec<vec<pii>> cells(2, vec<pii>()), past(1000, vec<pii>(1000, {-1, -1}));
vec<pair<pii, char>> delta({{{1, 0}, 'D'}, {{-1, 0}, 'U'}, {{0, 1}, 'R'}, {{0, -1}, 'L'}});

bool valid(pii p){
    if(p.f < n && p.f >= 0 && p.s < m && p.s >= 0 && v[p.f][p.s] != -1) return true;
    return false;
}

void bfs(int type){
    queue<pii> q;
    for(auto v: cells[type]){
        q.push(v);
        visited[type][v.f][v.s] = true;
        dist[type][v.f][v.s] = 0;
    }
    pii p, t;
    while(!q.empty()){
        p = q.front();
        q.pop();
        for(auto dir : delta){
            t = {p.f + dir.f.f, p.s + dir.f.s};
            if(valid(t) && !visited[type][t.f][t.s]){
                visited[type][t.f][t.s] = true;
                dist[type][t.f][t.s] = dist[type][p.f][p.s] + 1;
                if(!type){
                    past[t.f][t.s] = p;
                }
                q.push(t);
            }
        }
    }
}

void print_ans(int i, int j){
    pii p = {i, j}, pr;
    string l = "";
    while(p.f != -1){
        pr = past[p.f][p.s];
        if(pr.f == -1){
            break;
        }
        for(auto dir: delta){
            if (p.f - pr.f == dir.f.f && p.s - pr.s == dir.f.s){
                l += dir.s;
                p.f = pr.f;
                p.s = pr.s;
                break;
            }
        }
    }
    for(int f = l.size() - 1; f >= 0; f--){
        cout << l[f];
    }
}

bool ans(int i, int j){
    if(visited[0][i][j] && dist[0][i][j] < dist[1][i][j]){
        cout << "YES" << endl << dist[0][i][j] << endl;
        print_ans(i, j);
        return true;
    }
    return false;
}

int main(){
    cin >> n >> m;
    char c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c;
            if(c == '#'){
                v[i][j] = -1;
            }
            else {
                if(c == 'A'){
                    cells[0].push_back({i, j});
                    if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                        cout << "YES" << endl << 0;
                        return 0;
                    }
                }
                else if(c == 'M'){
                    cells[1].push_back({i, j});
                }
                v[i][j] = 0;
            }
        }
    }
    bfs(0);
    bfs(1);
    for(int i = 0; i < n; i += (n - 1)){
        for(int j = 0; j < m; j++){
            if(ans(i, j)){
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j+=(m - 1)){
            if(ans(i, j)){
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
