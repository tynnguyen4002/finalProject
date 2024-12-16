//************************************************************************
// Author: Phuc Nguyen
// Language: C++
// Assignment: Final Project
// Course: Programming Fundamental I
// Institution: Northwest Vista CollegeVistaCollege
// Description: Program prompt user to choose a selection. The selection
// choice that they make will determine the functionality the program will
// execute.
//************************************************************************
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

// define structures
struct Contacts
{
    string firstName;
    string lastName;
    string phoneNumber;
};

// define enumeration with 10 buildings on campus
enum nameBuildings { CCC, DWWC, JH, MLH, PH, CESC, HH, LOH, PCA, RLC };

// function prototype
// function to display the header
void displayHeader();
// function to prompt the users enter first and last name
void getUserNames(string&, string&);
// function to convert the numerical grade to a letter grade
void convertGrade(double);
// function to create a right triangle
void rightTriangle(int);
// function to calculate the weekly pay and return as a double
// calculated pay
void calculatedPay(int, double);
// function to display the names of buildings
void displayBuildings(nameBuildings buildings);
// function to get users' grades
void getGrades(double[], int);
// function to display each of the users' grades
void displayGrades(double[], int);
// function to return the average of grades as double
double averageGrades(double[], int);
// function to print the contact list
void printContacts(Contacts[]);


// define namespace
namespace bankAccount
{
    // declare local variables
    double balance;
    double interestRate;
    int years;
    
    // function prototype
    // function to calculate interest earned and display saving balance
    void displayInterest();
}

// global variable
const int ARRAY_SIZE = 3;

int main()
{
    // declare local variables
    string firstName, lastName;
    int choice=0;
    int number=0;
    int x, y;
    int gpa=0;
    int hours=0;
    double grades[5];
    int numGrades = sizeof(grades) / sizeof(grades[0]);
    double averageGrade=0;
    double rate;
    
    // declare and populate the array
    Contacts arrayContacts[ARRAY_SIZE] =
    {
        {"Scott", "Raymond", "(210)563-1234"},
        {"Fred", "Flinstone", "(210)622-5678"},
        {"Sally", "Smith", "(210)555-9753"}
    };
    
    // initialize variables from bankAccount namespace
    bankAccount::interestRate =0;
    bankAccount::balance=0;
    bankAccount::years=0;
    
    // declare a variable to an enumeration value and initialize it to the
    // building values
    nameBuildings buildings = MLH;
    
    // call function to display a header
    displayHeader();
    
    // call function to get users' first and last name
    getUserNames(firstName, lastName);
  
    // display welcome message
    cout << "Welcome to my Course Project " << firstName << "!\n";
    cout << "**************************************" << endl;
    
    // loop until users enter 0 to exit
    do
    {
        // display the outline of the options table
        cout << "|----------------------------------------------------|\n";
        // display options
        cout << "| Enter 1 to Calculate Square Root                   |\n"
             << "| Enter 2 to Enter x to the y Power                  |\n"
             << "| Enter 3 to Convert Numerical GPA to a Letter Grade |\n"
             << "| Enter 4 to Create a Right Triangle                 |\n"
             << "| Enter 5 to Calculate Weekly Pay                    |\n"
             << "| Enter 6 to Create Interest Earned                  |\n"
             << "| Enter 7 to Display the Classes Building            |\n"
             << "| Enter 8 to Calculate Grades                        |\n"
             << "| Enter 9 to Print Contacts                          |\n"
             << "| Enter 0 to Exit                                    |\n";
        cout << "|----------------------------------------------------|\n";
        cout << "Enter Your Request: ";
        cin  >> choice;
        
        // display user's request
        switch (choice)
        {
            case 1: // calculate the square root
                cout << "Enter a number to calculate the Square Root: ";
                cin  >> number;
                cout << "The Square Root of " << number << " is "
                << sqrt(number) << endl;
                break;
            case 2: // calculate power
                cout << "Enter a number x to raise to the y power" << endl;
                cout << "Enter x: ";
                cin  >> x;
                cout << "Enter y: ";
                cin  >> y;
                cout << x << " to the " << y << " power is " << pow(x, y);
                cout << endl;
                break;
            case 3: // convert numerical grade to letter grade
                cout << "Enter your numerical Grade (GPA): ";
                cin >> gpa;
                convertGrade(gpa); // function call
                break;
            case 4: // create a triangle
                cout << "Enter the size of the triangle: ";
                cin >> number;
                rightTriangle(number); // function call
                break;
            case 5: // calculate weekly pay
                cout << "Enter Hours: ";
                cin >> hours;
                cout << "Enter Pay Rate: ";
                cin >> rate;
                calculatedPay(hours, rate); // function call
                break;
            case 6: // calculate the interested earned and display
                cout << "Initial Balance: ";
                cin >> bankAccount::balance;
                cout << "Enter yearly Interest Rate: ";
                cin >> bankAccount::interestRate;
                cout << "Enter number of years: ";
                cin >> bankAccount::years;
                // call function from namespace bankAccount to calculate interest
                // and display the balance
                bankAccount::displayInterest();
                break;
            case 7: // display class building
                cout << "The class is located in ";
                // call function to display the building that class located in
                displayBuildings(buildings);
                cout << endl;
                break;
            case 8:
                // call function to get users' grades
                getGrades(grades, numGrades);
                
                // call function to display each of the grades
                displayGrades(grades, numGrades);
            
                // call function to assign the average grades
                averageGrade = averageGrades(grades, numGrades);
                // display the average
                cout << "The grade average is " << averageGrade << endl;
                break;
            case 9: // print the list of contacts
                // call function to display the list
                printContacts(arrayContacts);
                break;
            case 0: // exit the loop
                cout << "Thank you for using my project!" << endl;
                break;
            default:// option is not 0,1,2,3,4,5,6,7
                cout << "This is not a valid option." << endl;
                break;
        }// end of switch
    } while (choice !=0); // exit loop when users enter 0
    return 0;
}


