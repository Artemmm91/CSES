#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, A[500][500], temp;
    cin >> a >> b;
    A[0][0] = 0;
    for(int i = 0; i < b; i++){
        for(int j = 0; j < a; j++){
            if(i == j){
                A[i][j] = 0;
            }
            else{
                A[i][j] = -1;
                for(int x = 1; x <= (i + 1)/2; x++){
                    temp = A[x - 1][j] + A[i - x][j] + 1;
                    if(A[i][j] == -1){
                        A[i][j] = temp;
                    }
                    else{
                        A[i][j] = min(A[i][j], temp);
                    }
                }
                for(int x = 1; x <= (j + 1)/2; x++){
                    temp = A[i][x - 1] + A[i][j - x] + 1;
                    if(A[i][j] == -1){
                        A[i][j] = temp;
                    }
                    else{
                        A[i][j] = min(A[i][j], temp);
                    }
                }
            }
        }
    }
    cout << A[b - 1][a - 1];
    return 0;
}
