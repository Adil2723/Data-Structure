#include <iostream>
using namespace std;

class MinHeap {
public:
    int* heap;        // changed from harr ? heap
    int capacity;
    int heap_size;

    MinHeap(int cap) {
        capacity = cap;
        heap_size = 0;
        heap = new int[cap];   // updated
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    // -----------------------
    // MIN HEAPIFY (DOWN)
    // -----------------------
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

    // -----------------------
    // INSERT (UP)
    // -----------------------
    void insert(int k) {
        if (heap_size == capacity) return;

        int i = heap_size;
        heap[i] = k;
        heap_size++; 

        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // -----------------------
    // REMOVE MIN (ROOT)
    // -----------------------
    int remove() {
        if (heap_size == 0) return INT_MAX;

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
// MAIN FUNCTION FOR MIN HEAP
// --------------------------------------
int main() {
    MinHeap h(20);

    h.insert(10);
    h.insert(4);
    h.insert(15);
    h.insert(20);
    h.insert(0);
    h.insert(8);

    cout << "Min Heap after insertions: ";
    h.print();

    cout << "Removed Min = " << h.remove() << endl;

    cout << "Heap after removal: ";
    h.print();

    return 0;
}
