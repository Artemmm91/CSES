#include <iostream>
#include <set>
#include <limits.h>
using namespace std;

int func(int S[], int j, int x){
    int l, r, p;
    l = 0; r = j;
    while(l <= r){
        p = (l + r) / 2;
        if(l == r){
            if(S[l] <= x){
                return l;
            }
            else{
                return -1;
            }
        }
        if(S[p] > x){
            r = p - 1;
        }
        else{
            if(S[p + 1] <= x){
                l = p + 1;
            }
            else{
                return p;
            }
        }
    }
    return -1;
}

int main() {
    int n, A[200000], S[200010], x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    S[0] = -INT_MAX;
    for(int i = 1; i < 200010; i++){
        S[i] = INT_MAX;
    }
    for(int i = 0; i < n; i++){
        x = func(S, n, A[i]);
        if(x != -1 && S[x + 1] > A[i]){
            S[x + 1] = A[i];
        }
    }
    for(int i = 0; i <= n + 1; i++){
        if(S[i] == INT_MAX){
            cout << i - 1;
            break;
        }
    }
    return 0;
}
