#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int link[100000], size[100000], max_size = 0;

int find(int x){
    while(x != link[x]){
        x = link[x];
    }
    return x;
}

bool same(int a, int b){
    return find(a) == find(b);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(size[a] < size[b]){
        swap(a, b);
    }
    size[a] += size[b];
    max_size = max(max_size, size[a]);
    link[b] = a;
}

int main() {
    int n, m, a, b, cnt;
    vector<pair<int, int>> edges(0);
    cin >> n >> m;
    for(int i = 0; i < m ; i++){
        cin >> a >> b;
        a--; b--;
        edges.push_back({a, b});
    }
    for(int i = 0; i < n; i++){
        link[i] = i;
        size[i] = 1;
    }
    cnt = n;
    for(int i = 0; i < m; i++){
        tie(a, b) = edges[i];
        if(!same(a, b)){
            cnt--;
            unite(a, b);
        }
        cout << cnt << " " << max_size << endl;
    }
    return 0;
}
