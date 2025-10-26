#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* next;
    Node(string u) : url(u), next(NULL) {}
};

void backTwice(Node*& head, stack<string>& historyStack) {
    for(int i = 0; i < 2; i++) {
        if(!historyStack.empty()) {
            historyStack.pop();
        }
        if(head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    if(!historyStack.empty()) {
        cout << "Current Page: " << historyStack.top() << endl;
    } else {
        cout << "No pages left in history!" << endl;
    }
}

int main() {
    Node* head = new Node("Instagram");
    head->next = new Node("LinkedIn");
    head->next->next = new Node("Twitter");
    head->next->next->next = new Node("Facebook");
    head->next->next->next->next = new Node("Google");

    stack<string> historyStack;
    historyStack.push("Google");
    historyStack.push("Facebook");
    historyStack.push("Twitter");
    historyStack.push("LinkedIn");
    historyStack.push("Instagram");

    cout << "Going back twice...\n";
    backTwice(head, historyStack);

    return 0;
}
