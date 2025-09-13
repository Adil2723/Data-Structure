#include <iostream>
#include <string>
using namespace std;

struct Node {
    string book;
    Node* next;
    Node(string b) : book(b), next(nullptr) {}
};

class Library {
    Node* head;
public:
    Library() {
        head = new Node("Data Structures");
        head->next = new Node("Operating Systems");
        head->next->next = new Node("Computer Networks");
        head->next->next->next = new Node("Database Systems");
    }

    void addFront(const string& book) {
        Node* newNode = new Node(book);
        newNode->next = head;
        head = newNode;
    }

    void addEnd(const string& book) {
        Node* newNode = new Node(book);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAfter(const string& target, const string& book) {
        Node* temp = head;
        while (temp && temp->book != target) {
            temp = temp->next;
        }
        if (temp) {
            Node* newNode = new Node(book);
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            cout << "Book \"" << target << "\" not found for insertion.\n";
        }
    }

    bool search(const string& book) {
        Node* temp = head;
        while (temp) {
            if (temp->book == book) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        cout << "Books in library:\n";
        while (temp) {
            cout << "- " << temp->book << endl;
            temp = temp->next;
        }
    }

    ~Library() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Library lib;
    lib.addFront("Artificial Intelligence");
    lib.addEnd("Machine Learning");

    lib.insertAfter("Operating Systems", "Cyber Security");

    if (lib.search("Database Systems")) {
        cout << "\"Database Systems\" found in the list.\n";
    } else {
        cout << "\"Database Systems\" not found in the list.\n";
    }

    lib.display();

    return 0;
}
