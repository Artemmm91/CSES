#include <iostream>
#include <algorithm>
using namespace std;

void quick_sort(int *array, int *b, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quick_sort(array, b, low, j);
    if (i < high)
        quick_sort(array, b, i, high);
}

int main() {
    int n, x, last, A[200000], B[200000];
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        B[i] = i;
    }
    int l, r, p;
    quick_sort(A, B, 0, n-1);
    for(int i = 0; i < n - 1; i++){
        if(A[i] < x){
            last = x - A[i];
            l = i + 1; r = n - 1;
            while(l <= r){
                p = (l + r) / 2;
                if(A[p] == last){
                    cout << B[i] + 1 << " " << B[p] + 1;
                    return 0;
                }
                if(A[p] < last){
                    l = p + 1;
                }
                else{
                    r = p - 1;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
