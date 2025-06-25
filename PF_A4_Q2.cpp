//PF A4		QUESTION 2

/*
Q2: Two-Dimensional array Operations with File Handling
Write a program that takes a two-dimensional (2D) array from the user and provides a menu with the following operations:
1.	Grow the array by adding a row at the beginning (front side).
2.	Grow the array by adding a row at the end (last side).
3.	Grow the array by inserting a row at a user-defined position.
4.	Shrink the array by removing a row from the front.
5.	Shrink the array by removing a row from the end.
6.	Shrink the array by removing a row from a user-defined position.
🔹 Each operation should be implemented as a separate function (total: 6 functions).
🔸 Additionally, use file handling to:
•	Save the original 2D array before modification.
•	Save the modified 2D array after every operation.
*/

#include <iostream>
#include <fstream>
using namespace std;

const int max_rows = 100; 
const int max_columns = 100; 

// function enter array elemnents from user
void input_array (int array[max_rows][max_columns], int& rows, int& columns)  {
    cout << "Enter elements of array:" << endl;
    for (int r = 0; r < rows; r++) {        //r for rows
        for (int c = 0; c < columns; c++) {     // c for columns
            cout << "[Row = " << r + 1 << "][ Column = " << c + 1 << "] = ";
            cin >> array[r][c];
        }
    }
    cout << endl;
}

// function to display array elemnts
void display_array (int array[max_rows][max_columns], int rows, int columns) {
    cout << "Displaying Array" << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            cout << array[r][c] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// function to save array to file
void save_array_file (int array[max_rows][max_columns], int rows, int columns, const char* filename) {             //   filename
    ofstream File("array_q2.txt");
    if (File.is_open()) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                File << array[r][c] << "\t";
            }
            File << endl;
        }
        File.close();
    } else {
        cout << "File not Found" << endl;
    }
    cout << endl;
}

// 1.     Grow the array by adding a row at the beginning (front side) (Add row at start)
void add_row_start (int array[max_rows][max_columns], int& rows, int columns) {
    int new_row[max_columns];
    cout << "Enter values for new row:" << endl;
    for (int i = 0; i < columns; i++) {
        cin >> new_row[i];
    }

    for (int i = rows; i > 0; i--) {    // Shift rows down
        for (int j = 0; j < columns; j++) {
            array[i][j] = array[i - 1][j];
        }
    }

    for (int j = 0; j < columns; j++) {     // Copy new row to first row
        array[0][j] = new_row[j];
    }

    rows++;
    cout << "Row added at start" << endl;

    cout << endl;
}

//2.     Grow the array by adding a row at the end (last side) (Add row at end)
void add_row_end (int array[max_rows][max_columns], int& rows, int columns) {
    cout << "Enter values for new end row:" << endl;
    for (int j = 0; j < columns; j++) {
        cin >> array[rows][j];
    }
    rows++;
    cout << "Row added at end" << endl;

    cout << endl;
}

//3.     Grow the array by inserting a row at a user-defined position (Add row at specific position)
void row_user_position (int array[max_rows][max_columns], int& rows, int columns) {
    int position;
    cout << "Enter position to add row (0 to " << rows << "): ";
    cin >> position;

    if (position < 0 || position > rows) {
        cout << "Invalid position" << endl;
        return;
    }

    int new_row[max_columns];
    cout << "Enter values for new row:" << endl;
    for (int j = 0; j < columns; j++) {
        cin >> new_row[j];
    }

    for (int i = rows; i > position; i--) {     // Shift rows down
        for (int j = 0; j < columns; j++) {
            array[i][j] = array[i - 1][j];
        }
    }

    for (int j = 0; j < columns; j++) {     // Insert new row
        array[position][j] = new_row[j];
    }

    rows++;
    cout << "Row added at position: " << position << endl;

    cout << endl;
}

// 4.     Shrink the array by removing a row from the front (Remove row from front)
void shrink_row_start (int array[max_rows][max_columns], int& rows, int columns) {
    if (rows == 0) {
        cout << "Array is empty" << endl;
        return;
    }

    for (int i = 0; i < rows - 1; i++) {        // Shift rows up
        for (int j = 0; j < columns; j++) {
            array[i][j] = array[i + 1][j];
        }
    }

    rows--;
    cout << "Front row removed" << endl;

    cout << endl;
}

// 5.     Shrink the array by removing a row from the end (Remove row from end)
void shrink_row_end (int& rows) {
    if (rows == 0) {
        cout << "Array is empty" << endl;
        return;
    }

    rows--;
    cout << "End row removed" << endl;

    cout << endl;
}

// 6.     Shrink the array by removing a row from a user-defined position (Remove row at specific position
void shrink_user_position (int array[max_rows][max_columns], int& rows, int columns) {
    int position;
    cout << "Enter position to remove (0 to " << rows - 1 << "): ";
    cin >> position;

    if (position < 0 || position >= rows) {
        cout << "Invalid position" << endl;
        return;
    }

    for (int i = position; i < rows - 1; i++) {  // Shift rows up
        for (int j = 0; j < columns; j++) {
            array[i][j] = array[i + 1][j];
        }
    }

    rows--;
    cout << "Row at position " << position << " removed" << endl;

    cout << endl;
}

int main() {
    int array[max_rows][max_columns];

    int rows, columns;
    cout << "Enter number of Rows: ";
    cin >> rows;
    cout << "Enter number of Columns: ";
    cin >> columns;

    input_array (array, rows, columns);
    display_array (array, rows, columns);
    save_array_file (array, rows, columns, "array_q2.txt");

    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1.     Grow the array by adding a row at the beginning (front side) (Add row at start)" << endl;
        cout << "2.     Grow the array by adding a row at the end (last side) (Add row at end)" << endl;
        cout << "3.     Grow the array by inserting a row at a user-defined position (Add row at specific position)" << endl;
        cout << "4.     Shrink the array by removing a row from the front (Remove row from front)" << endl;
        cout << "5.     Shrink the array by removing a row from the end (Remove row from end)" << endl;
        cout << "6.     Shrink the array by removing a row from a user-defined position (Remove row at specific position" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        cout << endl;

        switch (choice) {
        case 1: 
            add_row_start (array, rows, columns); 
            break;
        case 2: 
            add_row_end (array, rows, columns); 
            break;
        case 3: 
            row_user_position (array, rows, columns); 
            break;
        case 4: 
            shrink_row_start (array, rows, columns); 
            break;
        case 5: 
            shrink_row_end (rows);
            break;
        case 6: 
            shrink_user_position (array, rows, columns);
            break;
        case 0:
            cout << "Exiting program" << endl; 
            break;
        default:
            cout << "Invalid choice" << endl;
        }

        // Show and save array after each function
        display_array (array, rows, columns);
        save_array_file (array, rows, columns, "array_q2.txt");

    } while (choice != 0);

    return 0;
}

