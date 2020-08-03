#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> forest(1001, vector<int>(1001, 0)), table(1001, vector<int>(1001, 0));

int main() {
    int n, q, x1, y1, x2, y2;
    char c;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c;
            if (c == '*'){
                forest[i][j] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            table[i][j] = table[i][j - 1] + table[i - 1][j] - table[i - 1][j - 1] + forest[i][j];
        }
    }
    while(q--){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << table[x2][y2] + table[x1 - 1][y1 - 1] - table[x2][y1 - 1] - table[x1 - 1][y2] << endl;
    }
    return 0;
}
