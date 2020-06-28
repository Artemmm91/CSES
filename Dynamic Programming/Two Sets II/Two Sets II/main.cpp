#include <iostream>
#include <vector>
using namespace std;
int mod = 1000000007;

int main() {
    int n, k, temp;
    cin >> n;
    k = n*(n + 1)/2 + 1;
    vector<int> v_0(k, 0);
    v_0[0] = 1;
    vector<vector<int>> v;
    v.push_back(v_0);
    for(int i = 1; i < n; i++){
        v_0.clear();
        for(int j = 0; j < k; j++){;
            temp = 0;
            temp += v[i - 1][abs(j - i)];
            if(j + i < k){
                temp += v[i - 1][j + i];
            }
            temp = temp % mod;
            v_0.push_back(temp);
        }
        v.push_back(v_0);
    }
    cout << v[n - 1][n];
    return 0;
}
