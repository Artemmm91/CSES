#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, A[100], sum = 0, temp, k = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        sum += A[i];
    }
    vector<int> v, ans;
    v.push_back(-1);
    for(int i = 1; i <= sum; i++){
        temp = -2;
        for(int j = 0; j < n; j++){
            if(i >= A[j]){
                if(v[i - A[j]] != -2 && v[i - A[j]] < j){
                    temp = j;
                    break;
                }
            }
        }
        if(temp != -2){
            ans.push_back(i);
            k++;
        }
        v.push_back(temp);
    }
    cout << k << endl;
    for(int i = 0; i < k; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
