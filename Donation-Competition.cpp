// Final Project Junior Ezuma - Ngwu

// Header Files
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <iomanip>
using namespace std;

// Global variables and strings
const int SIZE = 10;
int arr1[SIZE];
int arr2[SIZE];
int input;
string company1_name, company2_name;

// Function fills array with user input data
void fillArrays(int arr1[], int arr2[], int SIZE, int input)
{
    for (int c = 0; c < SIZE; c++)
    {
        arr1[c] = input;

    // While loop used for input validation
        while (true)
        {
            if(!(cin >> input))
            {
                cout << "Invalid input. Please input a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        }
    }

    for (int c = 0; c < SIZE; c++)
    {
        arr2[c] = input;

        while (true)
        {
            if(!(cin >> input))
            {
                cout << "Invalid input. Please input a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
        }
    }
}

// Function prints the elements of the array
void printArrays(int arr1[], int arr2[], int SIZE, int format, ostream& out)
{
    for (int c = 0; c < SIZE; c++)
    {
        cout << arr1[c] << setw(2);
        if ((c + 1) % format == 0)
        {
            cout << endl << endl;
        }
    }

    for (int c = 0; c < SIZE; c++)
    {
        cout << arr2[c] << setw(2);
        if ((c + 1) % format == 0)
        {
            cout << endl << endl;
        }
    }
}

// Function calculates the total of all the values within both arrays
void Totals(int arr1[], int arr2[], int SIZE, int input, int sum1, int sum2)
{
    for (int c = 0; c < SIZE; c++)
    {
        arr1[c] += input;

        sum1 = arr1[c];

        cout << " Million" << endl;
    }

    for (int c = 0; c < SIZE; c++)
    {
        arr2[c] += input;

        sum2 = arr2[c];

        cout << " Million " << endl;
    }
}
// Function compares the total values of the first array with the second
void Comparison(int arr1[], int arr2[], int SIZE, int sum1, int sum2)
{
    while (sum1 > sum2)
    {
        cout << company1_name << " wins the Donation competition!!" << endl;

        if (sum2 > sum1)
        {
            cout << company2_name << " wins the donation competition!! " << endl;
        }

        else
        {
            cout << " Invalid Data! " << endl;

            break;
        }
        
    }
}

int main()
{

// Initialized values
    int format = 5;
    int sum1, sum2 = 0;

// File starts
    std::ofstream outputFile;
    outputFile.open("S&P_500.txt");

// File opening error
    if (!outputFile.is_open())
    {
        cout << "Error: Unable to open file!" << endl;
        return 1;
    }

// Calling fillArrays function to main
    fillArrays(arr1, arr2, SIZE, input);

// Name of first company
    cout << " Enter the name of the first company: " << endl;
    getline (cin >> ws, company1_name);

// Name of second company
    cout << "Enter the name of the second company: " << endl;
    getline (cin >> ws, company2_name);

// Written to terminal
    cout << "Enter the donations of " << company1_name << endl;
    cin >> input;

    cout << "Enter the donationd of " << company2_name << endl;

    cout << "Donations of " << company1_name << " and " << company2_name << endl;
    cout << "-----------------------------------" << endl;
    cout << "\n\n\n";
    printArrays(arr1, arr2, SIZE, format, cout); // Calling to function main

    cout << "Total of " << company1_name << " and " << company2_name << endl;
    Totals(arr1, arr2, SIZE, input, sum1, sum2); // Calling to function main
    
    cout << "Result of the competiton:" << endl;
    Comparison(arr1, arr2, SIZE, sum1, sum2); // Calling to function main

// Written to file
    outputFile << "Donations of " << company1_name << " and " << company2_name << endl;
    outputFile << "-----------------------------------" << endl;
    outputFile << "\n\n\n";
    printArrays(arr1, arr2, SIZE, format, cout);

    outputFile << "Total of " << company1_name << " and " << company2_name << endl;
    Totals(arr1, arr2, SIZE, input, sum1, sum2);
    
    outputFile << "Result of the competiton:" << endl;
    Comparison(arr1, arr2, SIZE, sum1, sum2);


}