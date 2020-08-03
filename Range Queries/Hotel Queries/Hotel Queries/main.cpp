#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m, G[200000], H[200000];
    pair<int, int> p;
    set<pair<int, int>> s;
    set<pair<int, int>> :: iterator it;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> H[i];
        s.insert({H[i], i});
    }
    for(int i = 0; i < m; i++){
        cin >> G[i];
        it = s.lower_bound({G[i], -1});
        if(it == s.end()){
            cout << 0 << endl;
        }
        else{
            p = *it;
            cout << p.second + 1 << endl;
            p.first -= G[i];
            s.erase(it);
            s.insert(p);
        }
    }
    
    return 0;
}
