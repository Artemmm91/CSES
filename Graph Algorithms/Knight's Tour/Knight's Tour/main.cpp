#include <iostream>
#include <vector>
using namespace std;

int graph[64][64], path[64], coord[8][8];
bool visited[64];
pair<int, int> delta[8] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1},{1, -2}, {2, -1},{-1, -2}, {-2, -1}};

int deg(int x){
    int cnt = 0;
    for(int i = 0; i < 64; i++){
        if(i != x && graph[i][x] != 0 && !visited[i]){
            cnt++;
        }
    }
    return cnt;
}
 
vector<int> min_deg(int x){
    vector<int> ans(0);
    int md = 10, d = -1, dd;
    for(int i = 0; i < 64; i++){
        if(i != x && graph[i][x] != 0 && !visited[i]){
            dd = deg(i);
            if(dd < md){
                ans.clear();
                md = dd;
                d = i;
                ans.push_back(d);
            }
            else{
                if(dd == md){
                    ans.push_back(i);
                }
            }
        }
    }
    return ans;
}

bool ham(int pos){
    vector<int> d;
    if(pos == 64){
        return true;
    }
    d = min_deg(path[pos - 1]);
    for(auto v: d){
        path[pos] = v;
        visited[v] = true;
        if(ham(pos + 1)){
            return true;
        }
        path[pos] = -1;
        visited[v] = false;
    }
    return false;
}

int main() {
    int x, y, x1, y1;
    for(int i = 0; i < 64; i++){
        path[i] = -1;
        visited[i] = false;
        x = i / 8;
        y = i % 8;
        for(auto v: delta){
            x1 = x + v.first;
            y1 = y + v.second;
            if(x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8){
                graph[i][8*x1 + y1] = 1;
                graph[8*x1 + y1][i] = 1;
            }
        }
    }
    cin >> x >> y;
    x--; y--;
    path[0] = 8*x + y;
    coord[x][y] = 1;
    visited[8*x + y] = true;
    if(!ham(1)){
        cout << -1;
        return 0;
    }
    for(int i = 1; i < 64; i++){
        coord[path[i] / 8][path[i] % 8] = i + 1;
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << coord[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
