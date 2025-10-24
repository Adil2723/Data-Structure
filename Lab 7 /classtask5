#include <iostream>
using namespace std;

class QuickSort {
public:
    long long comparisons;

    QuickSort() {
        comparisons = 0;
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int partitionFirst(int arr[], int low, int high) {
        int pivot = arr[low];
        int i = low + 1;
        for (int j = low + 1; j <= high; j++) {
            comparisons++;
            if (arr[j] < pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[low], arr[i - 1]);
        return i - 1;
    }

    int partitionMiddle(int arr[], int low, int high) {
        int mid = low + (high - low) / 2;
        swap(arr[low], arr[mid]);
        return partitionFirst(arr, low, high);
    }

    int partitionMedianOfThree(int arr[], int low, int high) {
        int mid = low + (high - low) / 2;
        int a = arr[low], b = arr[mid], c = arr[high];
        int medianIndex = low;
        if ((a <= b && b <= c) || (c <= b && b <= a))
            medianIndex = mid;
        else if ((a <= c && c <= b) || (b <= c && c <= a))
            medianIndex = high;
        swap(arr[low], arr[medianIndex]);
        return partitionFirst(arr, low, high);
    }

    int partitionRandom(int arr[], int low, int high) {
        int pivotIndex = low + (high - low) % (high - low + 1);
        swap(arr[low], arr[pivotIndex]);
        return partitionFirst(arr, low, high);
    }

    void quickSort(int arr[], int low, int high, string method) {
        if (low < high) {
            int pi;
            if (method == "first")
                pi = partitionFirst(arr, low, high);
            else if (method == "middle")
                pi = partitionMiddle(arr, low, high);
            else if (method == "median")
                pi = partitionMedianOfThree(arr, low, high);
            else
                pi = partitionRandom(arr, low, high);
            quickSort(arr, low, pi - 1, method);
            quickSort(arr, pi + 1, high, method);
        }
    }
};

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    string methods[4] = {"first", "middle", "median", "random"};

    for (int m = 0; m < 4; m++) {
        int temp[n];
        for (int i = 0; i < n; i++)
            temp[i] = arr[i];

        QuickSort qs;
        qs.quickSort(temp, 0, n - 1, methods[m]);
        cout << "Sorted array using " << methods[m] << " element pivot: ";
        printArray(temp, n);
        cout << "Number of comparisons: " << qs.comparisons << "\n\n";
    }

    return 0;
}
