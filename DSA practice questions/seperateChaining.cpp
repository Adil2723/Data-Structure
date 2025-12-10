#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* next;

    Node(int k) {
        key = k;
        next = nullptr;
    }
};

class HashChaining {
private:
    int table_size;
    Node** table; 

public:
    HashChaining(int ts) {
        table_size = ts;
        table = new Node*[table_size];

        for (int i = 0; i < table_size; i++)
            table[i] = nullptr;
    }

    int hash(int key) {
        return key % table_size;
    }

    void insert(int key) {
        int idx = hash(key);
        Node* newNodePtr = new Node(key);

        newNodePtr->next = table[idx];
        table[idx] = newNodePtr;
    }

    bool search(int key) {
        int idx = hash(key);
        Node* curr = table[idx];

        while (curr != nullptr) {
            if (curr->key == key)
                return true;
            curr = curr->next;
        }
        return false;
    }

    bool remove(int key) {
        int idx = hash(key);
        Node* curr = table[idx];
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->key == key) {
                if (prev == nullptr)
                    table[idx] = curr->next;
                else
                    prev->next = curr->next;

                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Key not found\n";
        return false;
    }

    void display() {
        for (int i = 0; i < table_size; i++) {
            cout << i << ": ";
            Node* curr = table[i];
            while (curr != nullptr) {
                cout << curr->key << " -> ";
                curr = curr->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashChaining ht(7);

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(14);

    cout << "Hash Table with Separate Chaining:\n";
    ht.display();

    cout << "Search 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search 21: " << (ht.search(21) ? "Found" : "Not Found") << endl;

    ht.remove(15);
    cout << "\nAfter removing 15:\n";
    ht.display();
}
