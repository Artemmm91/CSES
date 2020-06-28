#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long int A[200000], n;

long long int count_s(long long int p){
    long long int s = 0;
    for(int i = 0; i < n; i++){
        s += (p / A[i]);
    }
    return s;
}

int main() {
    long long int t, left, s_l = 0, s_r = 0, s_p, right = 0, p;
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    long double s = 0, T;
    for(int i = 0; i < n; i++){
        s += (1.0 / A[i]);
    }
    T = t / s;
    T = ceil(T);
    left = (long long int) T;
    s_l = count_s(left);
    if(s_l >= t){
        cout << left;
        return 0;
    }
    for(int i = 0; i < n; i++){
        right = max(right, A[i] - left % A[i]);
    }
    right += left;
    s_r = count_s(right);
    while(right > left + 1){
        p = (left + right) / 2;
        s_p = count_s(p);
        if(t > s_p){
            left = p;
        }
        else{
            right = p;
        }
    }
    cout << right;
    return 0;
}
