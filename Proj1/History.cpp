#include "History.h"
#include "globals.h"
#include<iostream>
using namespace std;


History::History(int nRows, int nCols) {
	m_rows = nRows;
	m_cols = nCols;
	for (int i = 0; i < MAXROWS; i++) {
		for (int k = 0; k < MAXCOLS; k++) {
			recordGrid[i][k] = 0;
		}
	}
}

bool History::record(int r, int c) {
	if (isInBounds(r, c) == false) {
	return false;
	}
	r--;
	c--;
	for (int i = 0; i < MAXROWS; i++) {
		for (int k = 0; k < MAXCOLS; k++) {
			if (i == r && k == c) {
				recordGrid[i][k]++;
			}
		}
	}
	return true;
}
void History::display() const {
	clearScreen();
	for (int i = 0; i < m_rows; i++) {
		for (int k = 0; k < m_cols; k++) {
			if (recordGrid[i][k] == 0)
			{
				cout << '.';
			}
			if (recordGrid[i][k] > 0) {
				int a = recordGrid[i][k] + 64;

				char character;

				if (a >= 90) {
					character = 'Z';
				}
				else {
					character = a;
				}

				cout << character;
			}

		}

		cout<<endl;
	}

	cout << endl;


}

bool History::isInBounds(int r, int c) const
{
	return (r >= 1 && r <= m_rows && c >= 1 && c <= m_cols);
}
