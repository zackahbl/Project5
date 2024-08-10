/*
 Class: CMSC140 CRN 10152
 Program: Project #5
 Instructor: Hui-Mei Margaret Tseng
 Summary of Description: I am making a  program which checks if the values entered in a 3x3 grid of numbers by the user forms a Lo Shu Magic Square.
 Due Date: 8/09/24
 Integrity Pledge: I pledge that I have completed the programming assignment independently.
 I have not copied the code from a student or any source.
 I have not given my code to any student.
 Print your Name here: Zephaniah Ackah-Blay
 */


#include <iostream>
using namespace std;


// Prerequisite constants
const int ROWS = 3;
const int COLS = 3;
const int MIN = 1;
const int MAX = 9;

bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max);
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int calculatedSum);
bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int calculatedSum);
bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int calculatedSum);
void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size);

int main()
{
    
    // Persosnal info
    const int CRN_NUM = 10152;
    const string PROGRAMMER_NAME = "Zephaniah Ackah-Blay";
    const int PROJECT_NUM = 5;
    const string DUE_DATE = "8/09/2024";
    
    int magicArrayRow1[COLS], magicArrayRow2[COLS], magicArrayRow3[COLS];
    char tryAgain;

    do {
        fillArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);
        showArray(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS);

        if (isMagicSquare(magicArrayRow1, magicArrayRow2, magicArrayRow3, COLS))
            cout << "This is a Lo Shu magic square.\n";
        else
            cout << "This is not a Lo Shu magic square.\n" << endl << endl;

        // Ask user if they want to try again
        cout << "Do you want to try again?";
        cin >> tryAgain;
    } while (tryAgain == 'y' || tryAgain == 'Y');

    
    // Display details
    cout <<  endl << "Class: CMSC140 CRN " << CRN_NUM << endl << "Assigment: Project " << PROJECT_NUM << endl << "PROGRAMMER: " << PROGRAMMER_NAME << endl << "DUE DATE: " << DUE_DATE << endl << "Press any key to continue . . . ";
    cin.ignore();
    cin.get();
    
     

    return 0;
}

void fillArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter the number for row 0 and column " << i << " :";
        cin >> arrayRow1[i];
    }
    for (int i = 0; i < size; i++) {
        cout << "Enter the number for row 1 and column " << i << " :";
        cin >> arrayRow2[i];
    }
    for (int i = 0; i < size; i++) {
        cout << "Enter the number for row 2 and column " << i << " :";
        cin >> arrayRow3[i];
    }
}

// Displays the magic square grid
void showArray(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    for (int i = 0; i < size; i++)
        cout << arrayRow1[i] << " ";
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << arrayRow2[i] << " ";
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << arrayRow3[i] << " ";
    cout << endl;
}

// Checks if the given grid forms a Lo Shu Magic Square
bool isMagicSquare(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    int calculatedSum = 0;
    for (int i = 0; i < size; i++) {
        calculatedSum += arrayRow1[i];
    }

    return checkRange(arrayRow1, arrayRow2, arrayRow3, size, MIN, MAX) &&
           checkUnique(arrayRow1, arrayRow2, arrayRow3, size) &&
           checkRowSum(arrayRow1, arrayRow2, arrayRow3, size, calculatedSum) &&
           checkColSum(arrayRow1, arrayRow2, arrayRow3, size, calculatedSum) &&
           checkDiagSum(arrayRow1, arrayRow2, arrayRow3, size, calculatedSum);
}

bool checkRange(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        if (arrayRow1[i] < min || arrayRow1[i] > max ||
            arrayRow2[i] < min || arrayRow2[i] > max ||
            arrayRow3[i] < min || arrayRow3[i] > max)
            return false;
    }
    return true;
}


// Ensures that each number in the 3x3 grid is unique
bool checkUnique(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size) {
    bool used[MAX + 1] = {false};
    for (int i = 0; i < size; i++) {
        if (used[arrayRow1[i]] || used[arrayRow2[i]] || used[arrayRow3[i]])
            return false;
        used[arrayRow1[i]] = used[arrayRow2[i]] = used[arrayRow3[i]] = true;
    }
    return true;
}

bool checkRowSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int calculatedSum) {
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < size; i++) {
        sum1 += arrayRow1[i];
        sum2 += arrayRow2[i];
        sum3 += arrayRow3[i];
    }
    return (sum1 == calculatedSum) && (sum2 == calculatedSum) && (sum3 == calculatedSum);
}

bool checkColSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int calculatedSum) {
    for (int i = 0; i < size; i++) {
        if (arrayRow1[i] + arrayRow2[i] + arrayRow3[i] != calculatedSum)
            return false;
    }
    return true;
}

bool checkDiagSum(int arrayRow1[], int arrayRow2[], int arrayRow3[], int size, int calculatedSum) {
    return (arrayRow1[0] + arrayRow2[1] + arrayRow3[2] == calculatedSum) &&
           (arrayRow1[2] + arrayRow2[1] + arrayRow3[0] == calculatedSum);
}
