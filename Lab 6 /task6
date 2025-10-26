#include <iostream>
#include <string>
using namespace std;

struct Order {
    string itemName;
    int quantity;
    Order* next;
    Order(string item, int qty) {
        itemName = item;
        quantity = qty;
        next = NULL;
    }
};

class Queue {
private:
    Order* front;
    Order* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(string item, int qty) {
        Order* newOrder = new Order(item, qty);

        if (isEmpty()) {
            front = rear = newOrder;
        } else {
            rear->next = newOrder;
            rear = newOrder;
        }
        cout << "Order Added: " << item << " x" << qty << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No orders to process! Queue Underflow!" << endl;
            return;
        }

        Order* temp = front;
        cout << "Processed Order: " << temp->itemName 
             << " x" << temp->quantity << endl;

        front = front->next;
        delete temp;

        if (front == NULL)
            rear = NULL;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue Empty! No pending orders!" << endl;
            return;
        }

        cout << "\nPending Orders (FIFO):\n";
        Order* temp = front;
        while (temp != NULL) {
            cout << temp->itemName << " x" << temp->quantity << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue orders;
    int choice, qty;
    string item;

    do {
        cout << "\n=== Restaurant Order System ===\n";
        cout << "1. Add Order\n";
        cout << "2. Process Order\n";
        cout << "3. Show All Orders\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Item Name: ";
                cin >> item;
                cout << "Enter Quantity: ";
                cin >> qty;
                orders.enqueue(item, qty);
                break;

            case 2:
                orders.dequeue();
                break;

            case 3:
                orders.display();
                break;

            case 4:
                cout << "Exiting System... Goodbye!\n";
                break;

            default:
                cout << "Invalid Choice Try Again!\n";
        }

    } while (choice != 4);

    return 0;
}
