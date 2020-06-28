#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    ll n, x, y;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        if(x < y) swap(x, y);
        if(x > 2*y){
            cout << "NO" << endl;
        }
        else{
            if((2*y - x) % 3 == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
