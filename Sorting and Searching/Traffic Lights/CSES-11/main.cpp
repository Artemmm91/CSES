#include <iostream>
#include <set>
using namespace std;

int main() {
    int x, n, pos;
    multiset<int> s;
    multiset<int> position;
    cin >> x >> n;;
    position.insert(0);
    position.insert(x);
    int z, v;
    for(int i = 0; i < n; i++){
        cin >> pos;
        if(pos != x && pos != 0){
            position.insert(pos);
            z = *position.upper_bound(pos);
            v = *prev(position.lower_bound(pos));
            auto itr = s.find(z - v);
            if(itr!=s.end()){
                s.erase(itr);
            }
            s.insert(z - pos);
            s.insert(pos - v);
            cout << *prev(s.end()) << endl;
        }
    }
    return 0;
}
