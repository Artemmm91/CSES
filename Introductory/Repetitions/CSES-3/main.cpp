#include <iostream>
#include <string>
using namespace std;

#define ll long long

int main() {
    ll n, max_rep = -1, rep = 1;
    string s;
    char c_now, c_past='b';
    cin >> s;
    n = s.length();
    for(int i = 0; i < n; i++){
        c_now = s[i];
        if(c_now == c_past){
            rep++;
        }
        else{
            if(rep > max_rep) {
                max_rep = rep;
            }
            rep = 1;
        }
        c_past = c_now;
    }
    if(rep > max_rep) {
        max_rep = rep;
    }
    cout << max_rep;
}

