#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> edge(0);
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

void unit(int a, int b){
    a = find(a); b = find(b);
    if(size[a] < size[b]){
        swap(a, b);
    }
    size[a] += size[b];
    max_size = max(max_size, size[a]);
    link[b] = a;
}

int main() {
    int n, m, a, b, c;
    long long sum = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--; b--;
        edge.push_back({c, a, b});
    }
    for(int i = 0; i < n; i++){
        link[i] = i;
        size[i] = 1;
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < m; i++){
        tie(c, a, b) = edge[i];
        if(!same(a, b)){
            sum += c;
            unit(a, b);
        }
        if(max_size >= n) break;
    }
    if(max_size != n){
        cout << "IMPOSSIBLE";
    }
    else{
        cout << sum;
    }
    return 0;
}
