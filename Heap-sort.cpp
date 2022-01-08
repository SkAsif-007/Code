#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int pass=0;
void Heapify(int arr[], int i, int HeapSize)
{
    int largest;
    int l = 2 * i;
    int r = 2 * i + 1;
    if (l <= HeapSize && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if (r <= HeapSize && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        Heapify(arr, largest, HeapSize);
    }
}

void BuildHeap(int arr[], int HeapSize)
{
    for (int i = int(HeapSize / 2); i >= 1; --i)
        Heapify(arr, i, HeapSize);
}

void HeapSort(int arr[], int HeapSize)
{
    int n= HeapSize;
    BuildHeap(arr, HeapSize);
    cout << "\n\nArray after building Heap:  ";
    for (int i = 1; i <= HeapSize; ++i)
        cout << arr[i] << "  ";
    for (int i = HeapSize; i >= 2; --i)
    {
        int temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;

        HeapSize -= 1;

        cout << "\n\nPass "<<++pass<<"  :";
        for (int i = 1; i <= n; i++)
            cout << arr[i] << "  ";
        Heapify(arr, 1, HeapSize);
    }
}

int main(void)
{
    int x;
    cout << "Enter number of elements:  ";
    cin >> x;
    int arr[x];
    cout << endl;
    for (int i = 1; i <= x; ++i)
    {
        cout << "Enter element no." << i << ": ";
        cin >> arr[i];
    }

    cout << "\nArray before sorting:   ";
    for (int i = 1; i <= x; ++i)
        cout << arr[i] << "  ";

    HeapSort(arr, x);
    cout << "\n\nArray after sorting:   ";
    for (int i = 1; i <= x; ++i)
        cout << arr[i] << "  ";

    return 0;
}
