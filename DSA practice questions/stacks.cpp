#include<iostream>
#include<string>

using namespace std;

class Stack{
    string name[100];
    string number[100];
    float duration[100];
    int topIndex;
    int capacity;
    
public:
    Stack(int cap = 100){
        capacity = cap;
        topIndex = -1;
    }
    
    bool isFull() {
        return topIndex == capacity - 1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void push(string n, string num, float du){
        if (isFull()) {
            cout << "Stack Overflow\n";
        } else {
            topIndex++;
            name[topIndex] = n;
            number[topIndex] = num;
            duration[topIndex] = du;
        }
    }
    
    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow\n";
        }
        else{
            string n = name[topIndex];
            string num = number[topIndex];
            float du = duration[topIndex];

            cout << "Popped Call -> Name: " << n << ", Number: " << num  
                 << ", Duration: " << du << " mins\n";
            --topIndex;
        }
    }
    
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top Call -> Name: " << name[topIndex]  
             << ", Number: " << number[topIndex]  
             << ", Duration: " << duration[topIndex] << " mins\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Call History:\n";
        for (int i = 0; i <= topIndex; i++) {
            cout << i + 1 << ". Name: " << name[i]
                 << ", Number: " << number[i]
                 << ", Duration: " << duration[i] << " mins\n";
        }
    }
};

int main() {
    Stack callStack;   

    int choice;
    string n, num;
    float du;

    do {
        cout << "\n--- Call History Menu ---\n";
        cout << "1. Add Call (Push)\n";
        cout << "2. Remove Last Call (Pop)\n";
        cout << "3. View Last Call (Peek)\n";
        cout << "4. Display All Calls\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                cin >> n;
                cout << "Enter Number: ";
                cin >> num;
                cout << "Enter Duration (mins): ";
                cin >> du;
                callStack.push(n, num, du);
                break;

            case 2:
                callStack.pop();
                break;

            case 3:
                callStack.peek();
                break;

            case 4:
                callStack.display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
