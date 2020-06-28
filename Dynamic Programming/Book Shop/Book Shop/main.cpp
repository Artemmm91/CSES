#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x, S[1000], H[1000], temp;
    vector<vector<int>> v;
    cin >> n >> x;
    vector<int> v_0(x + 1, 0);
    v.push_back(v_0);
    for(int i = 0; i < n; i++){
        cin >> H[i];
    }
    for(int i = 0; i < n; i++){
        cin >> S[i];
    }
    for(int i = 1; i <= n; i++){
        v_0.clear();
        for(int j = 0; j <= x; j++){
            if(j >= H[i - 1]){
                temp = max(v[i - 1][j], v[i - 1][j - H[i - 1]] + S[i - 1]);
            }
            else{
                temp = v[i - 1][j];
            }
            v_0.push_back(temp);
        }
        v.push_back(v_0);
    }
    cout << v[n][x];
    return 0;
}
