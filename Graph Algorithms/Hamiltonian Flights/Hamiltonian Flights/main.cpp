#include <iostream>
#include <vector>
using namespace std;
 
#define mod 1000000007;
 
vector<vector<int>> mask(0);
int pow2[25], n, m, graph[20][20];
 
int main() {
    int a, b;
    long long t;
    cin >> n >> m;
    vector<int> v_0(n, 0);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        graph[a][b]++;
    }
    pow2[0] = 1;
    for(int i = 1; i <= n; i++){
        pow2[i] = 2*pow2[i - 1];
    }
    for(int i = 0; i < pow2[n]; i++){
        if(i % 2 == 0){
            mask.push_back(v_0);
            continue;
        }
        if(i == 1){
            v_0[0] = 1;
            mask.push_back(v_0);
            v_0[0] = 0;
            continue;
        }
        int j = 0, x = i;
        vector<int> s(0), ans(n, 0);
        while(x > 0){
            if(x % 2 == 1){
                s.push_back(j);
            }
            x /= 2;
            j++;
        }
        for(j = 1; j < s.size(); j++){
            t = 0;
            for(int k = 0; k < s.size(); k++){
                if(graph[s[k]][s[j]]){
                    t += (mask[i - pow2[s[j]]][s[k]] * graph[s[k]][s[j]]);
                    t = t % mod;
                }
            }
            ans[s[j]] = (int) t;
        }
        mask.push_back(ans);
    }
    cout << mask[pow2[n] - 1][n - 1];
    return 0;
}
