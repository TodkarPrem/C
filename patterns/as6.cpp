#include <iostream>
using namespace std;

int main()
{
	int i, j, rows;

prev:	cout << "Enter number of rows (odd): ";
	cin >> rows;

	if (rows % 2 == 0)
		goto prev;

	for (i = 0; i < rows; i++) {
		for (j = 0; j <= i; j++)
			if (j % 2)
				cout << "0 ";
			else
				cout << "1 ";
		cout << endl;
	}
	return 0;
}
