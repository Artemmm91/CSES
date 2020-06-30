#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long


int main() {
    ll n, a, b, A[200001], part[200001], x, k, max_part[200001], sum = 0, max_sum, sum_part[200001];
    set<pair<ll, ll>, greater<pair<ll, ll>>> s;
    cin >> n >> a >> b;
    k = b - a + 1;
    for(ll i = 0; i < n; i++){
        cin >> A[i];
    }
    for(ll i = a - 1; i < n; i++){
        x = A[i];
        part[i - a + 1] = part[i - a] + x;
    }
    for(ll i = 0; i < k; i++){
        s.insert({part[i], i});
    }
    max_part[0] = (*(s.begin())).first;
    for(ll i = 1; i <= n - a; i++){
        s.erase(s.find({part[i - 1], i - 1}));
        if(i + k - 1 <= n - a){
            s.insert({part[i + k - 1], i + k - 1});
        }
        max_part[i] = (*(s.begin())).first - part[i - 1];
    }
    for(ll i = 0; i < a - 1; i++){
        sum += A[i];
    }
    sum_part[0] = sum;
    for(ll i = a - 1; i < n - 1; i++){
        sum += A[i];
        sum -= A[i - a + 1];
        sum_part[i - a + 2] = sum;
    }
    max_sum = sum_part[0] + max_part[0];
    for(ll i = 1; i <= n - a; i++){
        max_sum = max(max_sum, sum_part[i] + max_part[i]);
    }
    cout << max_sum;
    return 0;
}
