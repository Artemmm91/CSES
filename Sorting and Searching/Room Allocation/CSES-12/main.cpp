#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

struct dat{
    double time;
    int type, index, room;
};

void quickSort(dat A[], int low, int high)
{
    int i = low;
    int j = high;
    double pivot = A[(i + j) / 2].time;

    while (i <= j)
    {
        while (A[i].time < pivot)
            i++;
        while (A[j].time > pivot)
            j--;
        if (i <= j)
        {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(A, low, j);
    if (i < high)
        quickSort(A, i, high);
}

int main() {
    int n;
    int k = 0, m = 0;
    dat A[400000];
    int Room[200000];
    queue<int> rooms;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[2*i].time >> A[2*i + 1].time;
        A[2*i].time = A[2*i].time - 0.1;
        A[2*i].type = 1;
        A[2*i + 1].type = -1;
        A[2*i].index = i;
        A[2*i + 1].index = i;
    }
    quickSort(A, 0, 2*n - 1);
    for(int i = 0; i < 2 * n; i++){
        k += A[i].type;
        m = max(k, m);
    }
    for(int i = 0; i < m; i++){
        rooms.push(i + 1);
    }
    for(int i = 0; i < 2*n - 1; i++){
        if(A[i].type == 1){
            Room[A[i].index] = rooms.front();
            rooms.pop();
        }
        else{
            rooms.push(Room[A[i].index]);
        }
    }
    cout << endl;
    cout << m << endl;
    for(int i = 0; i < n; i++){
        cout << Room[i] << " ";
    }
    return 0;
}
