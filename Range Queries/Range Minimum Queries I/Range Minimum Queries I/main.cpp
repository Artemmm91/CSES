#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int p2(int n){
    int k = 1;
    while(k * 2 <= n){
        k = k * 2;
    }
    return k;
}
int l2(int n){
    return (int) (log(n) / log(2));
}

int main() {
    int a, b, n, q, k;
    vector<vector<int>> arr(0);
    vector<int> v0(0);
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        cin >> a;
        v0.push_back(a);
    }
    arr.push_back(v0);
    int cnt = 0;
    for(int i = 2; i <= n; i*=2){
        cnt++;
        v0.clear();
        for(int j = 0; j <= n - i; j++){
            v0.push_back(min(arr[cnt - 1][j], arr[cnt - 1][j + i / 2]));
        }
        arr.push_back(v0);
    }
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        a--; b--;
        k = l2(b - a + 1);
        cnt = p2(b - a + 1);
        cout << min(arr[k][a], arr[k][b - cnt + 1]) << endl;
    }
    return 0;
}
