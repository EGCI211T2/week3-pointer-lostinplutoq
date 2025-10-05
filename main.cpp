#include <iostream>
#include <iomanip>
#include <cstdlib> //required for atoi()

using namespace std;

int main(int argc, char*argv[]) {
    int n;
    int *pa, *pb, i, temp;

    //determine the size of array
    n = argc - 1

    // Get dynamic size
    cout << "Enter the size of the array: ";
    cin >> n;

    // Check for size
    if (n <= 0) {
        cout << "Usage: " << argv[0] << " <integer1> <integer2> ... <integerN>" << endl;
        return 1;
    }

    // Allocate memory for the array
    int *a = new int[n];
    pa = a; // pa points to the first element of new array

    // Convert command-line arguments to integer and store in array
    for (i = 0; i < n; i++) {
        *pa = atoi(argv[i+1]);
        pa++;
    }

    //Reset pa to the start of the array
    pa = a;
    
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