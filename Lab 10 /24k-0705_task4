#include <iostream>
using namespace std;

int parent(int i){ return (i-1)/2; }
int leftChild(int i){ return 2*i+1; }
int rightChild(int i){ return 2*i+2; }

class MinHeap{
private:
    int arr[100];
    int size;

    void swapVal(int &a,int &b){
        int t=a; a=b; b=t;
    }

    void heapifyUp(int i){
        while(i!=0 && arr[parent(i)]>arr[i]){
            swapVal(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }

    void heapifyDown(int i){
        while(true){
            int l=leftChild(i);
            int r=rightChild(i);
            int smallest=i;

            if(l<size && arr[l]<arr[smallest]) smallest=l;
            if(r<size && arr[r]<arr[smallest]) smallest=r;

            if(smallest==i) break;

            swapVal(arr[i],arr[smallest]);
            i=smallest;
        }
    }

public:
    MinHeap(){ size=0; }

    void insertKey(int val){
        arr[size]=val;
        heapifyUp(size);
        size++;
    }

    void removeRoot(){
        if(size==0) return;
        arr[0]=arr[size-1];
        size--;
        heapifyDown(0);
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

    h.insertKey(100);
    h.insertKey(50);
    h.insertKey(75);
    h.insertKey(60);

    cout<<"Initial Heap:"<<endl;
    h.printHeap();

    h.insertKey(55);

    cout<<"After inserting 55:"<<endl;
    h.printHeap();

    h.removeRoot();

    cout<<"After removing lowest price order:"<<endl;
    h.printHeap();

    return 0;
}
