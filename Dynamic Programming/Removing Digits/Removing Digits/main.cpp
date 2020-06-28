#include <iostream>
#include <algorithm>
using namespace std;

int func(int n){
    int a = n, max_a = -1;
    while(a > 0){
        max_a = max(max_a, a % 10);
        a = a / 10;
    }
    return n - max_a;
}

int main() {
    int n, cnt = 0;
    cin >> n;
    while(n > 0){
        n = func(n);
        cnt++;
    }
    cout << cnt;
    return 0;
}
