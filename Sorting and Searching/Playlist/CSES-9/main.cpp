#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, A[200000], j = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    set<int> s;
    int c = 0, max_c = 0;
    for(int i = 0; i < n; i++){
        while(j < n && s.find(A[j]) == s.end()){
            s.insert(A[j]);
            c++;
            j++;
        }
        max_c = max(max_c, c);
        s.erase(A[i]);
        c -= 1;
    }
    cout << max_c;
    return 0;
}
