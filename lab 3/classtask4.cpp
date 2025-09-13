#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void addEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void sort() {
        if (!head) return;
        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            while (current->next) {
                if (current->data > current->next->data) {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }

    void concatenate(LinkedList& other) {
        if (!head) {
            head = other.head;
            other.head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = other.head;
        other.head = nullptr; 
    }

    int findMiddle() {
        if (!head) {
            cout << "List is empty.\n";
            return -1; // indicate empty
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    void removeDuplicates() {
        if (!head) return;
        Node* current = head;
        while (current) {
            Node* runner = current;
            while (runner->next) {
                if (runner->next->data == current->data) {
                    Node* dup = runner->next;
                    runner->next = runner->next->next;
                    delete dup;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    static LinkedList mergeSortedLists(LinkedList& l1, LinkedList& l2) {
        LinkedList merged;
        Node* dummy = new Node(0);
        Node* tail = dummy;

        Node* p1 = l1.head;
        Node* p2 = l2.head;

        while (p1 && p2) {
            if (p1->data < p2->data) {
                tail->next = new Node(p1->data);
                p1 = p1->next;
            } else {
                tail->next = new Node(p2->data);
                p2 = p2->next;
            }
            tail = tail->next;
        }

        while (p1) {
            tail->next = new Node(p1->data);
            tail = tail->next;
            p1 = p1->next;
        }
        while (p2) {
            tail->next = new Node(p2->data);
            tail = tail->next;
            p2 = p2->next;
        }

        merged.head = dummy->next;
        delete dummy;

        return merged;
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list1;
    list1.addEnd(3);
    list1.addEnd(1);
    list1.addEnd(4);
    list1.addEnd(2);
    list1.addEnd(4);
    list1.addEnd(5);

    cout << "Original List 1: ";
    list1.display();

    list1.sort();
    cout << "Sorted List 1: ";
    list1.display();

    list1.removeDuplicates();
    cout << "List 1 after removing duplicates: ";
    list1.display();

    LinkedList list2;
    list2.addEnd(1);
    list2.addEnd(2);
    list2.addEnd(6);

    cout << "List 2: ";
    list2.display();

    LinkedList merged = LinkedList::mergeSortedLists(list1, list2);
    cout << "Merged Sorted List: ";
    merged.display();

    list1.concatenate(list2);
    cout << "List1 after concatenation with list2 (list2 is empty): ";
    list1.display();

    cout << "Middle element of List1: " << list1.findMiddle() << endl;

    return 0;
}
