#include <iostream>
#include <string>
using namespace std;

class Order {
public:
    int orderID;
    string customerName;
    float totalPrice;
};

void swap(Order &a, Order &b) {
    Order temp = a;
    a = b;
    b = temp;
}

int partition(Order orders[], int low, int high) {
    float pivot = orders[high].totalPrice;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (orders[j].totalPrice < pivot) {
            i++;
            swap(orders[i], orders[j]);
        }
    }
    swap(orders[i + 1], orders[high]);
    return i + 1;
}

void quickSort(Order orders[], int low, int high) {
    if (low < high) {
        int pi = partition(orders, low, high);
        quickSort(orders, low, pi - 1);
        quickSort(orders, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of orders: ";
    cin >> n;

    Order *orders = new Order[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Order ID: ";
        cin >> orders[i].orderID;
        cout << "Enter Customer Name: ";
        cin >> orders[i].customerName;
        cout << "Enter Total Price: ";
        cin >> orders[i].totalPrice;
    }

    quickSort(orders, 0, n - 1);

    cout << "\nSorted Orders (by Total Price):\n";
    for (int i = 0; i < n; i++) {
        cout << orders[i].orderID << "   "
             << orders[i].customerName << "   "
             << orders[i].totalPrice << endl;
    }

    delete[] orders;
    return 0;
}
