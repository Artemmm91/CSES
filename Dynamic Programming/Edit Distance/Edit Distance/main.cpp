#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    int n, m, temp;
    string s1, s2;
    cin >> s1 >> s2;
    n = (int)s1.size();
    m = (int)s2.size();
    vector<int> v_0;
    vector<vector<int>> v;
    for(int i =0; i <= n; i++){
        v_0.push_back(i);
    }
    v.push_back(v_0);
    for(int i = 1; i <= m; i++){
        v_0.clear();
        for(int j = 0; j <= n; j++){
            if(j == 0){
                v_0.push_back(i);
            }
            else{
                if(s2[i - 1] == s1[j - 1]){
                    v_0.push_back(v[i - 1][j - 1]);
                }
                else{
                    temp = min(v[i - 1][j - 1], min(v[i - 1][j], v_0[j - 1]));
                    v_0.push_back(temp+1);
                }
            }
        }
        v.push_back(v_0);
    }
    cout << v[m][n];
    return 0;
}
