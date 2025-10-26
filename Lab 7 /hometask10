#include <iostream>
using namespace std;

#define SIZE 20

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void countingSort(int arr[], int n, int place) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / place) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / place) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    int pass = 1;
    for (int place = 1; maxVal / place > 0; place *= 10) {
        cout << "\nPass " << pass++ << " (Sorting by place " << place << "):" << endl;
        countingSort(arr, n, place);
        displayArray(arr, n);
    }
}

int main() {
    int products[SIZE];

    cout << "Enter 20 Product IDs (5-digit numbers):" << endl;
    for (int i = 0; i < SIZE; i++)
        cin >> products[i];

    cout << "\nBefore Sorting:" << endl;
    displayArray(products, SIZE);

    radixSort(products, SIZE);

    cout << "\nFinal Sorted Product IDs (Ascending):" << endl;
    displayArray(products, SIZE);

    return 0;
}
