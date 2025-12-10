#include <iostream>
using namespace std;

class HashQuad {
public:
    int table_size;
    int *table;
    const int EMPTY = -1;
    const int DELETED = -2;

    HashQuad(int ts) {
        table_size = ts;
        table = new int[table_size];
        for (int i = 0; i < table_size; i++)
            table[i] = EMPTY;
    }

    int hash(int key) {
        return key % table_size;
    }

    void insert(int key) {
        int idx = hash(key);
        int start = idx;

        int i = 0;
        while (table[idx] != EMPTY) {
            i++;
            idx = (idx + i*i) % table_size;

            if (idx == start) {
                cout << "Hash table is full\n";
                return;
            }
        }
        table[idx] = key;
    }

    bool remove(int key) {
        int idx = hash(key);
        int start = idx;

        int i = 0;
        while (table[idx] != EMPTY) {
            if (table[idx] == key) {
                table[idx] = DELETED;
                return true;
            }
            i++;
            idx = (idx + i*i) % table_size;
            if (idx == start) break;
        }
        cout << "Key not found\n";
        return false;
    }

    bool search(int key) {
        int idx = hash(key);
        int start = idx;

        int i = 0;
        while (table[idx] != EMPTY) {
            if (table[idx] == key)
                return true;

            i++;
            idx = (idx + i*i) % table_size;   

            if (idx == start)
                break;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < table_size; i++)
            cout << i << ": " << table[i] << endl;
    }
};

int main() {
    cout << "\n----- Quadratic Probing -----\n";
    HashQuad hl(7);

    hl.insert(10);
    hl.insert(20);
    hl.insert(15);
    hl.insert(7);

    hl.display();

    cout << "Search 15: " << hl.search(15) << endl;

    hl.remove(15);
    cout << "\nAfter removing 15:\n";
    hl.display();
}
