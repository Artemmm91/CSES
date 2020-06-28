#include <iostream>
using namespace std;
#define ll long long

ll A[200000], n, k;

bool func(ll sum){
    ll c_s = 0, numb = 0;
    for(int i = 0; i < n; i++){
        if(c_s + A[i] > sum){
            c_s = A[i];
            if(A[i] > sum) return false;
            numb++;
        }
        else{
            c_s += A[i];
        }
    }
    if(c_s != 0) numb++;
    if(numb > k) return false;
    return true;
}

int main() {
    ll sum = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        sum += A[i];
    }
    ll l = 0, r = sum, p;
    while(l + 1 < r){
        p = (l + r)/2;
        if(func(p) == true){
            r = p;
        }
        else{
            l = p;
        }
    }
    cout << r;
    return 0;
}
