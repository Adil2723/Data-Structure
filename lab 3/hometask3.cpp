#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int id;
    string name;
    int price;
    Node* prev;
    Node* next;

    Node(int itemId, string itemName, int itemPrice) {
        id = itemId;
        name = itemName;
        price = itemPrice;
        prev = next = nullptr;
    }
};

class ShoppingCart {
    Node* head;
    Node* tail;

public:
    ShoppingCart() {
        head = tail = nullptr;
    }

    void insertEnd(int id, string name, int price) {
        Node* newNode = new Node(id, name, price);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertFront(int id, string name, int price) {
        Node* newNode = new Node(id, name, price);
        if (!head) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void removeFront() {
        if (!head) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    void removeEnd() {
        if (!tail) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    void searchByID(int id) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "Item Found: ID=" << temp->id 
                     << ", Name=" << temp->name 
                     << ", Price=$" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << id << " not found." << endl;
    }

    void updatePriceByID(int id, int newPrice) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                temp->price = newPrice;
                cout << "Price updated for " << temp->name 
                     << ". New Price: $" << newPrice << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << id << " not found." << endl;
    }

    void displayForward() {
        if (!head) {
            cout << "Cart is empty." << endl;
            return;
        }
        cout << "Cart (Front to End):" << endl;
        Node* temp = head;
        while (temp) {
            cout << "ID=" << temp->id << ", " 
                 << temp->name << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        if (!tail) {
            cout << "Cart is empty." << endl;
            return;
        }
        cout << "Cart (End to Front):" << endl;
        Node* temp = tail;
        while (temp) {
            cout << "ID=" << temp->id << ", " 
                 << temp->name << " - $" << temp->price << endl;
            temp = temp->prev;
        }
    }

    int countItems() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void mostExpensiveItem() {
        if (!head) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = head;
        Node* maxNode = head;
        while (temp) {
            if (temp->price > maxNode->price)
                maxNode = temp;
            temp = temp->next;
        }
        cout << "Most Expensive Item: ID=" << maxNode->id 
             << ", " << maxNode->name 
             << " - $" << maxNode->price << endl;
    }
};

int main() {
    ShoppingCart cart;

    cart.insertEnd(1, "Laptop", 1000);
    cart.insertEnd(2, "Phone", 700);
    cart.insertEnd(3, "Tablet", 400);
    cart.insertFront(0, "Smartwatch", 200);

    cart.displayForward();
    cout << endl;

    cart.removeFront();
    cart.removeEnd();
    cart.displayForward();
    cout << endl;

    cart.searchByID(2);
    cart.updatePriceByID(2, 750);
    cout << endl;

    cart.displayBackward();
    cout << endl;

    cout << "Total items: " << cart.countItems() << endl;
    cart.mostExpensiveItem();

    return 0;
}
