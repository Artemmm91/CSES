#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, k, a, b, cnt = 0;
    vector<pair<int, int>> films(0);
    multiset<int> people;
    multiset<int> :: iterator it;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        films.push_back({b, a});
    }
    sort(films.begin(), films.end());
    for(int i = 0; i < n; i++){
        it = people.upper_bound(films[i].second);
        if(people.size() > 0 && it != people.begin()){
            it--;
            people.erase(it);
            people.insert(films[i].first);
            cnt++;
        }
        else if(people.size() < k){
            people.insert(films[i].first);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
