#include <iostream>
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
    int n, m, k, A[200000], B[200000];
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < m; i++){
        cin >> B[i];
    }
    quick_sort(A, 0, n - 1);
    quick_sort(B, 0, m - 1);
    int i = 0, j = 0, c = 0;
    while(i < n && j < m){
        if(A[i] + k >= B[j] && A[i] - k <= B[j]){
            c++;
            i++;
            j++;
        }
        else{
            if(A[i] + k < B[j]) i++;
            if(A[i] - k > B[j]) j++;
        }
    }
    cout << c;
    return 0;
}
