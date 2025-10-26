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
    const int n = 50;
    int scores[n];

    cout << "Enter 50 scores (0-100):\n";
    for (int i = 0; i < n; i++)
        cin >> scores[i];

    radixSort(scores, n);

    cout << "\nSorted Scores With Ranks:\n";
    for (int i = 0; i < n; i++) {
        cout << "Rank " << (i + 1) << ": " << scores[i] << endl;
    }

    return 0;
}
