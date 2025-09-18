#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string item;
    int price;
    Node* next;
    Node(string name, int cost) {
        item = name;
        price = cost;
        next = nullptr;
    }
};

class ShoppingCart {
    Node* head;
public:
    ShoppingCart() { head = nullptr; }

    void addTail(string item, int price) {
        Node* newNode = new Node(item, price);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void deleteFront() {
        if (!head) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void searchByName(string target) {
        Node* temp = head;
        while (temp) {
            if (temp->item == target) {
                cout << target << " found. Price: $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << target << " not found in cart." << endl;
    }

    void searchByPosition(int pos) {
        if (pos <= 0) {
            cout << "Invalid position." << endl;
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp) {
            if (count == pos) {
                cout << "Position " << pos << ": " << temp->item << " - $" << temp->price << endl;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "No item at position " << pos << endl;
    }

    void displayCart() {
        if (!head) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Shopping Cart:" << endl;
        while (temp) {
            cout << temp->item << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }
};

int main() {
    ShoppingCart cart;
    cart.addTail("Laptop", 1000);
    cart.addTail("Phone", 700);
    cart.addTail("Tablet", 400);
    cart.addTail("Headphones", 150);

    cart.displayCart();
    cout << endl;

    cart.deleteFront();
    cart.displayCart();
    cout << endl;

    cart.searchByName("Tablet");
    cart.searchByPosition(2);

    return 0;
}
