#include <iostream>
#include <vector>
using namespace std;

int eul_i, depth = 0, timer = 0, comp = 0, n;
int succ[200000], v_depth[400000], time_in[400000], time_out[400000];
bool visited[200000], vis_eul[200000];
vector<vector<int>> graph(200000, vector<int>(0)), cycles(0);
pair<int, int> coord[200000];

void dfs_init(int x){
    int t = x, q = x, i = 0, prev = -1, pprev = -1;
    pair<int, int> p;
    while(visited[t] == false){
        visited[t] = true;
        t = succ[t];
    }
    p = coord[t];
    if(p.first == -1){
        while(q != t){
            prev = q;
            coord[q] = {comp, -1};
            q = succ[q];
        }
        if(prev != -1){
            if(n + comp >= graph.size()){
                graph.push_back({prev});
            }
            else{
                graph[n + comp].push_back(prev);
            }
        }
        else{
            if(n + comp >= graph.size()){
                graph.push_back({});
            }
        }
        cycles.push_back({});
        do{
            coord[q] = {comp, i};
            cycles[comp].push_back(q);
            i++;
            q = succ[q];
        }while(q != t);
        comp++;
    }
    else{
        if(p.second >= 0){
            while(q != t){
                pprev = q;
                coord[q] = {p.first, 0 - p.second - 1};
                q = succ[q];
            }
            graph[n + p.first].push_back(pprev);
        }
        
        else{
            while(q != t){
                coord[q] = p;
                q = succ[q];
            }
        }
    }
}

void dfs_euler(int x){
    time_in[x] = timer++;
    v_depth[x] = depth++;
    vis_eul[x] = true;
    for(int v: graph[x]){
        if(!vis_eul[v]){
            dfs_euler(v);
        }
    }
    depth--;
    time_out[x] = timer++;
}

int main(){
    int q, a, b, h;
    pair<int, int> pa, pb;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> succ[i];
        succ[i]--;
        graph[succ[i]].push_back(i);
        coord[i] = {-1, -2};
        visited[i] = false;
    }
    for(int i = 0; i < n; i++){
        if(graph[i].size() == 0){
            dfs_init(i);
        }
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs_init(i);
        }
    }
    for(int i = 0; i < comp; i++){
        dfs_euler(n + i);
    }
    while(q--){
        cin >> a >> b;
        a--; b--;
        pa = coord[a];
        pb = coord[b];
        if(pa.first != pb.first){
            cout << -1 << endl;
            continue;
        }
        if(pa.second < 0 && pb.second < 0){
            if(time_in[a] >= time_in[b] && time_out[a] <= time_out[b]){
                cout << v_depth[a] - v_depth[b] << endl;
            }
            else{
                cout << -1 << endl;
            }
            continue;
        }
        if(pa.second < 0 && pb.second >= 0){
            h = 0 - pa.second - 1;
            if(pb.second >= h){
                cout << pb.second - h + v_depth[a] << endl;
            }
            else{
                cout << cycles[pa.first].size() + pb.second - h + v_depth[a] << endl;
            }
            continue;
        }
        if(pa.second >= 0 && pb.second >= 0){
            if(pb.second >= pa.second){
                cout << pb.second - pa.second << endl;
            }
            else{
                cout << cycles[pa.first].size() + pb.second - pa.second << endl;
            }
            continue;
        }
        cout << -1 << endl;
    }
    return 0;
}
