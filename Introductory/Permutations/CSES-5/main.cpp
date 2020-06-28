#include <iostream>
using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    if(n == 1) cout << "1 ";
    if(n == 2) cout << "NO SOLUTION";
    if(n == 3) cout << "NO SOLUTION";
    if(n == 4) cout << "2 4 1 3 ";
    if(n >= 5){
        ll i = n;
        while(i > 0){
            cout << i << " ";
            i -= 2;
        }
        i = n-1;
        while(i > 0){
            cout << i << " ";
            i -= 2;
        }
    }
    return 0;
}
