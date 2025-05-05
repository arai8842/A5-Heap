// include guard
#ifndef HEAP_H
#define HEAP_H

// header file
#include <iostream>  // for input/output stream operations
#include <fstream>   // for file operations
#include <string>    // for using string data types
#include <sstream>   // for string stream operations

using namespace std;

// HEAP class definition
class HEAP 
{
    private:
        int* array;    // Pointer to the array that stores heap elements
        int capacity;  // Total capacity of the heap (maximum size of the array)
        int heapSize;  // Current size of the heap (number of elements in the heap)

        // Helper functions to get the left child, right child, and parent of a given index
        int leftChild(int index);  // Returns the index of the left child
        int rightChild(int index); // Returns the index of the right child
        int parent(int index);     // Returns the index of the parent

        // These are for a Max Heap
        void heapifyUp(int index);    // Maintains heap property after insertion (bubbling up)
        void heapifyDown(int index);  // Maintains heap property after deletion (bubbling down)

        // Helper function for a Min Heap - only if you do the Extra Credit
        void heapifyDownMin(int index);  // Maintains heap property in a Min Heap after deletion (bubbling down)

    public:
        HEAP(int size);         // Constructor: Initializes the heap with the given size
        ~HEAP();                // Destructor: Cleans up the heap's memory

        void buildH(int arr[], int n); // Builds a max heap from the given array (complete this)
        void insertH(int data);        // Inserts an element into the heap
        void deleteMax();              // Removes the maximum element (root) from the heap
        void deleteH(int data);        // Removes a specific element from the heap
        int peek();                    // Returns the maximum element (root) without removing it

        void replace(int oldData, int newData);  // Replaces an old value with a new value in the heap (complete this)
        void heapSort(int arr[], int n);          // Sorts the given array using heap sort (complete this)

        void printHeap(int index, int depth);    // Prints the heap elements for visualization

        void switchMinMax();  // Converts Max Heap to Min Heap or vice versa (for Extra Credit)

        void resetHeapSize();  // Resets the heap size to its initial capacity
};

#endif
