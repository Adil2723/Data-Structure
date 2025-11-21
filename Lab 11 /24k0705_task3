#include <iostream>
using namespace std;

class Hash {
    int tableSize;
    int* table;
    const int EMPTY = -1;
    const int DELETED = -2;

public:
    Hash(int size) {
        tableSize = size;
        table = new int[tableSize];
        for(int i = 0; i < tableSize; i++)
            table[i] = EMPTY;
    }

    int hashFunction(int key) {
        return key % tableSize;
    }

    void insert(int key) {
        int h = hashFunction(key);
        int idx = h;
        int i = 0;

        while(table[idx] != EMPTY && table[idx] != DELETED) {
            i++;
            if(i == tableSize) {
                cout << "Hash table full! Cannot insert " << key << endl;
                return;
            }
            idx = (h + i*i) % tableSize;
        }

        table[idx] = key;
        cout << "Inserted " << key << endl;
    }

    void remove(int key) {
        int h = hashFunction(key);
        int idx = h;
        int i = 0;

        while(table[idx] != EMPTY && i < tableSize) {
            if(table[idx] == key) {
                table[idx] = DELETED;
                cout << "Deleted " << key << endl;
                return;
            }
            i++;
            idx = (h + i*i) % tableSize;
        }

        cout << "Key " << key << " not found\n";
    }

    bool search(int key) {
        int h = hashFunction(key);
        int idx = h;
        int i = 0;

        while(table[idx] != EMPTY && i < tableSize) {
            if(table[idx] == key) {
                cout << key << " FOUND\n";
                return true;
            }
            i++;
            idx = (h + i*i) % tableSize;
        }

        cout << key << " NOT FOUND\n";
        return false;
    }

    void display() {
        cout << "Hash Table:\n";
        for(int i = 0; i < tableSize; i++) {
            cout << i << ": ";
            if(table[i] == EMPTY) cout << "EMPTY";
            else if(table[i] == DELETED) cout << "DELETED";
            else cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    Hash h(11);

    h.insert(10);
    h.insert(22);
    h.insert(31);
    h.insert(4);
    h.insert(15);
    h.insert(28);
    h.insert(17);
    h.insert(88);

    h.display();

    h.remove(31);
    h.remove(4);

    h.display();

    h.search(15);
    h.search(100);

    return 0;
}
