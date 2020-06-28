#include <iostream>
#include <vector>
using namespace std;
#define ll long long

vector<vector<ll>> g(100000, vector<ll>(0));
vector<ll> color(100000, 0), p(100000, -1);

void print_ans(ll x){
    vector<ll> ans(0);
    ll t = x;
    do{
        ans.push_back(t);
        t = p[t];
    }while(t != x);
    ans.push_back(x);
    cout << ans.size() << endl;
    for(ll i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] + 1 << " ";
    }
}

bool dfs(ll x){
    color[x] = 1;
    for(auto v: g[x]){
        if(color[v] == 0){
            p[v] = x;
            if(dfs(v)){
                return true;
            }
        }
        else if(color[v] == 1){
            p[v] = x;
            print_ans(v);
            return true;
        }
    }
    color[x] = 2;
    return false;
}

int main() {
    ll n, m, a, b;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    bool fl = true;;
    for(ll i = 0; i < n; i++){
        if(color[i] == 0){
            if(!dfs(i)){
                fl = false;
            }
            else{
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
