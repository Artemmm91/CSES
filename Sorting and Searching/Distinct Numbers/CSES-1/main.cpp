#include <iostream>
#include <algorithm>
using namespace std;

void quick_sort(int *array, int low, int high)
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
            i++;
            j--;
        }
    }
    if (j > low)
        quick_sort(array, low, j);
    if (i < high)
        quick_sort(array, i, high);
}


int main() {
    int n, A[200000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    quick_sort(A, 0, n - 1);
    int dist = 1;
    for(int i = 1; i < n; i++){
        if(A[i] != A[i - 1]) dist++;
    }
    cout << dist;
    return 0;
}
