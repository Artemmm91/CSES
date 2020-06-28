#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    ll n, A[200000], S[200000], max_s = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    S[0] = A[0]; max_s = S[0];
    for(int i = 1; i < n; i++){
        S[i] = max(A[i], A[i] + S[i - 1]);
        max_s = max(S[i], max_s);
    }
    cout << max_s;
}
