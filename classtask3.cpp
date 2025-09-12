#include <iostream>
using namespace std;

struct Node {
    int compartmentNumber;
    Node* prev;
    Node* next;
    Node(int num) : compartmentNumber(num), prev(nullptr), next(nullptr) {}
};

class Train {
    Node* head;
    Node* tail;

public:
    Train() : head(nullptr), tail(nullptr) {}

    void addEnd(int compartmentNum) {
        Node* newNode = new Node(compartmentNum);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void removeFirst() {
        if (!head) {
            cout << "Train has no compartments.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;

        cout << "Removed compartment number: " << temp->compartmentNumber << endl;
        delete temp;
    }

    bool search(int compartmentNum) {
        Node* temp = head;
        while (temp) {
            if (temp->compartmentNumber == compartmentNum) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        if (!head) {
            cout << "Train has no compartments.\n";
            return;
        }
        cout << "Train compartments from front to end:\n";
        Node* temp = head;
        while (temp) {
            cout << temp->compartmentNumber << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Train() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Train train;

    train.addEnd(101);
    train.addEnd(102);
    train.addEnd(103);
    train.addEnd(104);

    train.display();
 
	  train.removeFirst();

    int searchNum = 103;
    if (train.search(searchNum)) {
        cout << "Compartment " << searchNum << " found.\n";
    } else {
        cout << "Compartment " << searchNum << " not found.\n";
    }

    train.display();

    return 0;
}
