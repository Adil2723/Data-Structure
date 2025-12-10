#include <iostream>
using namespace std;

void merge(int a[], int beg, int mid, int end)    
{    
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    

    int LeftArray[n1], RightArray[n2]; 

    for (int i = 0; i < n1; i++)    
        LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
        RightArray[j] = a[mid + 1 + j];    

    int i = 0, j = 0, k = beg;  

    while (i < n1 && j < n2)    
    {    
        if (LeftArray[i] <= RightArray[j])    
            a[k++] = LeftArray[i++];    
        else    
            a[k++] = RightArray[j++];    
    }    

    while (i < n1)    
        a[k++] = LeftArray[i++];    

    while (j < n2)    
        a[k++] = RightArray[j++];    
}    

void mergeSort(int a[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
    }  
}    

void printArray(int a[], int n)  
{  
    for (int i = 0; i < n; i++)  
        cout << a[i] << " ";  
    cout << "\n";  
}    

int main()  
{  
    int a[] = {12, 31, 25, 8, 32, 17, 40, 42};  
    int n = sizeof(a) / sizeof(a[0]);  

    cout << "Before sorting array elements are - \n";  
    printArray(a, n);  

    mergeSort(a, 0, n - 1);  

    cout << "After sorting array elements are - \n";  
    printArray(a, n);  

    return 0;  
}  
