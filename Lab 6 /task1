#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Call {
public:
    string name;
    string number;
    int duration;

    Call(string n, string num, int d) {
        name = n;
        number = num;
        duration = d;
    }
};

class CallHistory {
private:
    stack<Call> history;

public:
    void push(Call c) {
        history.push(c);
        cout << "Call Added Successfully!" << endl;
        display();
    }

    void pop() {
        if(history.empty()) {
            cout << "No call history to delete!" << endl;
        } else {
            cout << "Deleting the most recent call: " 
                 << history.top().name << endl;
            history.pop();
            display();
        }
    }

    void top() {
        if(history.empty()) {
            cout << "Call history is empty!" << endl;
        } else {
            Call c = history.top();
            cout << "Most Recent Call:\n";
            cout << "Name: " << c.name << "\nNumber: " << c.number 
                 << "\nDuration: " << c.duration << " seconds\n";
        }
    }

    void empty() {
        if(history.empty())
            cout << "Call history is empty!" << endl;
        else
            cout << "Call history is not empty!" << endl;
    }

    void display() {
        if(history.empty()) {
            cout << "[No Calls in History]\n";
            return;
        }

        cout << "\nCurrent Call Log\n";
        stack<Call> temp = history; 

        while(!temp.empty()) {
            Call c = temp.top();
            cout << "Name: " << c.name 
                 << ", Number: " << c.number 
                 << ", Duration: " << c.duration << " sec\n";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    CallHistory obj;
    int choice;

    do {
        cout << "\n1. Add Call\n2. Delete Last Call\n3. View Most Recent Call"
             << "\n4. Check if Empty\n5. Exit\nEnter choice: ";
        cin >> choice;

        if(choice == 1) {
            string name, number;
            int duration;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Number: ";
            cin >> number;
            cout << "Enter Duration (sec): ";
            cin >> duration;

            obj.push(Call(name, number, duration));
        }
        else if(choice == 2) obj.pop();
        else if(choice == 3) obj.top();
        else if(choice == 4) obj.empty();

    } while(choice != 5);

    cout << "Call history program terminated." << endl;
    return 0;
}
