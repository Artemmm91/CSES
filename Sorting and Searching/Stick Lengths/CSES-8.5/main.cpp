#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int n, A[200000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    sort(A, A + n);
    int k = A[n / 2];
    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += abs(A[i] - k);
    }
    cout << sum;
    return 0;
}
