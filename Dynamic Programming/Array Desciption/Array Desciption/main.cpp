#include <iostream>
#include <vector>
using namespace std;
long int mod = 1000000007;

int main() {
    long int n, A[100000], m, temp;
    cin >> n >> m;
    vector<vector<long int>> v;
    for(long int i = 0; i < n; i++){
        cin >> A[i];
    }
    vector<long int> v_0(m + 1, 1);
    v_0[0] = 0;
    if(A[0] != 0){
        for(long int i = 1; i <= m; i++){
            if(i != A[0]){
                v_0[i] = 0;
            }
            else{
                v_0[i] = 1;
            }
        }
    }
    v.push_back(v_0);
    for(long int i = 1; i < n; i++){
        v_0.clear();
        v_0.push_back(0);
        if(A[i] == 0){
            for(long int j = 1; j < m; j++){
                temp = v[i - 1][j - 1] + v[i - 1][j] + v[i - 1][j + 1];
                temp = temp % mod;
                v_0.push_back(temp);
            }
            temp = v[i - 1][m - 1] + v[i - 1][m];
            temp = temp % mod;
            v_0.push_back(temp);
        }
        else{
            for(long int j = 1; j <=m; j++){
                if(j != A[i]){
                    v_0.push_back(0);
                }
                else{
                    if(j != m){
                        temp = v[i - 1][j - 1] + v[i - 1][j] + v[i - 1][j + 1];
                        temp = temp % mod;
                    }
                    else{
                        temp = v[i - 1][m - 1] + v[i - 1][m];
                        temp = temp % mod;
                    }
                    v_0.push_back(temp);
                }
            }
        }
        v.push_back(v_0);
    }
    long int sum = 0;
    for(long int i = 1; i <= m; i++){
        sum += v[n - 1][i];
        sum = sum % mod;
    }
    cout << sum;
    return 0;
}
