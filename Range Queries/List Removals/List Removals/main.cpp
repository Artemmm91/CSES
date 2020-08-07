#include <iostream>
using namespace std;

int A[200001], tree[525001], s;

int p2(int x){
    int l = 1;
    while(l < x){
        l *= 2;
    }
    return l;
}

void upd(int k, int x){
    tree[k] = x;
    k /= 2;
    while(k >= 1){
        tree[k] = tree[2 * k] + tree[2 * k + 1];
        k /= 2;
    }
}

int sum(int a, int b){
    int ss = 0;
    while(a <= b){
        if(a % 2 == 1){
            ss += tree[a];
            a++;
        }
        if(b % 2 == 0){
            ss += tree[b];
            b--;
        }
        a/=2;b/=2;
    }
    return ss;
}

int find(int x){
    int k, l = 0, r = s - 1, p;
    while(l < r){
        k = (l + r)/2;
        p = sum(s, k + s);
        if(l + 1 == r){
            if(p >= x) return l;
            return r;
        }
        if(p < x){
            l = k;
        }
        else{
            r = k;
        }
    }
    return l;
}

int main() {
    int n, a, k;
    cin >> n;
    s = p2(n);
    for(int i = 1; i <= n; i++){
        cin >> A[i];
        upd(i + s - 1, 1);
    }
    for(int i = 1; i <= n; i++){
        cin >> a;
        k = find(a);
        cout << A[k + 1] << " ";
        upd(k + s, 0);
    }
    return 0;
}
