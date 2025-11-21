#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 50;

class EmployeeHashTable {
private:
    string table[TABLE_SIZE];
    bool deleted[TABLE_SIZE];

    int h1(const string& name) {
        int sum = 0;
        for (char ch : name) sum += int(ch);
        return sum % TABLE_SIZE;
    }

    int h2(const string& name) {
        int sum = 0;
        for (char ch : name) sum += int(ch);
        return 7 - (sum % 7);
    }

public:
    EmployeeHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = "";
            deleted[i] = false;
        }
    }

    void insert(const string& name) {
        int index1 = h1(name);
        int index2 = h2(name);
        int i = 0;
        int newIndex = index1;

        while (!table[newIndex].empty() && !deleted[newIndex]) {
            i++;
            newIndex = (index1 + i * index2) % TABLE_SIZE;
        }

        table[newIndex] = name;
        deleted[newIndex] = false;
        cout << "Employee \"" << name << "\" inserted at index " << newIndex << endl;
    }

    bool search(const string& name) {
        int index1 = h1(name);
        int index2 = h2(name);
        int i = 0;
        int newIndex = index1;

        while (!table[newIndex].empty() && i < TABLE_SIZE) {
            if (!deleted[newIndex] && table[newIndex] == name) {
                cout << "Employee \"" << name << "\" found at index " << newIndex << endl;
                return true;
            }
            i++;
            newIndex = (index1 + i * index2) % TABLE_SIZE;
        }

        cout << "Employee \"" << name << "\" not found." << endl;
        return false;
    }

    bool remove(const string& name) {
        int index1 = h1(name);
        int index2 = h2(name);
        int i = 0;
        int newIndex = index1;

        while (!table[newIndex].empty() && i < TABLE_SIZE) {
            if (!deleted[newIndex] && table[newIndex] == name) {
                deleted[newIndex] = true;
                cout << "Employee \"" << name << "\" removed from index " << newIndex << endl;
                return true;
            }
            i++;
            newIndex = (index1 + i * index2) % TABLE_SIZE;
        }

        cout << "Employee \"" << name << "\" not found for removal." << endl;
        return false;
    }

    void display() {
        cout << "\nEmployee Hash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i].empty() || deleted[i])
                cout << i << ": ---\n";
            else
                cout << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    EmployeeHashTable empTable;


    empTable.insert("Ali");
    empTable.insert("Babar");
    empTable.insert("Faisal");
    empTable.insert("Danish");


    empTable.search("Ali");
    empTable.search("Ahsan");

    empTable.remove("Danish");
    empTable.remove("Ali");

    empTable.display();

    return 0;
}
