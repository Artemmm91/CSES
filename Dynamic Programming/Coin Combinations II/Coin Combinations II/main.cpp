#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int mod = 1000000007;

int main() {
    int n, x, A[100];
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    vector<int> v(x + 1, 0);
    v[0] = 1;
    int k;
    for(int i = 0; i < n; i++){
        k = A[i];
        for(int j = k; j <= x; j++){
            if(v[j - k] != 0){
                v[j] = v[j] + v[j - k];
                v[j] = v[j] % mod;
            }
        }
    }
    cout << v[x];
    return 0;
}
