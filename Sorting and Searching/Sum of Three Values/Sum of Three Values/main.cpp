#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, x, last, l, r, p;
    pair<int, int> A[5000];
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    
    sort(A, A + n);
    int sum;
    for(int ii = 0; ii <= n - 3; ii++){
        if(A[ii].first >= (x / 3 + 1)) break;
        sum = x - A[ii].first;
        for(int i = ii + 1; i < n - 1; i++){
            if(A[i].first < sum){
                last = sum - A[i].first;
                l = i + 1; r = n - 1;
                while(l <= r){
                    p = (l + r) / 2;
                    if(A[p].first == last){
                        cout << A[ii].second + 1 << " " << A[i].second + 1 << " " << A[p].second + 1;
                        return 0;
                    }
                    if(A[p].first < last){
                        l = p + 1;
                    }
                    else{
                        r = p - 1;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
