#include <iostream>
using namespace std;

void quick_sort(int *array, int *v, int low, int high)
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
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quick_sort(array, v, low, j);
    if (i < high)
        quick_sort(array, v, i, high);
}


int main() {
    int n, A[400000], V[400000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[2*i] >> A[2*i + 1];
        V[2*i] = 1;
        V[2*i + 1] = -1;
    }
    quick_sort(A, V, 0, 2*n - 1);
    int sum = 0, max_sum = 0;
    for(int i = 0; i < 2*n; i++){
        sum += V[i];
        if(sum > max_sum) max_sum = sum;
    }
    cout << max_sum;
    return 0;
}
