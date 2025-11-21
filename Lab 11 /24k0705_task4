#include <iostream>
#include <string>
using namespace std;

class StudentHashTable {
    struct StudentRecord {
        int rollNumber;
        string studentName;
        bool empty;
        bool deleted;
        StudentRecord() : rollNumber(0), studentName(""), empty(true), deleted(false) {}
    };

    int size = 15;
    StudentRecord records[15];

    int hashFunc(int roll) {
        return roll % size;
    }

public:
    void InsertRecord(int roll, string name) {
        int index = hashFunc(roll);
        int attempt = 0;
        int probeIndex = index;

        while(!records[probeIndex].empty && !records[probeIndex].deleted) {
            attempt++;
            if(attempt == size) {
                cout << "Hash table full! Cannot insert roll " << roll << endl;
                return;
            }
            probeIndex = (index + attempt * attempt) % size;
        }

        records[probeIndex].rollNumber = roll;
        records[probeIndex].studentName = name;
        records[probeIndex].empty = false;
        records[probeIndex].deleted = false;
        cout << "Inserted: " << roll << " - " << name << endl;
    }

    void SearchRecord(int roll) {
        int index = hashFunc(roll);
        int attempt = 0;
        int probeIndex = index;

        while(!records[probeIndex].empty && attempt < size) {
            if(!records[probeIndex].deleted && records[probeIndex].rollNumber == roll) {
                cout << "Record found: " << records[probeIndex].studentName << endl;
                return;
            }
            attempt++;
            probeIndex = (index + attempt * attempt) % size;
        }

        cout << "Record not found\n";
    }

    void DisplayTable() {
        cout << "Hash Table:\n";
        for(int i = 0; i < size; i++) {
            cout << i << ": ";
            if(records[i].empty) cout << "EMPTY";
            else if(records[i].deleted) cout << "DELETED";
            else cout << records[i].rollNumber << " - " << records[i].studentName;
            cout << endl;
        }
    }
};

int main() {
    StudentHashTable studentTable;

    studentTable.InsertRecord(101, "Ali");
    studentTable.InsertRecord(102, "Babar");
    studentTable.InsertRecord(116, "Saad");
    studentTable.InsertRecord(131, "Dhoni");
    studentTable.InsertRecord(146, "Starc");

    cout << "\nCurrent Table:\n";
    studentTable.DisplayTable();

    cout << "\nSearching Records:\n";
    studentTable.SearchRecord(116);
    studentTable.SearchRecord(150);

    return 0;
}
