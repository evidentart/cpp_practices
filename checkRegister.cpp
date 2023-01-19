// Author:		   Ali Akcin
// Source file:	   checkRegister.cpp
// Description:	   Program checks register with Data Files, and reads the balance
//                 with transactions from the provided functions. Program displays
//                 Credits, Debits, Service charges, and number of transactions.
// Compiler used:  Visual Studio 2019

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

struct record {

    int code;
    double amt;
};

// Function Prototypes
void display_Title();
double getBegbalance(istream& inFile);
void displaybalance(double);
record getData(istream& inFile);
double processCheck(double, double);
double processDeposit(double, double);
double processATM(double, double);
double processSvcCHARGE(double);

//Globalance Constants
const double CHARGE = 10, 
             ATMFEE = 2;
int numTrans = 0;

int main()

{
    //Variable Declarations
    int transcode;
    double balance, transAmt;
    record r;
    ifstream inFile;

    inFile.open("c:\\CSIT\\checkIn.dat");

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    display_Title();
    balance = getBegbalance(inFile);
    displaybalance(balance);
    r = getData(inFile);
    transcode = r.code;
    transAmt = r.amt;

    while (transcode != 0)
    {
        switch (transcode)
        {
            case 1: balance = processCheck(balance, transAmt); break;
            case 2: balance = processDeposit(balance, transAmt); break;
            case 3: balance = processATM(balance, transAmt); break;
        }

        displaybalance(balance);
        if (balance < 0)
            balance = processSvcCHARGE(balance);
        r = getData(inFile);

        transcode = r.code;
        transAmt = r.amt;

        numTrans++;
    
    }

    ofstream outFile;
    outFile.open("c:\\CSIT\\check_Out.dat");

    cout << endl;
    cout << "\nFinal balance          : $"<< balance << endl;
    cout << "Number of transactions : " << numTrans << endl;;

    cout << endl;
    inFile.close();
    return 0;
}

void display_Title()
{
    cout << "\n ----Check Register----\n";
}

double getBegbalance(istream& inFile)
{
    double balance;
    inFile >> balance;
    return balance;
}

void displaybalance(double y)
{
    cout << "\nBalance        $" << setw(10) << y;
}

record getData(istream& inFile)
{
    int code;
    double amt = 0;
    inFile >> code;

    if (code > 0)
    {
        inFile >> amt;
    }

    record r;
    r.amt = amt;
    r.code = code;
    return r;
}

double processCheck(double VAL, double amt)
{
   
    cout << "\nCheck          $"<<setw(10)<<amt;
    return (VAL - amt);
}

double processDeposit(double VAL, double amt)
{
    cout << endl;
    cout <<"\nDeposit        $" << setw(10) << amt;
    return (VAL + amt);
}

double processATM(double VAL, double amt)
{
    cout << endl;
    cout << "\nATM            $" << setw(10) << amt;
    VAL = VAL - amt;
    displaybalance(VAL);
    VAL = VAL - ATMFEE;
    cout << endl;
    cout <<"\nATM Fee        $"<< setw(10)<<ATMFEE;
    return (VAL);
}

double processSvcCHARGE(double VAL)
{
    cout << endl;
    cout <<"\nService charge $  "<<setw(8)  <<    CHARGE;
    VAL = VAL - CHARGE;
    displaybalance(VAL);
    return (VAL);
}