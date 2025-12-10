#include <iostream>
using namespace std;

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
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    // -----------------------
    // MAX HEAPIFY (DOWN)
    // -----------------------
    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heap_size && heap[l] > heap[largest])
            largest = l;

        if (r < heap_size && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    // -----------------------
    // INSERT (UP)
    // -----------------------
    void insert(int k) {
        if (heap_size == capacity) return;

        int i = heap_size;
        heap[i] = k;
        heap_size++;

        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // -----------------------
    // REMOVE MAX (ROOT)
    // -----------------------
    int remove() {
        if (heap_size == 0) return INT_MIN;

        int root = heap[0];
        heap[0] = heap[heap_size - 1];
        heap_size--;
        heapify(0);

        return root;
    }

    void print() {
        for (int i = 0; i < heap_size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

// --------------------------------------
// MAIN FUNCTION FOR MAX HEAP
// --------------------------------------
int main() {
    MaxHeap h(20);

    h.insert(10);
    h.insert(40);
    h.insert(15);
    h.insert(30);
    h.insert(5);
    h.insert(8);

    cout << "Max Heap after insertions: ";
    h.print();

    cout << "Removed Max = " << h.remove() << endl;

    cout << "Heap after removal: ";
    h.print();

    return 0;
}
