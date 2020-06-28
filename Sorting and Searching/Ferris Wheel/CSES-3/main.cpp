#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
 

 
int main() {
    int n, x, A[200000];
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    sort(A, A+n);
    int i = 0, c = 0;
    for(int j = n - 1; j >= i; j--){
        if(i == j){
            c++;
            continue;
        }
        if(A[i] + A[j] <= x){
            i++;
        }
        c++;
    }
    cout << c;
    return 0;
}
