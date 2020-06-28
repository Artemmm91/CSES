#include <iostream>
#define s(i,b) for(int i=1;i<=b;++i)
using namespace std;

int main() {
    int n, q, a, k, g[200001][30];
    cin >> n >> q;
    s(i, n) cin >> g[i][0];
    s(i, 29) s(j, n) g[j][i] = g[g[j][i - 1]][i - 1];
    s(i, q){
        cin >> a >> k;
        n = 0;
        while(k > 0){
            if(k%2) a = g[a][n];
            n++;
            k = k>>1;
        }
        cout << a << endl;
    }
}
