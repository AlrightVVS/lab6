#include <iostream>
using namespace std;
int main() {
	int a[] = { 1, 91, 36, 210, 1550, 5, 9, 17, 75, 700 };
	cout << "Array before sorting: ";
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n\nArray after sorting: ";
	for (int i = 0; i < 10; i++) {
		int temp;
		for (int j = 10 - 2; j >= 1; j--) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}

		}
	}

for (int i = 0; i < 10; i++) {
	cout << a[i] << " ";
}
cout << endl;
}