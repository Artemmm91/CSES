#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll A[20], B[20], n, allsum;

void func(){
    ll sum = 0, min_dif = allsum + 2;
    bool fl = true, f = false;
    while (fl){
        ll i = 0;
        sum = 0;
        f = false;
        while(i < n){
            if(B[i] == 1){
                B[i] = 0;
            }
            else{
                B[i] = 1;
                i = n;
                f = true;
            }
            i++;
        }
        if(f == false) fl = false;
        for(int j = 0; j < n; j++){
            if(B[j] == 1) sum+= A[j];
        }
        if(min_dif > abs(allsum - 2*sum)){
            min_dif = abs(allsum - 2*sum);
        }
    }
    cout << min_dif;
}


int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        allsum += A[i];
    }
    func();
    return 0;
}
