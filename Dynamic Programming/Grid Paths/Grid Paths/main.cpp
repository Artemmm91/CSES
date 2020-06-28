#include <iostream>
using namespace std;
int mod = 1000000007;

int main() {
    char c;
    int A[1000][1000], B[1000][1000], n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c;
            if(c == '.'){
                A[i][j] = 0;
            }
            else{
                A[i][j] = 1;
            }
        }
    }
    if(A[0][0] == 0){
        B[0][0] = 1;
    }
    else{
        B[0][0] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i!= 0 || j != 0){
                B[i][j] = 0;
                if(A[i][j] == 0){
                    if(i != 0){
                        B[i][j] += B[i - 1][j];
                    }
                    if(j != 0){
                        B[i][j] += B[i][j - 1];
                    }
                    B[i][j] = B[i][j] % mod;
                }
            }
        }
    }
    cout << B[n - 1][n - 1];
    return 0;
}
