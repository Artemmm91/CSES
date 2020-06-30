#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

vector<pair<int, int>> g_n(100000);
vector<pair<vector<int>, vector<int>>> g_m(100001, {{}, {}});
vector<int> ans(100001, -1);
vector<bool> done(100000, false);
int n, m;

bool bfs(int x, int r){
    queue<pair<int, int>> q;
    vector<int> pr_ans(100001, -1);
    vector<bool> pr_done(100000, false);
    int v, res, pa, pb;
    q.push({x, r});
    while(!q.empty()){
        tie(v, res) = q.front();
        q.pop();
        if((ans[v] != -1 && ans[v] != res) || (pr_ans[v] != -1 && pr_ans[v] != res)){
            return false;
        }
        pr_ans[v] = res;
        if(res == 1){
            for(int p: g_m[v].first){
                if(!done[p] && !pr_done[p]){
                    pr_done[p] = true;
                }
            }
            for(int p: g_m[v].second){
                if(!done[p] && !pr_done[p]){
                    pr_done[p] = true;
                    tie(pa, pb) = g_n[p];
                    if(pa != (0 - v)){
                        swap(pa, pb);
                    }
                    if(pb > 0){
                        q.push({pb, 1});
                    }
                    else{
                        q.push({(0-pb), 0});
                    }
                }
            }
        }
        else{
            for(int p: g_m[v].second){
                if(!done[p] && !pr_done[p]){
                    pr_done[p] = true;
                }
            }
            for(int p: g_m[v].first){
                if(!done[p] && !pr_done[p]){
                    pr_done[p] = true;
                    tie(pa, pb) = g_n[p];
                    if(pa != v){
                        swap(pa, pb);
                    }
                    if(pb > 0){
                        q.push({pb, 1});
                    }
                    else{
                        q.push({(0-pb), 0});
                    }
                }
            }
        }
    }
    for(int i = 1; i <= m; i++){
        if(pr_ans[i] != -1){
            ans[i] = pr_ans[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(pr_done[i]){
            done[i] = true;
        }
    }
    return true;
}

int main() {
    int a, b;
    char c;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> c >> a;
        if(c == '-'){
            g_m[a].second.push_back(i);
            a = 0 - a;
        }
        else{
            g_m[a].first.push_back(i);
        }
        cin >> c >> b;
        if(c == '-'){
            g_m[b].second.push_back(i);
            b = 0 - b;
        }
        else{
            g_m[b].first.push_back(i);
        }
        g_n[i] = {a, b};
    }
    for(int i = 1; i <= m; i++){
        if(g_m[i].first.size() == 0){
            ans[i] = 0;
            for(int p: g_m[i].second){
                done[p] = true;;
            }
        }
        if(g_m[i].second.size() == 0){
            ans[i] = 1;
            for(int p: g_m[i].first){
                done[p] = true;;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        if(ans[i] == -1){
            if(bfs(i, 1)){
                continue;
            }
            if(bfs(i, 0)){
                continue;
            }
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for(int i = 1; i <= m; i++){
        if(ans[i] == 1){
            cout << "+ ";
        }
        else{
            cout << "- ";
        }
    }
    return 0;
}
