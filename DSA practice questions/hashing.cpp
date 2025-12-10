#include <iostream>
using namespace std;

// ----------------- Node class for Separate Chaining -----------------
class Node {
public:
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

// ----------------- Separate Chaining Hash Table -----------------
class HashChaining {
    int tableSize;
    Node** table;
public:
    HashChaining(int size) {
        tableSize = size;
        table = new Node*[tableSize];
        for(int i = 0; i < tableSize; i++)
            table[i] = nullptr;
    }

    int hash(int key) { return key % tableSize; }

    void insert(int key) {
        int idx = hash(key);
        Node* newNode = new Node(key);
        newNode->next = table[idx];
        table[idx] = newNode;
    }

    bool search(int key) {
        int idx = hash(key);
        Node* curr = table[idx];
        while(curr) {
            if(curr->key == key) return true;
            curr = curr->next;
        }
        return false;
    }

    void remove(int key) {
        int idx = hash(key);
        Node* curr = table[idx];
        Node* prev = nullptr;
        while(curr) {
            if(curr->key == key) {
                if(prev == nullptr) table[idx] = curr->next;
                else prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void display() {
        for(int i = 0; i < tableSize; i++) {
            cout << i << ": ";
            Node* curr = table[i];
            while(curr) {
                cout << curr->key << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }
};

// ----------------- Linear Probing Hash Table -----------------
class HashLinear {
    int tableSize;
    int* table;
    const int EMPTY = -1;
public:
    HashLinear(int size) {
        tableSize = size;
        table = new int[tableSize];
        for(int i = 0; i < tableSize; i++)
            table[i] = EMPTY;
    }

    int hash(int key) { return key % tableSize; }

    void insert(int key) {
        int idx = hash(key);
        int start = idx;
        while(table[idx] != EMPTY) {
            idx = (idx + 1) % tableSize;
            if(idx == start) {
                cout << "Table full! Cannot insert " << key << endl;
                return;
            }
        }
        table[idx] = key;
    }

    bool search(int key) {
        int idx = hash(key);
        int start = idx;
        while(table[idx] != EMPTY) {
            if(table[idx] == key) return true;
            idx = (idx + 1) % tableSize;
            if(idx == start) break;
        }
        return false;
    }

    void remove(int key) {
        int idx = hash(key);
        int start = idx;
        while(table[idx] != EMPTY) {
            if(table[idx] == key) {
                table[idx] = EMPTY;
                return;
            }
            idx = (idx + 1) % tableSize;
            if(idx == start) break;
        }
    }

    void display() {
        for(int i = 0; i < tableSize; i++)
            cout << i << ": " << table[i] << endl;
    }
};

// ----------------- Quadratic Probing Hash Table -----------------
class HashQuadratic {
    int tableSize;
    int* table;
    const int EMPTY = -1;
public:
    HashQuadratic(int size) {
        tableSize = size;
        table = new int[tableSize];
        for(int i = 0; i < tableSize; i++)
            table[i] = EMPTY;
    }

    int hash(int key) { return key % tableSize; }

    void insert(int key) {
        int idx = hash(key);
        int i = 1;
        while(table[idx] != EMPTY) {
            idx = (hash(key) + i*i) % tableSize;
            i++;
            if(i == tableSize) {
                cout << "Table full! Cannot insert " << key << endl;
                return;
            }
        }
        table[idx] = key;
    }

    bool search(int key) {
        int i = 0;
        int idx = hash(key);
        while(table[idx] != EMPTY && i < tableSize) {
            if(table[idx] == key) return true;
            i++;
            idx = (hash(key) + i*i) % tableSize;
        }
        return false;
    }

    void remove(int key) {
        int i = 0;
        int idx = hash(key);
        while(table[idx] != EMPTY && i < tableSize) {
            if(table[idx] == key) {
                table[idx] = EMPTY;
                return;
            }
            i++;
            idx = (hash(key) + i*i) % tableSize;
        }
    }

    void display() {
        for(int i = 0; i < tableSize; i++)
            cout << i << ": " << table[i] << endl;
    }
};

// ----------------- Double Hashing -----------------
class HashDouble {
    int tableSize;
    int* table;
    const int EMPTY = -1;
public:
    HashDouble(int size) {
        tableSize = size;
        table = new int[tableSize];
        for(int i = 0; i < tableSize; i++)
            table[i] = EMPTY;
    }

    int hash1(int key) { return key % tableSize; }
    int hash2(int key) { return 7 - (key % 7); } // second hash function, prime < tableSize

    void insert(int key) {
        int idx = hash1(key);
        int i = 0;
        while(table[idx] != EMPTY) {
            i++;
            idx = (hash1(key) + i * hash2(key)) % tableSize;
            if(i == tableSize) {
                cout << "Table full! Cannot insert " << key << endl;
                return;
            }
        }
        table[idx] = key;
    }

    bool search(int key) {
        int i = 0;
        int idx = hash1(key);
        while(table[idx] != EMPTY && i < tableSize) {
            if(table[idx] == key) return true;
            i++;
            idx = (hash1(key) + i * hash2(key)) % tableSize;
        }
        return false;
    }

    void remove(int key) {
        int i = 0;
        int idx = hash1(key);
        while(table[idx] != EMPTY && i < tableSize) {
            if(table[idx] == key) {
                table[idx] = EMPTY;
                return;
            }
            i++;
            idx = (hash1(key) + i * hash2(key)) % tableSize;
        }
    }

    void display() {
        for(int i = 0; i < tableSize; i++)
            cout << i << ": " << table[i] << endl;
    }
};

// ----------------- Main -----------------
int main() {
    cout << "----- Separate Chaining -----\n";
    HashChaining hc(7);
    hc.insert(10); hc.insert(20); hc.insert(15); hc.insert(7);
    hc.display();
    cout << "Search 15: " << hc.search(15) << endl;
    hc.remove(15);
    cout << "After removing 15:\n"; hc.display();

    cout << "\n----- Linear Probing -----\n";
    HashLinear hl(7);
    hl.insert(10); hl.insert(20); hl.insert(15); hl.insert(7);
    hl.display();
    cout << "Search 15: " << hl.search(15) << endl;
    hl.remove(15);
    cout << "After removing 15:\n"; hl.display();

    cout << "\n----- Quadratic Probing -----\n";
    HashQuadratic hq(7);
    hq.insert(10); hq.insert(20); hq.insert(15); hq.insert(7);
    hq.display();
    cout << "Search 15: " << hq.search(15) << endl;
    hq.remove(15);
    cout << "After removing 15:\n"; hq.display();

    cout << "\n----- Double Hashing -----\n";
    HashDouble hd(7);
    hd.insert(10); hd.insert(20); hd.insert(15); hd.insert(7);
    hd.display();
    cout << "Search 15: " << hd.search(15) << endl;
    hd.remove(15);
    cout << "After removing 15:\n"; hd.display();

    return 0;
}
