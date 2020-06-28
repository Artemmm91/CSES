#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n, sum = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        sum = sum * 2;
        sum = sum % (1000000007);
    }
    cout << sum;
    return 0;
}
