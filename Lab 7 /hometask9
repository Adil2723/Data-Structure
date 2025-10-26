#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int place) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / place) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    for (int place = 1; maxVal / place > 0; place *= 10)
        countingSort(arr, n, place);
}

int main() {
    int n;
    cout << "Enter number of transactions: ";
    cin >> n;

    int *transactions = new int[n];

    cout << "Enter transaction amounts:\n";
    for (int i = 0; i < n; i++)
        cin >> transactions[i];

    radixSort(transactions, n);

    cout << "\nSorted Transaction Amounts:\n";
    for (int i = 0; i < n; i++)
        cout << transactions[i] << endl;

    delete[] transactions;
    return 0;
}
