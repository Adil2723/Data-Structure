#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int ticketID;
    string customerName;
    string rideName;
    Node* next;

    Node(int id, string name, string ride) {
        ticketID = id;
        customerName = name;
        rideName = ride;
        next = nullptr;
    }
};

class BookingSystem {
    Node* tail;

public:
    BookingSystem() { tail = nullptr; }

    void issueTicketEnd(int id, string name, string ride) {
        Node* newNode = new Node(id, name, ride);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void issuePriorityFront(int id, string name, string ride) {
        Node* newNode = new Node(id, name, ride);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
    }

    void cancelTicketByID(int id) {
        if (!tail) {
            cout << "No tickets booked." << endl;
            return;
        }
        Node* curr = tail->next;
        Node* prev = tail;
        do {
            if (curr->ticketID == id) {
                if (curr == tail && curr == tail->next) {
                    delete curr;
                    tail = nullptr;
                } else {
                    prev->next = curr->next;
                    if (curr == tail) tail = prev;
                    delete curr;
                }
                cout << "Ticket ID " << id << " cancelled." << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Ticket ID " << id << " not found." << endl;
    }

    void cancelFirstTicket() {
        if (!tail) {
            cout << "No tickets booked." << endl;
            return;
        }
        Node* head = tail->next;
        if (head == tail) {
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
        cout << "First ticket cancelled." << endl;
    }

    void searchTicketByID(int id) {
        if (!tail) {
            cout << "No tickets booked." << endl;
            return;
        }
        Node* curr = tail->next;
        do {
            if (curr->ticketID == id) {
                cout << "Ticket Found: ID=" << curr->ticketID 
                     << ", Customer=" << curr->customerName 
                     << ", Ride=" << curr->rideName << endl;
                return;
            }
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Ticket ID " << id << " not found." << endl;
    }

    void displayAllTickets() {
        if (!tail) {
            cout << "No tickets booked." << endl;
            return;
        }
        cout << "Tickets in Circular Order:" << endl;
        Node* curr = tail->next;
        do {
            cout << "ID=" << curr->ticketID 
                 << ", Customer=" << curr->customerName 
                 << ", Ride=" << curr->rideName << endl;
            curr = curr->next;
        } while (curr != tail->next);
    }

    void countTickets() {
        if (!tail) {
            cout << "Total Tickets: 0" << endl;
            return;
        }
        int count = 0;
        Node* curr = tail->next;
        do {
            count++;
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Total Tickets: " << count << endl;
    }

    void nextTicketAfterID(int id) {
        if (!tail) {
            cout << "No tickets booked." << endl;
            return;
        }
        Node* curr = tail->next;
        do {
            if (curr->ticketID == id) {
                cout << "Next Ticket: ID=" << curr->next->ticketID 
                     << ", Customer=" << curr->next->customerName 
                     << ", Ride=" << curr->next->rideName << endl;
                return;
            }
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Ticket ID " << id << " not found." << endl;
    }
};

int main() {
    BookingSystem system;

    system.issueTicketEnd(1, "Alice", "Roller Coaster");
    system.issueTicketEnd(2, "Bob", "Ferris Wheel");
    system.issueTicketEnd(3, "Charlie", "Haunted House");
    system.issuePriorityFront(0, "VIP_Jane", "Water Ride");

    system.displayAllTickets();
    cout << endl;

    system.cancelFirstTicket();
    system.displayAllTickets();
    cout << endl;

    system.searchTicketByID(2);
    system.cancelTicketByID(3);
    system.displayAllTickets();
    cout << endl;

    system.countTickets();
    system.nextTicketAfterID(1);

    return 0;
}
