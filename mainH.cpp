#include "heap.h"  // Include the header file for heap class

int main (int argc, char *argv[])  // Main function with command-line arguments
{
    // Check if the number of arguments passed is not equal to 2 (program name and filename)
    if (argc != 2) {
        cerr << "Usage: ./a <filename>" << endl;  // Print error message for incorrect argument count
        return 1;  // Exit with an error code
    }

    int size = 50;  // Define the maximum size of the heap
    string filename = argv[1];  // Assign the second argument (filename) to the 'filename' variable

    HEAP heap(size);  // Create a heap object with a defined size
    int arr[10] = {2, 5, 9, 3, 7, 6, 11, 8, 10, 1};  // Initialize an array with sample data
    heap.buildH(arr, 10);  // Build the heap using the given array and size

    cout << "Heap structure after building:" << endl;  // Display message before showing heap structure
    heap.printHeap(0, 0);  // Print the structure of the heap (starting from index 0)

    ifstream infile(filename);  // Open the file with the specified filename for reading
    // Check if the file failed to open
    if (!infile) {
        cerr << "Error opening file.\n";  // Print error message if file cannot be opened
        return 1;  // Exit with an error code
    }

    string line;  // Declare a string variable to hold each line read from the file
    // Read the file line by line
    while (getline(infile, line)) {
        istringstream iss(line);  // Create a string stream object to parse the line
        int command, data, oldD, newD;  // Declare variables to store command and data values
        iss >> command;  // Read the command (first value) from the line

        // Use a switch case to handle different commands
        switch (command) {
            case 0:  // Exit case
                cout << "Exiting...!\n";  // Print exit message
                return 0;  // Exit the program
            case 1:  // Insert a value into the heap
                iss >> data;  // Read the data value to be inserted
                heap.insertH(data);  // Insert the data into the heap
                cout << "Inserted " << data << endl;  // Print the inserted data
                break;
            case 2:  // Delete the maximum value from the heap
                heap.deleteMax();  // Delete the maximum value
                cout << "Deleted Max" << endl;  // Print confirmation message
                break;
            case 3:  // Delete a specific value from the heap
                iss >> data;  // Read the value to be deleted
                heap.deleteH(data);  // Delete the specified value from the heap
                cout << "Deleted " << data << endl;  // Print the deleted value
                break;
            case 4:  // Peek the maximum value in the heap
                int max;
                max = heap.peek();  // Get the maximum value from the heap
                cout << "Max is " << max << endl;  // Print the maximum value
                break;
            case 5:  // Replace an old value with a new value in the heap
                iss >> oldD;  // Read the old value to be replaced
                iss >> newD;  // Read the new value to replace the old one
                heap.replace(oldD, newD);  // Replace the old value with the new one
                cout << "Replaced " << oldD << " with " << newD << endl;  // Print confirmation message
                break;
            case 6:  // Convert the heap from max-heap to min-heap or vice versa
                cout << "Converting Heap" << endl;  // Print conversion message
                heap.switchMinMax();  // Switch the heap from max-heap to min-heap (or vice versa)
                cout << "Heap converted." << endl;  // Print confirmation message
                break;
            case 7:  // Perform heap sort
                cout << "Heap Sort" << endl;  // Print heap sort message
                heap.heapSort(arr, 10);  // Perform heap sort on the array
                cout << "Sorted Array: ";  // Print message before showing the sorted array
                for (int i = 0; i < 10; i++) {  // Loop through the sorted array
                    cout << arr[i] << " ";  // Print each element in the sorted array
                }
                cout << endl;  // Print a newline after the sorted array
                heap.resetHeapSize();  // Reset the heap size after sorting
                break;
            case 8:  // Print the heap structure again
                cout << "The Heap looks like:" << endl;  // Print message before printing heap structure
                heap.printHeap(0, 0);  // Print the heap structure starting from index 0
                cout << endl;  // Print a newline after the heap structure
                break;

            // Handle invalid commands
            default:
                cout << "Invalid command." << endl;  // Print error message for invalid command
        }
    }

    return 0;  // Exit the program successfully
}
