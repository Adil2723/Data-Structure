#include <iostream>
#include <string>
using namespace std;

#define MAX 10

class LibraryQueue {
private:
    string queue[MAX];
    int front, rear;

public:
    LibraryQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0;
        rear++;
        queue[rear] = name;
        cout << name << " added to queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << queue[front] << " has completed their transaction.\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Current Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << endl;
        }
    }
};

int main() {
    LibraryQueue q;
    int choice;
    string name;

    do {
        cout << "\n1. Add Patron\n";
        cout << "2. Process Patron\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                q.enqueue(name);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
