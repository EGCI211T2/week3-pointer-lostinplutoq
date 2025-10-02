#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    int *pa, *pb, i, temp;

    // Get dynamic size
    cout << "Enter the size of the array: ";
    cin >> n;

    // Check for size
    if (n <= 0) {
        cout << "Error: The size must be a positive number." << endl;
        return 1;
    }

    // Allocate memory for the array
    int *a = new int[n];
    pa = a; // pa points to the first element of new array

    // Input values to the array
    cout << "Enter " << n << " integer values" << endl;
    for (i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> pa[i];
    }
    
    // Print the original array
    cout << "\nOriginal: ";
    for (i = 0; i < n; i++) {
        cout << setw(3) << pa[i];
    }
    cout << endl;

    // Reverse the array
    pb = &pa[n - 1]; // pb points to the last element
    for (i = 0; i < n / 2; i++) {
        temp = *pa;  // Store the value at the beginning
        *pa = *pb;   // Assign the value from the end to beginning
        *pb = temp;  // Assign the stored value to the end
        pa++;        // Move pa forward
        pb--;        // Move pb backward
    }
    
    // Reset pa to the start of the array for printing
    pa = a;

    // Print the reversed array
    cout << "Reversed: ";
    for (i = 0; i < n; i++) {
        cout << setw(3) << pa[i];
    }
    cout << endl;

    // Deallocate memory to prevent memory leaks
    delete[] a;

    return 0;
}