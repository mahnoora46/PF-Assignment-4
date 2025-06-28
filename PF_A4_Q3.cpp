// PF A4		QUESTION 3

/*
Q3: Jagged 2D array Operations with File Handling
Write a program that takes a jagged 2D array (i.e., a 2D array where each row can have a different number of columns) from the user and provides a menu with the following operations:
1.	Grow the jagged array by adding a new row at the beginning (front side).
2.	Grow the jagged array by adding a new row at the end (last side).
3.	Grow the jagged array by inserting a new row at a user-defined position.
4.	Shrink the jagged array by removing a row from the front.
5.	Shrink the jagged array by removing a row from the end.
6.	Shrink the jagged array by removing a row from a user-defined position.
🔹 Each operation should be implemented as a separate function (total: 6 functions).
🔸 In addition, implement file handling to:
•	Write the original jagged array to a file before performing any operations.
•	Save the updated jagged array after each operation to track changes.
*/


#include <iostream>
#include <fstream>
using namespace std;

// Function to take a single row input from user
int* input_row (int& column_number) {
    cout << "Enter number of columns for this row: ";
    cin >> column_number;

    cout << endl;

    int* row = new int[column_number];      //1d array for this row

    cout << "Enter " << column_number << " values: " << endl;
    for (int i = 0; i < column_number; i++) {
        cin >> row[i];
    }
    cout << endl;

    return row;     //returns address of row
}

// Function to display the current jagged array
void display_jagged_array (int** array, int* column_sizes, int rows) {
    cout << "Current Jagged Array: " << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ": \t";
        for (int j = 0; j < column_sizes[i]; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to save jagged array to file
void save_jagged_array_file (const char* filename, int** array, int* column_sizes, int rows) {
    ofstream File("array_q3.txt");
    if (File.is_open()) {
        for (int i = 0; i < rows; i++) {
            File << column_sizes[i] << " ";
            for (int j = 0; j < column_sizes[i]; j++) {
                File << array[i][j] << " ";
            }
            File << endl;
        }
        File.close();
    } else {
        cout << "File not found" << endl;
    }
    cout << endl;
}

// 1. Add row at the start
void add_row_start (int**& array, int*& column_sizes, int& rows) {
    int columns;
    int* new_column = input_row (columns);

    int** temp_array = new int* [rows + 1];
    int* temp_columns = new int [rows + 1];

    // New row at front
    temp_array[0] = new_column;
    temp_columns[0] = columns;

    // Copy old rows after new row
    for (int i = 0; i < rows; i++) {
        temp_array[i + 1] = array[i];
        temp_columns[i + 1] = column_sizes[i];
    }

    // Free old memory
    delete[] array;
    delete[] column_sizes;

    // Update references
    array = temp_array;
    column_sizes = temp_columns;
    rows++;
}

// 2. Add row at  end
void add_row_end (int**& array, int*& column_sizes, int& rows) {
    int columns;
    int* new_column = input_row (columns);

    int** temp_array = new int* [rows + 1];
    int* temp_columns = new int [rows + 1];

    // Copy old rows
    for (int i = 0; i < rows; i++) {
        temp_array[i] = array[i];
        temp_columns[i] = column_sizes[i];
    }

    // Add new row at end
    temp_array[rows] = new_column;
    temp_columns[rows] = columns;

    delete[] array;
    delete[] column_sizes;

    array = temp_array;
    column_sizes = temp_columns;
    rows++;
}

// 3. Add row at a specific position
void add_row_user_position (int**& array, int*& column_sizes, int& rows, int position) {
    if (position < 0 || position > rows) {
        cout << "Invalid position." << endl;
        return;
    }

    int columns;
    int* new_column = input_row (columns);

    int** temp_array = new int* [rows + 1];
    int* temp_columns = new int [rows + 1];

    for (int i = 0; i < position; i++) {
        temp_array[i] = array[i];
        temp_columns[i] = column_sizes[i];
    }

    temp_array [position] = new_column;
    temp_columns [position] = columns;

    for (int i = position; i < rows; i++) {
        temp_array[i + 1] = array[i];
        temp_columns[i + 1] = column_sizes[i];
    }

    delete[] array;
    delete[] column_sizes;

    array = temp_array;
    column_sizes = temp_columns;
    rows++;
}

// 4. Remove row from front
void remove_row_start (int**& array, int*& column_sizes, int& rows) {
    if (rows == 0) {
        return;
    }
    delete[] array[0]; // delete first row

    for (int i = 0; i < rows - 1; i++) {
        array[i] = array[i + 1];
        column_sizes[i] = column_sizes[i + 1];
    }

    rows--;
}

// 5. Remove row from end
void remove_row_end (int**& array, int*& column_sizes, int& rows) {
    if (rows == 0) {
        return;
    }
    delete[] array[rows - 1];
    rows--;
}

// 6. Remove row at specific position
void remove_row_user_position (int**& array, int*& column_sizes, int& rows, int position) {
    if (position < 0 || position >= rows) {
        cout << "Invalid position." << endl;
        return;
    }

    delete[] array[position];

    for (int i = position; i < rows - 1; i++) {
        array[i] = array[i + 1];
        column_sizes[i] = column_sizes[i + 1];
    }

    rows--;
}


int main() {
    int rows;
    cout << "Enter number of initial rows: ";
    cin >> rows;

    int** jagged = new int* [rows];
    int* column_sizes = new int[rows];

    cout << endl;

    // Input initial jagged array
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << "\t" ;
        jagged[i] = input_row(column_sizes[i]);
    }

    // Save original array
    save_jagged_array_file("array_q3.txt", jagged, column_sizes, rows);
    display_jagged_array(jagged, column_sizes, rows);

    int position;

    int choice;

    do {
        cout << endl;
        cout << "Menu: " << endl;
        cout << "1.	    Grow the jagged array by adding a new row at the beginning (front side)." << endl;
        cout << "2.	    Grow the jagged array by adding a new row at the end (last side)" << endl;
        cout << "3.	    Grow the jagged array by inserting a new row at a user-defined position." << endl;
        cout << "4.	    Shrink the jagged array by removing a row from the front" << endl;
        cout << "5.	    Shrink the jagged array by removing a row from the end" << endl;
        cout << "6.	    Shrink the jagged array by removing a row from a user-defined position." << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        cout << endl;

        switch (choice) {
        case 1:
            add_row_start(jagged, column_sizes, rows);
            break;
        case 2:
            add_row_end(jagged, column_sizes, rows);
            break;
        case 3:
            cout << "Enter position: ";
            cin >> position;
            add_row_user_position(jagged, column_sizes, rows, position);
            break;
        case 4:
            remove_row_start(jagged, column_sizes, rows);
            break;
        case 5:
            remove_row_end(jagged, column_sizes, rows);
            break;
        case 6:
            cout << "Enter position: ";
            cin >> position;
            cout << endl;
            remove_row_user_position(jagged, column_sizes, rows, position);
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }

        // Save after every operation
        save_jagged_array_file("updated_jagged.txt", jagged, column_sizes, rows);
        display_jagged_array(jagged, column_sizes, rows);

    } while (choice != 0);

    // Cleanup memory
    for (int i = 0; i < rows; i++) {
        delete[] jagged[i];
    }
    delete[] jagged;
    delete[] column_sizes;

    return 0;
}
