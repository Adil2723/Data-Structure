#include <iostream>
using namespace std;

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
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap_size && heap[l] < heap[smallest])
            smallest = l;

        if (r < heap_size && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    void insert(int k) {
        if (heap_size == capacity) {
            cout << "Heap overflow!" << endl;
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
        for (int i = 0; i < heap_size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap h(10);

    h.insert(10);
    h.insert(12);
    h.insert(14);
    h.insert(3);
    h.insert(5);
    h.insert(7);
    h.insert(1);

    cout << "Heap elements: ";
    h.print();

    cout << "Removed element: " << h.remove() << endl;

    cout << "Heap after removal: ";
    h.print();

    return 0;
}
