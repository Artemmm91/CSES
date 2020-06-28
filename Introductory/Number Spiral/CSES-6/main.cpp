#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long

ll func(ll r, ll c){
    ll numb = max(r, c) - 1, ans = numb*numb;
    if (numb % 2 == 0){
        ans = c + ans + numb + 1 - r;
    }
    else{
        ans = r + ans + numb + 1 - c;
    }
    return ans;
}

int main() {
    ll t, x, y;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> x >> y;
        cout << func(x, y) << endl;
    }
    return 0;
}
