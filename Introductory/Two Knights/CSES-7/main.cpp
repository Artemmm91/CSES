#include <iostream>
using namespace std;
#define ll long long

ll func(ll k){
    ll s = k * k;
    return 4*(s - 3) + 8*(s - 4) + 4*(k - 3)*(s - 5) + 4*(k - 4)*(s - 7) + (k - 4)*(k - 4)*(s - 9);
}

int main() {
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        if(i == 1) cout << 0;
        if(i == 2) cout << 6;
        if(i == 3) cout << 28;
        if(i >= 4) cout << func(i) / 2;
        cout << endl;
    }
    return 0;
}
