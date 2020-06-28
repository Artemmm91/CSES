#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long int n, x, a = 0, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        a = max(x, a);
        sum += x;
    }
    if(a <= sum - a){
        cout << sum;
    }
    else{
        cout << 2 * a;
    }
}
