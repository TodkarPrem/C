#include <iostream>
using namespace std;

int main()
{
	int i, j, k, rows;

	cout << "Enter number of rows: ";
	cin >> rows;

	for (i = 1; i <= rows; i++) {
		if (i % 2)
			k = -1;
		else
			k = 0;
	
		for (j = 1; j<= i; j++) 
			cout << (k = 2 + k) << " ";
		cout << endl;
	}
	return 0;
}
