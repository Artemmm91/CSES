#include <iostream>
#include <string>
using namespace std;
#define ll long long

int main() {
    ll A[26], n, k = -1;
    char c;
    bool fl = true, F = true;
    string l;
    cin >> l;
    n = l.length();
    for(int i = 0; i < 26; i++){
        A[i] = 0;
    }
    for(int i = 0; i < n; i++){
        c = l[i];
        A[c - 'A'] += 1;
    }
    for(int i = 0; i < 26; i++){
        if(A[i] % 2 != 0){
            if(fl == true){
                fl = false;
                k = i;
            }
            else
                F = false;
        }
    }
    if(F == true){
        for(int i = 0; i < 26; i++){
            if(i != k){
                for(int j = 0; j < A[i]/2; j++){
                    c = 'A' + i;
                    cout << c;
                }
            }
        }
        if(fl == false){
            for(int j = 0; j < A[k]; j++){
                c = 'A' + k;
                cout << c;
            }
        }
        for(int i = 25; i >= 0; i--){
            if(i != k){
                for(int j = 0; j < A[i]/2; j++){
                    c = 'A' + i;
                    cout << c;
                }
            }
        }
    }
    else{
        cout << "NO SOLUTION";
    }
    return 0;
}
