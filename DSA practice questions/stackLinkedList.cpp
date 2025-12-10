#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string url;
    Node* next;

    Node(string u) {
        url = u;
        next = nullptr;
    }
};


class BrowserHistory {
private:
    Node* head;   
    Node* top;    

public:
    BrowserHistory() {
        head = nullptr;
        top = nullptr;
    }

    void visit(string url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
        
        Node* stackNode = new Node(url);
        stackNode->next = top;
        top = stackNode;
    }
    
    void goBack(int n) {
        for (int i = 0; i < n; i++) {
            if (!top) {
                cout << "No more pages to go back.\n";
                break;
            }
            top = top->next;     
            Node* temp = head;
            head = head->next;    
            delete temp;
        }
    }

    void currentPage() {
        if (head)
            cout << "Current page: " << head->url << endl;
        else
            cout << "No pages visited.\n";
    }

    void displayHistory() {
        Node* temp = head;
        cout << "Browsing History (most recent first):\n";
        while (temp) {
            cout << temp->url << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    BrowserHistory browser;

    // User visits 5 websites
    browser.visit("Google");
    browser.visit("Facebook");
    browser.visit("Twitter");
    browser.visit("LinkedIn");
    browser.visit("Instagram");

    browser.displayHistory();
    browser.currentPage();

    // User clicks "back" twice
    browser.goBack(2);

    browser.displayHistory();
    browser.currentPage();

    return 0;
}
