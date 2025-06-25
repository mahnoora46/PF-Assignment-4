// PF A4:	QUESTION 1

/*
Q1: One-Dimensional array Operations with File Handling
Write a program that takes a one-dimensional array from the user and provides a menu with the following operations:
1.	Grow the array from the front (beginning).
2.	Grow the array from the last (end).
3.	Grow the array at a user-defined position.
4.	Shrink (remove an element) from the front.
5.	Shrink from the last.
6.	Shrink from a user-defined position.
*/

#include <iostream>
#include <fstream>
using namespace std;

const int max_size = 100; // Maximum array size

// Function to input array elements
void input_array (int array[], int &size)  {
    cout << "Enter " << size << " elements: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
    cout << endl;
}

// Function to display the array
void display_array (int array[], int size)  {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Function to write array to file
void save_array_file (int array[], int size)   {
    ofstream File("array_q1.txt");
    if (File.is_open()) {
        for (int i = 0; i < size; i++) {
            File << array[i] << " ";
        }
        File.close();
    } else {
        cout << "File not found." << endl;
    }
    cout << endl;
}

//1.	Grow the array from the front (beginning)
void grow_array_start (int array[], int &size) {
    int value;
    cout << "Enter value to insert at front: ";
    cin >> value;

    // Shift all elements to right
    for (int i = size; i > 0; i--) {
        array[i] = array[i - 1];
    }

    array[0] = value;
    size++;
    cout << "Element added at front." << endl;

    cout << endl;
}

// 2.	Grow the array from the last (end)
void grow_array_end (int array[], int &size)  {
    int value;
    cout << "Enter value to insert at end: ";
    cin >> value;

    array[size] = value;
    size++;
    cout << "Element added at end." << endl;

    cout << endl;
}

//3.	Grow the array at a user-defined position
void grow_user_position (int array[], int &size) {
    int value, position;
    cout << "Enter value to insert: ";
    cin >> value;
    cout << "Enter position (0 to " << size << "): ";
    cin >> position;

    if (position < 0 || position > size) {
        cout << "Invalid position" << endl;
        return;
    }
    
    for (int i = size; i > position; i--) {     // Shift elements to the right
        array[i] = array[i - 1];
    }

    array[position] = value;
    size++;
    cout << "Element inserted at position " << position << endl;

    cout << endl;
}

//4.	Shrink (remove an element) from the front
void shrink_start (int array[], int &size) {
    if (size == 0) {
        cout << "array is empty" << endl;
        return;
    }

    for (int i = 0; i < size - 1; i++) {        // Shift elements to left
        array[i] = array[i + 1];
    }

    size--;
    cout << "Element removed from front." << endl;

    cout << endl;
}

//5.	Shrink from the end
void shrink_end (int array[], int &size) {
    if (size == 0) {
        cout << "array is empty." << endl;
        return;
    }

    size--;
    cout << "Element removed from end." << endl;

    cout << endl;
}

//6.	Shrink from a user-defined position
void shrink_user_position (int array[], int &size) {
    if (size == 0) {
        cout << "array is empty." << endl;
        return;
    }

    int position;
    cout << "Enter position to remove (0 to " << size - 1 << "): ";
    cin >> position;

    if (position < 0 || position >= size) {
        cout << "Invalid position." << endl;
        return;
    }

    for (int i = position; i < size - 1; i++) {
        array[i] = array[i + 1];
    }

    size--;
    cout << "Element removed from position: " << position << endl;

    cout << endl;
}


int main()
{
    int array[max_size]; // array
    int size; // current size of array

    cout << "Enter number of elements: ";
    cin >> size;

    input_array (array, size);
    display_array (array, size);
    save_array_file (array, size); 


    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1.	Grow the array from the front (beginning)" << endl;
        cout << "2.	Grow the array from the last (end)" << endl;
        cout << "3.	Grow the array at a user-defined position" << endl;
        cout << "4.	Shrink (remove an element) from the front" << endl;
        cout << "5.	Shrink from the last" << endl;
        cout << "6.	Shrink from a user-defined position" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        cout << endl;
        

        switch (choice) {
        case 1: 
            grow_array_start (array, size);
            break;

        case 2: 
            grow_array_end (array, size);
            break;

        case 3: 
            grow_user_position (array, size);
            break;

        case 4: 
            shrink_start (array, size);
            break;

        case 5: 
            shrink_end (array, size);
            break;

        case 6: 
            shrink_user_position (array, size);
            break;

        case 0:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

        // Show updated array and save to file after each operation
        display_array (array, size);
        save_array_file (array, size);


    } while (choice != 0);



	return 0;
}