#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string book;
    Node* next;
    Node(string b) : book(b), next(nullptr) {}
};

class LibraryCatalog {
    Node* head;
    Node* tail;

public:
    LibraryCatalog() : head(nullptr), tail(nullptr) {}

    void addTail(const string& book) {
        Node* newNode = new Node(book);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteFront() {
        if (!head) {
            cout << "Catalog is empty, nothing to delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (!head) tail = nullptr;
        cout << "Deleted book: " << temp->book << endl;
        delete temp;
    }

    void searchByTitle(const string& book) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->book == book) {
                cout << "Book \"" << book << "\" found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Book \"" << book << "\" not found.\n";
    }

    void searchByPosition(int position) {
        if (position <= 0) {
            cout << "Invalid position.\n";
            return;
        }
        Node* temp = head;
        int pos = 1;
        while (temp && pos < position) {
            temp = temp->next;
            pos++;
        }
        if (temp && pos == position) {
            cout << "Book at position " << position << ": " << temp->book << endl;
        } else {
            cout << "Position " << position << " is out of range.\n";
        }
    }

    void display() {
        if (!head) {
            cout << "Catalog is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Books in catalog:\n";
        while (temp) {
            cout << "- " << temp->book << endl;
            temp = temp->next;
        }
    }

    ~LibraryCatalog() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LibraryCatalog catalog;

    catalog.addTail("Data Structures");
    catalog.addTail("Operating Systems");
    catalog.addTail("Computer Networks");
    catalog.addTail("Database Systems");

    catalog.display();

    catalog.deleteFront();

    catalog.searchByTitle("Database Systems");
    catalog.searchByTitle("Artificial Intelligence");

    catalog.searchByPosition(2);
    catalog.searchByPosition(10);

    catalog.addTail("Artificial Intelligence");
    catalog.addTail("Machine Learning");

    catalog.display();

    return 0;
}
