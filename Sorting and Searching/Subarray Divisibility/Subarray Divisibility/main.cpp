#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll A[200000], n, B[200001], count = 0, x = 0, s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        B[i] = 0;
    }
    for(int i = 0; i < n; i++){
        x = x + A[i];
        s = x % n;
        if(s < 0){
            s += n;
        }
        B[s]++;
    }
    for(int i = 1; i < n; i++){
        x = (B[i] - 1)*B[i];
        x = x/2;
        count += x;
    }
    x = (B[0] + 1)*B[0];
    x = x/2;
    count += x;
    cout << count;
    return 0;
}
