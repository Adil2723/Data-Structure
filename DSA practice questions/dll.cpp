#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val = 0) : data(val), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    ~DoublyLinkedList() {
        clear();
    }

    void clear() {
        while (head != NULL)
            deleteAtStart();
    }

    void traverse() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertAtBeginning(int data) {
        Node* temp = new Node(data);
        if (head == NULL) {
            head = tail = temp;
        }
        else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    void insertAtEnd(int data) {
        Node* temp = new Node(data);
        if (head == NULL) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }

    void insertAtAny(int pos, int data) {
        if (pos <= 1) {
            insertAtBeginning(data);
            return;
        }

        Node* temp = new Node(data);
        Node* curr = head;
        int count = 1;

        while (curr != NULL && count < pos) {
            curr = curr->next;
            count++;
        }

        if (curr == NULL) {
            insertAtEnd(data);
            delete temp;
            return;
        }

        temp->prev = curr->prev;
        temp->next = curr;
        if (curr->prev != NULL)
            curr->prev->next = temp;
        curr->prev = temp;
    }

    void deleteAtStart() {
        if (head == NULL)
            return;

        Node* temp = head;
        if (head == tail) {
            head = tail = NULL;
        }
        else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteAtEnd() {
        if (tail == NULL)
            return;

        Node* temp = tail;
        if (head == tail) {
            head = tail = NULL;
        }
        else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
    }

    void deleteAtAny(int pos) {
        if (head == NULL)
            return;
        if (pos <= 1) {
            deleteAtStart();
            return;
        }

        Node* curr = head;
        int count = 1;
        while (curr != NULL && count < pos) {
            curr = curr->next;
            count++;
        }

        if (curr == NULL)
            return;

        if (curr == tail) {
            deleteAtEnd();
            return;
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
    }

    int search(int key) {
        Node* curr = head;
        int pos = 1;
        while (curr != NULL) {
            if (curr->data == key)
                return pos;
            curr = curr->next;
            pos++;
        }
        return -1;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.insertAtBeginning(5);
    dll.traverse(); // Output: 5 10 20 30

    dll.insertAtAny(3, 15);
    dll.traverse(); // Output: 5 10 15 20 30

    cout << "Position of 20: " << dll.search(20) << endl; // Output: 4
    cout << "Position of 100: " << dll.search(100) << endl; // Output: -1

    dll.deleteAtStart();
    dll.traverse(); // Output: 10 15 20 30

    dll.deleteAtEnd();
    dll.traverse(); // Output: 10 15 20

    dll.deleteAtAny(2);
    dll.traverse(); // Output: 10 20

    dll.clear();
    dll.traverse(); // Output: (empty)

    return 0;
}
