#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
#define ll long long
#define pll pair<long long, long long>

ll lm = LLONG_MAX;
vector<vector<ll>> g(500, vector<ll>(500, lm));

void floyd(int n){
    for(int k = 0; k < n; k++){ // промежуточная вершина
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(g[i][k] < lm && g[k][j] < lm){
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                    g[j][i] = g[i][j];
                }
            }
        }
    }
}

int main() {
    int n;
    ll m, q, a, b, c;
    cin >> n >> m >> q;
    for(ll i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--; b--;
        g[a][b] = min(c, g[a][b]);
        g[b][a] = g[a][b];
    }
    for(int i = 0; i < n; i++){
        g[i][i] = 0;
    }
    floyd(n);
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        a--; b--;
        if(g[a][b] == lm){
            cout << -1 << endl;
        }
        else{
            cout << g[a][b] << endl;
        }
    }
    return 0;
}
