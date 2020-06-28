#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long


int main() {
    ll n, k, A[200000], B[200000], median = 0;
    cin >> n >> k;
    multiset<ll> Less, More;
    multiset<ll> :: iterator it;
    for(int i = 0; i < n; i++){
        cin >> B[i];
        A[i] = B[i];
    }
    sort(B, B+k);
    for(ll i = 0; i < k / 2; i++){
        Less.insert(B[i]);
    }
    for(ll i = k / 2; i < k; i++){
        More.insert(B[i]);
    }
    if(k % 2 == 0){
        median = *Less.rbegin();
    }
    else{
        median = *More.begin();
    }
    cout << median << " ";
    ll temp;
    
    for(int i = 0; i < n - k; i++){
        if(A[i + k] >= median){
            More.insert(A[i + k]);
            it = Less.find(A[i]);
            if(it != Less.end()){
                Less.erase(it);
                temp = *More.begin();
                More.erase(More.begin());
                Less.insert(temp);
            }
            else{
                More.erase(More.find(A[i]));
            }
        }
        else{
            Less.insert(A[i + k]);
            it = Less.find(A[i]);
            if(it != Less.end()){
                Less.erase(it);
            }
            else{
                More.erase(More.find(A[i]));
                temp = *Less.rbegin();
                Less.erase(Less.find(temp));
                More.insert(temp);
            }
        }
        if(k % 2 == 0)
            median = *Less.rbegin();
        else
            median = *More.begin();
        cout << median << " ";
    }
    return 0;
}
