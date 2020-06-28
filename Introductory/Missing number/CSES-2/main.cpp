#include <iostream>
using namespace std;

#define ll long long

int main() {
    ll n, x;
    cin >> n;
    ll  sum = n*(n + 1)/2;
    for(int i = 0; i < n - 1; i++){
        cin >> x;
        sum -= x;
    }
    cout << sum;
    return 0;
}
