#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll n, sum;
    cin >> n;
    if(n % 4 == 1 || n % 4 == 2) cout << "NO";
    else{
        cout << "YES" << endl;
        ll i = n;
        if(n % 4 == 0){
            cout << n / 2 << endl;
            while(i > 0){
                if(i % 4 == 0) cout << i << " ";
                if(i % 4 == 1) cout << i << " ";
                i--;
            }
            cout << endl << n/2 << endl;
            i = n;
            while(i > 0){
                if(i % 4 == 2) cout << i << " ";
                if(i % 4 == 3) cout << i << " ";
                i--;
            }
        }
        else{
            cout << n/2 + 1 << endl;
            while(i > 3){
                if(i % 4 == 0) cout << i << " ";
                if(i % 4 == 3) cout << i << " ";
                i--;
            }
            cout << 1 << " " << 2 << endl << n/2 << endl;
            i = n;
            while(i > 3){
                if(i % 4 == 1) cout << i << " ";
                if(i % 4 == 2) cout << i << " ";
                i--;
            }
            cout << 3;
        }
    }
    return 0;
}
