// Author:			Ali Akcin
// Source file:		Airplane.cpp
// Description:		Program assigns passenger seats in an airplane. User enters row
//                  and seat, and program checks if the seat is available, and marks the seat
//                  with "X". 
// IDE used:	    Visual Studio C++ 2019

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#include "array.h"

void displayPlane(char p[ROW][COL])

{

	cout <<   "   Chesapeake Airlines" << endl;

	for (int i = 0; i < 9; i++)

	{
		cout << i + 1 << " ";

		for (int j = 0; j < 4; j++)

		{
			cout << p[i][j] << " ";
		}

		cout << endl;

	}
}

void getData(int& a, char& c)

{
	
	cout << "Enter row (-1 to stop) ";

	cin >> a;

	if (a == -1)return;

	while (a < 1 || a>9)

	{

		cout << "Please enter a valid row";

		cout << "Enter row (-1 to stop) ";

		cin >> a;

		if (a == -1)return;

	}

	cout << "Enter seat (A, B, C, D)";

	cin >> c;

	while ((c - 65) < 0 || (c - 65) > 3)

	{

		cout << "Please enter a valid seat " << endl;
		cout << "Enter seat (A, B, C, D)";
		cin >> c;

	}
	return;

}

int main()

{

	int row;
	char seat;

	while (1)

	{

		cout << endl;

		displayPlane(layout);

		getData(row, seat);

		if (row == -1)

		{

			int total_seats = 0;

			for (int i = 0; i < 3; i++)total_seats += classCtr[i];

			double total_sales = 0;

			for (int i = 0; i < 3; i++)total_sales += classCtr[i] * fare[i];

			cout << endl;
			cout << " Total seats = " << total_seats << endl << endl;
			cout << fixed << setprecision(2) << " Percent Occupied = " << double(100 * total_seats) / 36 << endl << endl;
			cout << "                                 Sales Report" << endl << endl;;
			cout << "                    Ticket Price               Total Sales" << endl << endl;
			cout << fixed << setprecision(2) << " First Class        " << fare[0] << "                     " << classCtr[0] << " " << fare[0] * classCtr[0] << endl << endl;
			cout << fixed << setprecision(2) << " Business Class     " << fare[1] << "                     " << classCtr[1] << " " << fare[1] * classCtr[1] << endl << endl;
			cout << fixed << setprecision(2) << " Coach              " << fare[2] << "                     " << classCtr[2] << " " << fare[2] * classCtr[2] << endl << endl;
			cout << endl;

			cout << fixed << setprecision(2) << " Total Sales = " << total_sales << endl << endl;

			break;

		}

		else if (layout[row - 1][seat - 65] == 'X')

		{

			cout << "The seat you selected is already occupied" << endl;

			continue;
		}

		else

		{
			layout[row - 1][seat - 65] = 'X';

			if (row == 1)classCtr[0]++;

			else if (row <= 4)classCtr[1]++;

			else classCtr[2]++;

		}

	}

	return 0;
}