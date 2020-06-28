#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
 
bool func(ll a, ll b, ll c, ll d){
    if(a != d && a != c  && b != c && b != d){
        cout << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1;
        return true;
    }
    return false;
}


int main() {
    ll n, x, k = 0, sum;
    pair<ll, pair<ll, ll>> B[500000];
    pair<ll, ll> A[1000];
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    for(ll i = 0; i < n - 1; i++){
        for(ll j = i + 1; j < n; j++){
            B[k].first = A[i].first + A[j].first;
            B[k].second.first = i;
            B[k].second.second = j;
            k++;
        }
    }
    sort(B, B + k);
    bool fl;
    ll l, r;
    for(ll i = 0; i < k - 1; i++){
        l = i + 1;
        r = k;
        sum = x - B[i].first;
        if(sum <= 0) break;
        while(l < r){
            ll p = (l + r)/2;
            if(B[p].first == sum){
                ll j = p;
                while(j < k && B[j].first == sum){
                    fl = func(B[i].second.first, B[i].second.second, B[j].second.first, B[j].second.second);
                    if(fl) return 0;
                    j++;
                }
                j = p;
                while(j >= 0 && B[j].first == sum){
                    fl = func(B[i].second.first, B[i].second.second, B[j].second.first, B[j].second.second);
                    if(fl) return 0;
                    j--;
                }
            }
            if(B[p].first > sum){
                r = p;
            }
            else{
                if(l == p) l = r;
                else l = p;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
