#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* elements;
    int currentSize;
    int maxCapacity;

    void resizeArray() {
        int newCapacity = maxCapacity * 2;
        int* tempArray = new int[newCapacity];
        for (int i = 0; i < currentSize; ++i) {
            tempArray[i] = elements[i];
        }
        delete[] elements;
        elements = tempArray;
        maxCapacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 2) {
        elements = new int[initialCapacity];
        currentSize = 0;
        maxCapacity = initialCapacity;
    }

    ~DynamicArray() {
        delete[] elements;
    }

    void push_back(int value) {
        if (currentSize == maxCapacity) {
            resizeArray();
        }
        elements[currentSize] = value;
        ++currentSize;
    }

    void print() const {
        for (int i = 0; i < currentSize; ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }

    int getSize() const {
        return currentSize;
    }

    int getCapacity() const {
        return maxCapacity;
    }
};

int main() {
    DynamicArray arr;

    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(15);
    arr.push_back(20);

    cout << "Array elements: ";
    arr.print();

    cout << "Current size: " << arr.getSize() << endl;
    cout << "Current capacity: " << arr.getCapacity() << endl;

    return 0;
}
