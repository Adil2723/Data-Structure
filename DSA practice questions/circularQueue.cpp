#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
    string* queue;
    int front;
    int rear;
    int capacity;

public:
    CircularQueue(int cap) {
        capacity = cap;
        queue = new string[capacity];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    bool enqueue(string value) { // Add element
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << ".\n";
            return false;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % capacity;
        queue[rear] = value;
        cout << value << " enqueued.\n";
        return true;
    }

    bool dequeue() { // Remove element
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return false;
        }

        cout << queue[front] << " dequeued.\n";

        if (front == rear) { // last element removed
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        return true;
    }

    string peek() { // View front element
        if (isEmpty()) {
            return "Queue is empty";
        }
        return queue[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue cq(3);

    cq.enqueue("Car1");
    cq.enqueue("Car2");
    cq.enqueue("Car3");
    cq.enqueue("Car4"); // should show full

    cout << "Front element: " << cq.peek() << "\n";

    cq.dequeue();
    cq.display();

    cq.enqueue("Car4"); // add after space frees
    cq.display();

    cout << "Front element: " << cq.peek() << "\n";

    return 0;
}
