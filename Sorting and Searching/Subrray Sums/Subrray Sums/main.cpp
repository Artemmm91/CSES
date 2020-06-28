#include <iostream>
#include <set>
#include <map>
using namespace std;
#define ll long long
 
int main() {
    ll n, A[200000], x, s = 0, count = 0;
    multiset<ll> S;
    map<ll, ll> M;
    map<ll, ll> :: iterator it;
    M[0] = 1;
    S.insert(0);
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        s += A[i];
        it = M.find(s - x);
        if(it != M.end()){
            count += it->second;
        }
        it = M.find(s);
        if(it == M.end()){
            M[s] = 1;
        }
        else{
            it->second++;
        }
    }
    cout << count;
    return 0;
}
