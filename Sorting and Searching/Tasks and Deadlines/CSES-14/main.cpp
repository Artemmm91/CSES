#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    pair<int, int> A[200000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A + n);
    long long int t = 0, score = 0;
    for(int i = 0; i < n; i++){
        t += A[i].first;
        score += (A[i].second - t);
    }
    cout << score;
}
