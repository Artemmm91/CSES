#include <iostream>
using namespace std;

#define ll long long

ll func(ll k){
    if(k % 2 == 0){
        return k/2;
    }
    else{
        return 3*k + 1;
    }
}

int main() {
    ll n;
    cin >> n;
    cout << n << " ";
    while(n != 1){
        n = func(n);
        cout << n << " ";
    }
    return 0;
}
