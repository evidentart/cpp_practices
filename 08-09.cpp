// Author:		   Ali Akcin
// Source file:	   VectorP.cpp
// Description:	   Program creates vector with logins made up of user names and 
//                 passwords.
// Compiler used:  Visual Studio 2019
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main( )
{
    vector<int> v;
    cout << "Enter a list of positive numbers.\n"
         << "Place a negative number at the end.\n";

    int next;
    cin >> next;
    while (next > 0)
    {
        v.push_back(next);
        cout << next << " added. ";
        cout << "v.size( ) = " << v.size( ) << endl;
        cin >> next;
    }

    cout << "You entered:\n";
    for (unsigned int i = 0; i < v.size( ); i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}
