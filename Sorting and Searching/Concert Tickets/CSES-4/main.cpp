#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    multiset<int> s;
    int n, m, x, A[200000];
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x;
        s.insert(x);
    }
    for(int i = 0; i < m; i++){
        cin >> A[i];
    }
    for(int i = 0; i < m; i++){
        if(s.begin() == s.upper_bound(A[i])){
            cout << -1 << endl;
        }
        else{
            cout << *(--s.upper_bound(A[i])) << endl;
            s.erase(--s.upper_bound(A[i]));
        }
    }
    return 0;
}
