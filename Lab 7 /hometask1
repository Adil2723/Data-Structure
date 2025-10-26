#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int score;
    Student* next;
    Student(string n, int s) : name(n), score(s), next(nullptr) {}
};

class StudentList {
private:
    Student* head;

    int getMax() {
        int maxVal = 0;
        Student* temp = head;
        while (temp) {
            if (temp->score > maxVal)
                maxVal = temp->score;
            temp = temp->next;
        }
        return maxVal;
    }

    int getDigit(int number, int place) {
        while (place--)
            number /= 10;
        return number % 10;
    }

public:
    StudentList() : head(nullptr) {}

    void insert(string name, int score) {
        Student* newNode = new Student(name, score);
        if (!head) {
            head = newNode;
            return;
        }
        Student* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void radixSort() {
        if (!head)
            return;

        int maxVal = getMax();

        for (int place = 0; maxVal / (1 << (place * 3)) > 0; place++) {
            Student* buckets[10] = {nullptr};
            Student* tails[10] = {nullptr};

            Student* curr = head;
            while (curr) {
                int digit = getDigit(curr->score, place);

                if (!buckets[digit]) {
                    buckets[digit] = tails[digit] = curr;
                } else {
                    tails[digit]->next = curr;
                    tails[digit] = curr;
                }
                curr = curr->next;
            }

            head = nullptr;
            Student* tail = nullptr;

            for (int i = 0; i < 10; i++) {
                if (buckets[i]) {
                    if (!head) {
                        head = buckets[i];
                        tail = tails[i];
                    } else {
                        tail->next = buckets[i];
                        tail = tails[i];
                    }
                }
            }

            if (tail)
                tail->next = nullptr;
        }
    }

    void display() {
        cout << "\nSorted Student List:\n";
        Student* temp = head;
        while (temp) {
            cout << temp->name << " - " << temp->score << endl;
            temp = temp->next;
        }
    }
};

int main() {
    StudentList list;
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cout << "\nEnter name: ";
        cin >> name;
        cout << "Enter score: ";
        cin >> score;
        list.insert(name, score);
    }

    list.radixSort();
    list.display();

    return 0;
}
