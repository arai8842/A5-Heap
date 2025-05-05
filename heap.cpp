#include "heap.h"

// Constructor: Initializes the heap with the given size
HEAP::HEAP(int size) {
    capacity = size;          // Set the capacity to the provided size
    heapSize = 0;             // Initialize heap size to 0
    array = new int[capacity]; // Dynamically allocate memory for the heap array
}

// Destructor: Cleans up the heap's memory
HEAP::~HEAP() {
    delete[] array;  // Deallocate the memory used by the heap array
}

// Returns the index of the left child of a given index
int HEAP::leftChild(int index) {
    return 2 * index + 1;  // Formula for left child index in a binary heap
}

// Returns the index of the right child of a given index
int HEAP::rightChild(int index) {
    return 2 * index + 2;  // Formula for right child index in a binary heap
}

// Returns the index of the parent of a given index
int HEAP::parent(int index) {
    return (index - 1) / 2;  // Formula for parent index in a binary heap
}

// Inserts an element into the heap
void HEAP::insertH(int data) {
    if (heapSize == capacity) {  // Check if heap is full
        cout << "Heap overflow - can't insert" << endl;
        return;
    }

    array[heapSize] = data;  // Place the new element at the end of the heap
    heapifyUp(heapSize);      // Ensure the heap property is maintained by bubbling up
    heapSize++;               // Increment the heap size
}

// Maintains heap property by bubbling up the element at the given index
void HEAP::heapifyUp(int index) {
    while (index != 0 && array[parent(index)] < array[index]) {  // Check if the parent is smaller
        swap(array[parent(index)], array[index]);  // Swap the parent with the current element
        index = parent(index);  // Move the index up to the parent
    }
}

// Returns the maximum element (root) without removing it
int HEAP::peek() {
    if (heapSize <= 0) {  // Check if the heap is empty
        cout << "Heap is empty" << endl;
        return -1;  // Return -1 to indicate the heap is empty
    }
    return array[0];  // Return the root element, which is the maximum in a max-heap
}

// Removes the maximum element (root) from the heap
void HEAP::deleteMax() {
    if (heapSize <= 0) {  // Check if the heap is empty
        cout << "Heap is empty - nothing to delete" << endl;
        return;
    }

    if (heapSize == 1) {  // If there is only one element
        heapSize--;        // Simply decrease the heap size
        return;
    }

    array[0] = array[heapSize - 1];  // Replace the root with the last element
    heapSize--;                      // Decrease the heap size
    heapifyDown(0);                   // Restore heap property by bubbling down the root
}

// Removes a specific element from the heap
void HEAP::deleteH(int data) {
    int index = -1;
    for (int i = 0; i < heapSize; i++) {  // Search for the element
        if (array[i] == data) {  // Element found
            index = i;
            break;
        }
    }

    if (index == -1) {  // If element not found
        cout << "Element not found - can't delete" << endl;
        return;
    }

    array[index] = array[heapSize - 1];  // Replace the element with the last one
    heapSize--;                           // Decrease heap size
    heapifyDown(index);                   // Restore heap property by bubbling down the replaced element
}

// Maintains heap property by bubbling down the element at the given index
void HEAP::heapifyDown(int index) {
    int left = leftChild(index);  // Get the left child index
    int right = rightChild(index); // Get the right child index
    int largest = index;           // Assume the current index is the largest

    if (left < heapSize && array[left] > array[largest])  // If left child is larger
        largest = left;
    if (right < heapSize && array[right] > array[largest])  // If right child is larger
        largest = right;

    if (largest != index) {  // If the largest is not the current element
        swap(array[index], array[largest]);  // Swap with the largest child
        heapifyDown(largest);  // Recursively bubble down the affected child
    }
}

// Builds a max heap from the given array
void HEAP::buildH(int arr[], int n) {
    for (int i = 0; i < n; i++) {  // Copy the elements into the heap array
        array[i] = arr[i];
    }
    heapSize = n;  // Set the heap size to the array's size

    for (int i = parent(n - 1); i >= 0; i--) {  // Start from the last parent and heapify down
        heapifyDown(i);
    }
}

// Replaces an old value with a new value in the heap
void HEAP::replace(int oldData, int newData) {
    int index = -1;
    for (int i = 0; i < heapSize; i++) {  // Search for the old value
        if (array[i] == oldData) {  // Element found
            index = i;
            break;
        }
    }

    if (index == -1) {  // If element not found
        cout << "Element not found - can't replace" << endl;
        return;
    }

    array[index] = newData;  // Replace the old value with the new one
    heapifyDown(index);      // Restore heap property by bubbling down
    heapifyUp(index);        // Ensure the new value is correctly positioned by bubbling up
}

// Sorts the array using heap sort
void HEAP::heapSort(int arr[], int n) {
    buildH(arr, n);  // Build the heap from the array
    int tempSize = heapSize;  // Save the current heap size

    for (int i = n - 1; i >= 0; i--) {  // Swap the root (max) with the last element
        swap(array[0], array[i]);
        heapSize--;  // Decrease the heap size
        heapifyDown(0);  // Restore heap property for the reduced heap
    }

    heapSize = tempSize;  // Restore the original heap size
}

// Prints the heap elements in a structured way for visualization
void HEAP::printHeap(int index, int depth) {
    if (index >= heapSize)  // If the index is out of bounds, stop
        return;

    printHeap(rightChild(index), depth + 1);  // Print the right subtree first

    for (int i = 0; i < depth; i++) {  // Print indentation based on depth
        cout << "  ";
    }

    cout << array[index] << endl;  // Print the current element

    printHeap(leftChild(index), depth + 1);  // Print the left subtree
}

// Switches the heap from Max Heap to Min Heap or vice versa
void HEAP::switchMinMax() {
    for (int i = 0; i < heapSize; i++) {  // Negate all elements in the heap
        array[i] = -array[i];
    }
    for (int i = parent(heapSize - 1); i >= 0; i--) {  // Restore heap property for the negated values
        heapifyDown(i);
    }
}

// Resets the heap size to 0
void HEAP::resetHeapSize() {
    heapSize = 0;  // Set the heap size to 0
}
