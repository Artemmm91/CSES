#include <iostream>
using namespace std;
#define ll long long

ll c, A[8][8];

bool is_attack(int c1, int r1, int c2, int r2){
    if (c1 == c2 || r1 == r2) return false;
    if(abs(r1 - r2) == abs(c1 - c2)) return false;
    return true;
}

bool is_pole(int c, int r){
    if(A[r][c] == 0) return false;
    return true;
}

bool is_good(int I[]){
    for(int i = 0; i < 8; i++){
        if(is_pole(i, I[i]) == false) return false;
    }
    for(int i = 0; i < 8; i++){
        for(int j = i + 1; j < 8; j++){
            if(is_attack(i, I[i], j, I[j]) == false){
                return false;
            }
        }
    }
    return true;
}

void func(){
    for(int i1 = 0; i1 < 8; i1++){
        for(int i2 = 0; i2 < 8; i2++){
            for(int i3 = 0; i3 < 8; i3++){
                for(int i4 = 0; i4 < 8; i4++){
                    for(int i5 = 0; i5 < 8; i5++){
                        for(int i6 = 0; i6 < 8; i6++){
                            for(int i7 = 0; i7 < 8; i7++){
                                for(int i8 = 0; i8 < 8; i8++){
                                    int I[8] = {i1, i2, i3, i4, i5, i6, i7, i8};
                                    if(is_good(I)){
                                        c++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}



int main() {
    char x;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> x;
            if(x == '*') A[i][j] = 0;
            else A[i][j] = 1;
        }
    }
    func();
    cout << c;
    return 0;
}
