#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string s) : data(s), next(nullptr) {}
};

class HashTable {
    int tableSize;
    Node** table;

public:
    HashTable(int size) {
        tableSize = size;
        table = new Node*[tableSize];
        for(int i = 0; i < tableSize; i++)
            table[i] = nullptr;
    }

    int hashFunction(string s) {
        int sum = 0;
        for(char c : s)
            sum += int(c);
        return sum % tableSize;
    }

    void insert(string s) {
        int idx = hashFunction(s);
        Node* newNode = new Node(s);
        newNode->next = table[idx];
        table[idx] = newNode;
    }

    bool search(string s) {
        int idx = hashFunction(s);
        Node* curr = table[idx];
        while(curr) {
            if(curr->data == s)
                return true;
            curr = curr->next;
        }
        return false;
    }

    void display() {
        for(int i = 0; i < tableSize; i++) {
            cout << i << ": ";
            Node* curr = table[i];
            while(curr) {
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable separate(7);

    separate.insert("Mango");
    separate.insert("banana");
    separate.insert("Dragon Food");
    separate.insert("dog");
    separate.insert("apple");

    separate.display();

    cout << separate.search("Mango") << endl;
    cout << separate.search("orange") << endl;

    return 0;
}
