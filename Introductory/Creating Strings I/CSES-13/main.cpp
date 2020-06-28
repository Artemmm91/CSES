#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void permutations(string s)
{
    int k = 0;
    sort(s.begin(), s.end());
    string l = s;
    do {
        k++;
    } while (next_permutation(s.begin(), s.end()));
    cout << k << endl;
    do {
        cout << l << endl;
    } while (next_permutation(l.begin(), l.end()));
}

int main() {
    string s;
    cin >> s;
    permutations(s);
    return 0;
}
