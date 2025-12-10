#include <iostream>
using namespace std;

int partition(int a[], int start, int end) {
    int pivot = a[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (a[j] <= pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[end];
    a[end] = temp;

    return i + 1;
}

void quickSort(int a[], int start, int end) {
    if (start < end) {
        int p = partition(a, start, end);
        quickSort(a, start, p - 1);
        quickSort(a, p + 1, end);
    }
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";  
    }
    cout << endl;
}

int main() {
    int a[] = {3, 2, 7, 1, 8};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Before sorting array elements are - \n";
    print(a, n);

    quickSort(a, 0, n - 1);

    cout << "After sorting array elements are - \n";
    print(a, n);

    return 0;
}
