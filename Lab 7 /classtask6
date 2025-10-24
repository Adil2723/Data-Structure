#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string name;
    int ID;
    double salary;
};

class EmployeeList {
public:

    void merge(Employee arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        Employee leftArr[n1], rightArr[n2];

        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (leftArr[i].salary >= rightArr[j].salary) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    void mergeSort(Employee arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    void displayTop(Employee arr[], int n) {
        cout << "Top 3 highest-paid employees:\n";
        for (int i = 0; i < 3 && i < n; i++)
            cout << i + 1 << ". " << arr[i].name << " | ID: " << arr[i].ID << " | Salary: $" << arr[i].salary << endl;
    }
};

int main() {
    Employee employees[12];
    EmployeeList elist;

    for (int i = 0; i < 12; i++) {
        cout << "Enter details for employee " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, employees[i].name);
        cout << "ID: ";
        cin >> employees[i].ID;
        cout << "Salary: ";
        cin >> employees[i].salary;
        cout << endl;
    }

    elist.mergeSort(employees, 0, 11);
    elist.displayTop(employees, 12);

    return 0;
}
