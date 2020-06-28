#include <iostream>
#include <set>
using namespace std;

struct a{
    int t1, t2;
};

void quick_sort(a *array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2].t2;
    a temp;

    while (i <= j)
    {
        while (array[i].t2 < pivot)
            i++;
        while (array[j].t2 > pivot)
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
    int n, c = 0;
    a A[200000];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> A[i].t1 >> A[i].t2;
    }
    quick_sort(A, 0, n - 1);
    a last;
    last.t2 = -1;
    for(int i = 0; i < n; i++){
        if(A[i].t1 >= last.t2){
            last = A[i];
            c++;
        }
    }
    cout << c;
    return 0;
}
