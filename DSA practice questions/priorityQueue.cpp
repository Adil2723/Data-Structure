#include <iostream>
#include <climits>
using namespace std;

// ==================== MIN HEAP ====================
class MinHeap {
public:
    int* heap;
    int capacity;
    int heap_size;

    MinHeap(int cap) {
        capacity = cap;
        heap_size = 0;
        heap = new int[cap];
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapify(int i) {
        int l = left(i), r = right(i), smallest = i;

        if (l < heap_size && heap[l] < heap[smallest]) smallest = l;
        if (r < heap_size && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    void insert(int k) {
        if (heap_size == capacity) {
            cout << "Min Heap Overflow!" << endl;
            return;
        }

        int i = heap_size;
        heap[i] = k;
        heap_size++;

        while (i != 0 && heap[i] < heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    int remove() {
        if (heap_size == 0) return INT_MAX;
        int root = heap[0];
        heap[0] = heap[heap_size - 1];
        heap_size--;
        heapify(0);
        return root;
    }

    void print() {
        for (int i = 0; i < heap_size; i++) cout << heap[i] << " ";
        cout << endl;
    }
};

// ==================== MAX HEAP ====================
class MaxHeap {
public:
    int* heap;
    int capacity;
    int heap_size;

    MaxHeap(int cap) {
        capacity = cap;
        heap_size = 0;
        heap = new int[cap];
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapify(int i) {
        int l = left(i), r = right(i), largest = i;

        if (l < heap_size && heap[l] > heap[largest]) largest = l;
        if (r < heap_size && heap[r] > heap[largest]) largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    void insert(int k) {
        if (heap_size == capacity) {
            cout << "Max Heap Overflow!" << endl;
            return;
        }

        int i = heap_size;
        heap[i] = k;
        heap_size++;

        while (i != 0 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    int remove() {
        if (heap_size == 0) return INT_MIN;
        int root = heap[0];
        heap[0] = heap[heap_size - 1];
        heap_size--;
        heapify(0);
        return root;
    }

    void print() {
        for (int i = 0; i < heap_size; i++) cout << heap[i] << " ";
        cout << endl;
    }
};

// ==================== PRIORITY QUEUE (MIN) USING LINKED LIST ====================
class PQNode {
public:
    int data;
    PQNode* next;
    PQNode(int val) { data = val; next = nullptr; }
};

class PriorityQueueLL {
private:
    PQNode* head;

public:
    PriorityQueueLL() { head = nullptr; }

    void insert(int val) {
        PQNode* newNode = new PQNode(val);
        if (!head || val < head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }

        PQNode* temp = head;
        while (temp->next && temp->next->data <= val) temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    int remove() {
        if (!head) {
            cout << "Priority Queue Underflow!" << endl;
            return -1;
        }
        int val = head->data;
        PQNode* temp = head;
        head = head->next;
        delete temp;
        return val;
    }

    int peek() {
        if (!head) {
            cout << "Priority Queue Empty!" << endl;
            return -1;
        }
        return head->data;
    }

    void print() {
        PQNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ==================== MAIN FUNCTION ====================
int main() {
    cout << "===== MIN HEAP =====" << endl;
    MinHeap minH(10);
    int minValues[] = {15, 10, 20, 8, 12, 25, 5};
    for (int v : minValues) minH.insert(v);
    minH.print();
    cout << "Removed: " << minH.remove() << endl;
    minH.print();
    cout << "Removed: " << minH.remove() << endl;
    minH.print();

    cout << "\n===== MAX HEAP =====" << endl;
    MaxHeap maxH(10);
    int maxValues[] = {7, 3, 10, 1, 5, 8};
    for (int v : maxValues) maxH.insert(v);
    maxH.print();
    cout << "Removed: " << maxH.remove() << endl;
    maxH.print();

    cout << "\n===== PRIORITY QUEUE (LL) =====" << endl;
    PriorityQueueLL pq;
    int pqValues[] = {5, 2, 8, 1};
    for (int v : pqValues) pq.insert(v);
    pq.print();
    cout << "Removed: " << pq.remove() << endl;
    pq.print();
    cout << "Peek: " << pq.peek() << endl;

    return 0;
}