// function definitions
// function to display header
void displayHeader()
{
    cout << "**************************************" << endl;
    cout << "*    Programming 1 Course Project    *" << endl;
    cout << "**************************************" << endl;
}

// function to get users' first and last name
void getUserNames(string &firstName, string &lastName)
{
    cout << "Please enter your First Name: ";
    cin >> firstName;
    cout << "Please enter your Last Name: ";
    cin >> lastName;
}
// function to convert the numerical grade to letter grade
void convertGrade(double gpa)
{
    if (gpa <= 0.7) // gpa <= 0.7 executes F
        cout << "Letter Grade is F\n";
    else if (gpa <= 1.7) // 0.7 < gpa <= 1.7 executes D
        cout << "Letter Grade is D\n";
    else if (gpa <= 2.7) // 1.7 < gpa <= 2.7 executes C
        cout << "Letter Grade is C\n";
    else if (gpa <= 3.7) // 2.7 < gpa <= 3.7 executes B
        cout << "Letter Grade is B\n";
    else if (gpa <= 4.0) // 3.7 < gpa <= 4.0 executes A
        cout << "Letter Grade is A\n";
}

// function to create a right triangle
void rightTriangle(int number)
{
    // loop creating row until row = number
    for (int row = 1; row <= number; row++)
    {
        // loop creating column until column = row
        for (int column = 1; column <= row; column++)
            cout << "*";
        cout << endl;
    }
}

// function to calculate weekly pay by take 2 parameters: hours and rate
// and return it as a double
void calculatedPay(int hours, double rate)
{
    // declare local variables
    double pay = hours*rate;
    
    // using if to calculate overtime hours as at 1.5 times hourly
    // rate for each hours over 40 hours
    if (hours > 40)
    {
        pay = 40*rate + (hours - 40)*rate*1.5;
    }
    // set output to 2 decimal places
    cout << showpoint << fixed << setprecision(2);
    cout << "Weekly Pay is $" << pay << endl;
}

// function calculate interest earned and display the saving
// account for the next 5 years
void bankAccount::displayInterest()
{
    // using for loop to calculate the interest earned and
    // display the saving balance for the next 5 years
    // formatting ouput to 2 decimal places
    cout << showpoint << fixed << setprecision(2);
    for (int i = 1; i<=years; i++)
        {
            balance += balance*interestRate;
            cout << "Year " << i << " : $" << balance << endl;
        }
}

// function that takes one of the enumeration nameBuildingss as a parameter
// and display the names of building
void displayBuildings(nameBuildings buildings)
{
    // using switch to print the full name of the buildings
    switch (buildings)
    {
        case CCC:
            cout << "Cypress Cultural Center";
            break;
        case DWWC:
            cout << "Desert Willow Welcome Center";
            break;
        case JH:
            cout << "Juniper Hall";
            break;
        case MLH:
            cout << "Mountain Laurel Hall";
            break;
        case PH:
            cout << "Pecan Hall";
            break;
        case CESC:
            cout << "Cedar Elm STEM Center";
            break;
        case HH:
            cout << "Huisache Hall";
            break;
        case LOH:
            cout << "Live Oak Hall";
            break;
        case PCA:
            cout << "Palmetto Center of the Arts";
            break;
        case RLC:
            cout << "Redbud Learning Center";
            break;
        default:
            cout << "This is not valid.\n";
            break;
    }
}

// function to get users' grades
void getGrades(double grades[], int size)
{
    // using loop to populate the array
    // initialize LCV equal to 1 to match with the prompt
    for (int i = 1; i <= size; i++)
    {
        cout << "Enter Grade " << i << ": ";
        cin >> grades[i];
    }
    cout << endl;
}

// function to display each of the users' grades
void displayGrades(double grades[], int size)
{
    // formatting the ouput
    cout << fixed << showpoint << setprecision(2);
    
    // using loop to display the array
    for (int i = 1; i<=size; i++)
    {
        // cast integer entered to double
        cout << "Grade " << i << ": " << static_cast<double>(grades[i])
             << endl;
    }
}

// function to calculate the average grades
double averageGrades(double grades[], int size)
{
    // declare local variable
    int totalGrade = 0;
    
    // using for loop to get the total grades
    for (int i=1; i<=size; i++)
        totalGrade += grades[i];
    
    // calculate and return the average
    return totalGrade/5.0;
}

// function to display the list of contacts
void printContacts(Contacts array[])
{
    // using loop to display through the array
    cout << "Contact List: " << endl;
    
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << "Name: " << array[i].firstName << " "
             << array[i].lastName << endl
             << "Phone: " << array[i].phoneNumber << endl;
        cout << endl;
    }
}
