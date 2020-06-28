#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
#include <algorithm>
using namespace std;

int main() {
    int n, A[200000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    vector<int> v(n + 1, INT_MAX);
    vector<int> :: iterator temp;
    v[0] = -1;
    for(int i = 0; i < n; i++){
        temp = (upper_bound(v.begin(), v.end(), A[i]));
        if(*(temp - 1) < A[i] && *(temp) > A[i]){
            *(temp) = A[i];
        }
    }
    if(v[n] != INT_MAX){
        cout << n;
    }
    else{
        for(int i = 0; i < n - 1; i++){
            if(v[i + 1] == INT_MAX){
                cout << i;
                break;
            }
        }
    }
    return 0;
}
