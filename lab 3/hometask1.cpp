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

    void addFront(string item, int price) {
        Node* newNode = new Node(item, price);
        newNode->next = head;
        head = newNode;
    }

    void addEnd(string item, int price) {
        Node* newNode = new Node(item, price);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertAfter(string target, string item, int price) {
        Node* temp = head;
        while (temp) {
            if (temp->item == target) {
                Node* newNode = new Node(item, price);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
    }

    void searchItem(string target) {
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

    void displayCart() {
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
    cart.addEnd("Laptop", 1000);
    cart.addEnd("Phone", 700);
    cart.addEnd("Tablet", 400);
    cart.addEnd("Headphones", 150);
    cart.addFront("Smartwatch", 200);
    cart.addEnd("Keyboard", 80);
    cart.insertAfter("Phone", "Monitor", 300);
    cart.searchItem("Tablet");
    cart.displayCart();
    return 0;
}
