#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* next;

    Node(const string& s) : song(s), next(nullptr) {}
};

class Playlist {
    Node* tail; 
public:
    Playlist() : tail(nullptr) {}

    void addSong(const string& song) {
        Node* newNode = new Node(song);
        if (!tail) {
            tail = newNode;
            tail->next = tail;  // circular link
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode; 
        }
    }

    void display() {
        if (!tail) {
            cout << "Playlist is empty.\n";
            return;
        }
        Node* temp = tail->next;
        cout << "Playlist songs:\n";
        do {
            cout << "- " << temp->song << endl;
            temp = temp->next;
        } while (temp != tail->next);
    }

    void playSongs(int n) {
        if (!tail) {
            cout << "Playlist is empty, no songs to play.\n";
            return;
        }
        Node* current = tail->next;
        cout << "Playing songs:\n";
        for (int i = 0; i < n; ++i) {
            cout << current->song << endl;
            current = current->next;
        }
    }

    ~Playlist() {
        if (!tail) return;

        if (tail->next == tail) {  
            delete tail;  // only one node
            return;
        }

        Node* current = tail->next;
        tail->next = nullptr; 

        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    Playlist playlist;
    playlist.addSong("Song A");
    playlist.addSong("Song B");
    playlist.addSong("Song C");
    playlist.addSong("Song D");

    playlist.display();

    playlist.playSongs(10);

    return 0;
}
