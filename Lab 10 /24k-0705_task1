#include <iostream>
using namespace std;

int parent(int i){ return (i-1)/2; }
int leftChild(int i){ return 2*i+1; }
int rightChild(int i){ return 2*i+2; }

class MinHeap{
private:
    int arr[100];
    int size;

    void swap(int &a,int &b){
        int t=a; a=b; b=t;
    }

    void heapifyUp(int i){
        while(i!=0 && arr[parent(i)]>arr[i]){
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }

public:
    MinHeap(){
        size=0;
    }

    void insertKey(int val){
        arr[size]=val;
        heapifyUp(size);
        size++;
    }

    void printHeap(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    MinHeap h;
    h.insertKey(1);
    h.insertKey(3);
    h.insertKey(4);
    h.insertKey(5);

    cout<<"Initial Heap:"<<endl;
    h.printHeap();

    h.insertKey(2);

    cout<<"Heap After Inserting 2:"<<endl;
    h.printHeap();

    return 0;
}
