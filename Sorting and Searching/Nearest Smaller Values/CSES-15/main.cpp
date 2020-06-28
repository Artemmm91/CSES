#include <iostream>
#include <vector>
using namespace std;
 
struct num{
    int x, i;
};
 
int main() {
    num A[200000], y;
    vector<num> v;
    int n, B[200000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i].x;
        A[i].i = i;
    }
    for(int i = n - 1; i >= 0; i--){
        while(v.size() != 0 && A[i].x < v.back().x){
            y = v.back();
            B[y.i] = i;
            v.pop_back();
        }
        v.push_back(A[i]);
    }
    while(v.size() != 0){
        y = v.back();
        B[y.i] = -1;
        v.pop_back();
    }
    for(int i = 0; i < n; i++){
        cout << B[i] + 1 << " ";
    }
    return 0;
}
