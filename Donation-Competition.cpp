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
int arr1[10];
int arr2[10];
int array[10];

// Function fills array with user input data
void fillArrays(int array[], int SIZE)
{
    int input;

    for (int c = 0; c < SIZE; c++)
    {
        cout << "Enter donation " << (c + 1) << ": ";

    // While loop used for input validation
        while (!(cin >> input))
        {
                cout << "Invalid input. Please input a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        array[c] = input;
    }
}

// Function prints and formats the elements of the array
void printArrays(int array[], int SIZE, int format, ostream& out)
{

// Code creates a new line every 5 values printed
    for (int c = 0; c < SIZE; c++)
    {
        cout << (array[c]) << setw(2) << " Million";
        if ((c + 1) % format == 0)
        {
            cout << " " << endl;
        }
        else
        {
            cout << ", ";
        }
    }
}

// string function to pritn the elements to a text file
string Donation(int array[], int SIZE, int format, ostream& out)
{;
    string Donations;

// Same loop logic of the void function
    for (int c = 0; c < SIZE; c++)
    {
        Donations +=  to_string((array[c])) + "  Million, " ;
        if ((c + 1) % format == 0)
        {
            Donations += '\n';
        }
    }  

    return Donations;  // string variable
}


// Function calculates the total of all the values within an array
int Total(int array[], int SIZE)
{
    int total = 0;

    for (int c = 0; c < SIZE; c++)
    {
        total += array[c]; // adds the elements together and assigns it to total
    }

    return total; // Called to main
}

// Function compares the total values of the first array with the second
void Comparison(int arr1[], int arr2[], int SIZE, string company1_name, string company2_name)
{
// Declarative variables
   int total1 = Total(arr1, SIZE);
   int total2 = Total(arr2, SIZE);

   if (total1 > total2)
   {
        cout << company1_name << " wins the donation competition!!" << endl;
   }
    else if (total2 > total1)
   {
        cout << company2_name << " wins the donation competition!!" << endl;
   }
   else
   {
        cout << "It's a tie!" << endl;
   }
}

// A string function that returns the result of the two array totals to an output file
string ComparisonOut(int arr1[], int arr2[], int SIZE, string company1_name, string company2_name)
{
   int total1 = Total(arr1, SIZE);
   int total2 = Total(arr2, SIZE);

   string Results;

   if (total1 > total2)
   {
        Results = company1_name + " wins the donation competition!!" + '\n';
   }
    else if (total2 > total1)
   {
        Results = company2_name + " wins the donation competition!!" + '\n';
   }
   else
   {
        Results = "It's a tie!" + '\n';
   }

   return Results; // Called to main

}

int main()
{

// Initialized values
    int arr1[SIZE], arr2[SIZE];
    int format = 5;
    string company1_name, company2_name;

// File starts
    std::ofstream outputFile;
    outputFile.open("S&P.txt");

// File openeing validation
    if (!outputFile.is_open())
    {
        cerr << "Unable to open file!" << endl;
        return 1;
    }

//  Name of first company
    cout << " Enter the name of the first company: ";
    getline (cin >> ws, company1_name);

// Name of second company
    cout << "Enter the name of the second company: ";
    getline (cin >> ws, company2_name);

// Prompts user to input the values of the arrays
    cout << "Enter donations for " << company1_name << ":" << endl;
    fillArrays(arr1, SIZE);
    cout << "Enter donations for " << company2_name << ":" << endl;
    fillArrays(arr2, SIZE);

// Prints the assigned user input values of the array to terminal
    cout << "Donations of " << company1_name << ":" << endl;
    printArrays(arr1, SIZE, format, cout);
    cout << "Donations of " << company2_name << ":" << endl;
    printArrays(arr2, SIZE, format, cout);

// Prints the total amount of the values of each array to terminal
    cout << "Total donations of " << company1_name << ": $" << Total(arr1, SIZE) << " Million " << endl;
    cout << "Total donations of " << company2_name << ": $" << Total(arr2, SIZE) << " Million " << endl;

// Declares the array with the highest total value
    cout << "Result of the competition:" << endl;
    Comparison(arr1, arr2, SIZE, company1_name, company2_name);

// Prints the array elements to the file
    outputFile << "Donations of " << company1_name << ": $" << Donation(arr1, SIZE, format, outputFile) << endl;
    outputFile << "Donations of " << company2_name << ": $" << Donation(arr2, SIZE, format, outputFile) << endl;

// Prints the arrays total values to the file
    outputFile << "Total donations of " << company1_name << ": $" << Total(arr1, SIZE) << " Million " << endl;
    outputFile << "Total donations of " << company2_name << ": $" << Total(arr2, SIZE) << " Million " << endl; 

// Declares the aray with the highest total value to the file
    outputFile << "Result of the competition: " << ComparisonOut(arr1, arr2, SIZE, company1_name, company2_name) << endl;
    
    outputFile.close(); // File closes

    return 0; // Program endsDonationd
    
}



