#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n, max_el = -1, sum = 0, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x > max_el){
            max_el = x;
        }
        else{
            sum += (max_el - x);
        }
    }
    cout << sum;
    return 0;
}
