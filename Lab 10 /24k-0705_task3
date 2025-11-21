#include <iostream>
using namespace std;

int parent(int i){ return (i-1)/2; }
int leftChild(int i){ return 2*i+1; }
int rightChild(int i){ return 2*i+2; }

class MaxHeap{
private:
    int arr[100];
    int size;

    void swapVal(int &a,int &b){
        int t=a; a=b; b=t;
    }

    void heapifyUp(int i){
        while(i!=0 && arr[parent(i)]<arr[i]){
            swapVal(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }

    void heapifyDown(int i){
        while(true){
            int l=leftChild(i);
            int r=rightChild(i);
            int largest=i;

            if(l<size && arr[l]>arr[largest]) largest=l;
            if(r<size && arr[r]>arr[largest]) largest=r;

            if(largest==i) break;

            swapVal(arr[i],arr[largest]);
            i=largest;
        }
    }

public:
    MaxHeap(){ size=0; }

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
    MaxHeap h;

    h.insertKey(5); 
    h.insertKey(3);
    h.insertKey(8);

    cout<<"After inserting A(5), B(3), C(8):"<<endl;
    h.printHeap();

    h.removeRoot();

    cout<<"After removing highest priority task:"<<endl;
    h.printHeap();

    h.insertKey(6);

    cout<<"After inserting D(6):"<<endl;
    h.printHeap();

    return 0;
}
