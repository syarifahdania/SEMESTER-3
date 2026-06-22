#include <iostream>
using namespace std;

// Function to perform selection sort and track comparisons and swaps
void selectionSort(int arr[], int size, int &comparisons, int &swaps) {
    comparisons = 0; // Initialize comparison count
    swaps = 0;       // Initialize swap count

    for (int i = 0; i < size - 1; i++) {
        int minIndex = i; // Assume current index has the smallest value

        // Find the smallest value in the unsorted portion
        for (int j = i + 1; j < size; j++) {
            comparisons++; // Increment comparisons counter
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update index of smallest value
            }
        }

        // Swap the smallest value with the current element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++; // Increment swaps counter
        }
    }
}

// Function to print an array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Input array of student marks
    int marks[] = {60, 70, 95, 75, 88};
    int size = sizeof(marks) / sizeof(marks[0]);

    // Variables to track the number of comparisons and swaps
    int comparisons, swaps;

    // Display the original array
    cout << "Original list of student marks: ";
    printArray(marks, size);

    // Sort the array using selection sort
    selectionSort(marks, size, comparisons, swaps);

    // Display the sorted array
    cout << "Sorted list of student marks: ";
    printArray(marks, size);

    // Display the total number of comparisons and swaps
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;

    return 0;
}
